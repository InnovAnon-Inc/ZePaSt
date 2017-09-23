#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <math.h>

#include <variance.h>

__attribute__ ((leaf, nonnull (1), nothrow))
void init_variance (void *restrict _dest, size_t nval) {
   variance_t *restrict dest = (variance_t *restrict) _dest;
   dest->sum = 0;
   if (nval >= 30) dest->df  = nval - 1;
   else            dest->df  = nval;
   /*dest->cnt = 0;*/
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_variance (void *restrict _dest, unigram_t val, size_t nval) {
   variance_t *restrict dest = (variance_t *restrict) _dest;
   TODO (check overflow X2)
   double dev = dest->ct - val;
   dest->sum += dev * dev;
}

/* if the ct were an integer,
 * then we could use int sqrt() here */
__attribute__ ((leaf, nonnull (1), nothrow))
void finish_variance (void *restrict _dest, size_t nval) {
   variance_t *restrict dest = (variance_t *restrict) _dest;
   dest->res = sqrt (dest->sum) / (double) (dest->df);
}

__attribute__ ((nonnull (1, 2), nothrow))
void ez_variance (
   variance_t *restrict variance,
   unigram_t const vals[], size_t nval) {
   stat_t s;
   s.init   = init_variance;
   s.update = update_variance;
   s.finish = finish_variance;
   s.stat   = variance;
   ez_stat (&s, vals, nval);
}
