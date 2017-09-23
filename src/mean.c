#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#define NDEBUG 1

#ifndef NDEBUG
#include <stdio.h>
#endif

#include <mean.h>

__attribute__ ((leaf, nonnull (1), nothrow))
void init_mean (void *restrict _dest, size_t nval) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   dest->sum = 0;
#ifndef NDEBUG
   printf ("dest->sum:%d\n", (int) (dest->sum)); fflush (stdout);
#endif
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_mean (void *restrict _dest, unigram_t val, size_t nval) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   TODO (check overflow)
#ifndef NDEBUG
   printf ("dest->sum:%d\n", (int) (dest->sum)); fflush (stdout);
   printf ("dest->val:%d\n", (int) val); fflush (stdout);
#endif
   dest->sum += val;
#ifndef NDEBUG
   printf ("dest->sum:%d\n", (int) (dest->sum)); fflush (stdout);
#endif
   /*dest->cnt++;*/
}

__attribute__ ((leaf, nonnull (1), nothrow))
void finish_mean (void *restrict _dest, size_t nval) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   dest->res = (double) (dest->sum) / (double) (/*dest->cnt*/nval);
#ifndef NDEBUG
   printf ("dest->sum:%d\n", (int) (dest->sum)); fflush (stdout);
   printf ("dest->res:%g\n", dest->res); fflush (stdout);
#endif
}

__attribute__ ((nonnull (1, 2), nothrow))
void ez_mean (
   mean_t *restrict mean,
   unigram_t const vals[], size_t nval) {
   stat_t s;
   s.init   = init_mean;
   s.update = update_mean;
   s.finish = finish_mean;
   s.stat   = mean;
   ez_stat (&s, vals, nval);
}
