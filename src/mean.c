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
void init_mean (void *restrict _dest) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   init_sum (&(dest->sum));
   dest->cnt = 0;
#ifndef NDEBUG
   printf ("dest->sum:%d\n", (int) (dest->sum)); fflush (stdout);
#endif
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_mean (void *restrict _dest, unigram_t val) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   TODO (check overflow)
#ifndef NDEBUG
   printf ("dest->sum:%d\n", (int) (dest->sum)); fflush (stdout);
   printf ("dest->val:%d\n", (int) val); fflush (stdout);
#endif
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
   update_sum (&(dest->sum), val);
	#pragma GCC diagnostic pop
   dest->cnt ++;
#ifndef NDEBUG
   printf ("dest->sum:%d\n", (int) (dest->sum)); fflush (stdout);
#endif
   /*dest->cnt++;*/
}

__attribute__ ((leaf, nonnull (1), nothrow))
void finish_mean (void *restrict _dest) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   finish_sum (&(dest->sum));
   dest->res = (double) (dest->sum) / (double) (dest->cnt);
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
