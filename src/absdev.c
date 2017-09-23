#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <math.h>

#include <absdev.h>

__attribute__ ((leaf, nonnull (1), nothrow))
void init_absdev (void *restrict _dest, size_t nval) {
   absdev_t *restrict dest = (absdev_t *restrict) _dest;
   dest->sum = 0;
   if (nval >= 30) dest->df  = nval - 1;
   else            dest->df  = nval;
   /*dest->cnt = 0;*/
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_absdev (void *restrict _dest, unigram_t val, size_t nval) {
   absdev_t *restrict dest = (absdev_t *restrict) _dest;
   TODO (check overflow)
   dest->sum += abs (dest->ct - val);
}

/* if the ct were an integer,
 * then we could use int sqrt() here */
__attribute__ ((leaf, nonnull (1), nothrow))
void finish_absdev (void *restrict _dest, size_t nval) {
   absdev_t *restrict dest = (absdev_t *restrict) _dest;
   dest->res = dest->sum / (double) (dest->df);
}

__attribute__ ((nonnull (1, 2), nothrow))
void ez_absdev (
   absdev_t *restrict absdev,
   unigram_t const vals[], size_t nval) {
   stat_t s;
   s.init   = init_absdev;
   s.update = update_absdev;
   s.finish = finish_absdev;
   s.stat   = absdev;
   ez_stat (&s, vals, nval);
}
