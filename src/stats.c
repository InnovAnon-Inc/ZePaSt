#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stats.h>

__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result))
void init_mean (stat_t *restrict dest) {
   dest->n = 0;
}

__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result))
void update_mean (stat_t *restrict dest, unigram_t val) {
   TODO (check overflow)
   dest->n += val;
}

__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result))
void finish_mean (stat_t *restrict dest) {
   dest->d = (double) (dest->n) / ?;
}