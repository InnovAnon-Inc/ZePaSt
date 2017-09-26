#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#define NDEBUG 1

#ifndef NDEBUG
#include <stdio.h>
#endif

#include <stat_off_diff.h>

__attribute__ ((const, warn_unused_result))
unigram_t diff_stat_off (unigram_t left, unigram_t right) {
   return right - left;
}

__attribute__ ((nonnull (1, 2), nothrow))
void ez_stat_off_diff (
   stat_t *restrict stat,
   unigram_t const vals[], size_t nval, size_t offset) {
   stat_off_t s;
   /*s.init   = init_stat_off_diff;
   s.update = update_stat_off_diff;
   s.finish = finish_stat_off_diff;*/
   s.stat   = stat;
   s.diff   = diff_stat_off;
   ez_stat_off (&s, vals, nval);
}
