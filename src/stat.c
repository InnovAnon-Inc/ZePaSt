#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stat.h>

__attribute__ ((leaf, nonnull (1), nothrow))
void init_stat (stat_t *restrict s, size_t nval) {
   s->init (s->stat, nval);
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_stat (
   stat_t *restrict s,
   unigram_t val, size_t nval) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
   s->update (s->stat, val, nval);
	#pragma GCC diagnostic pop
}

/* naive implementation */
/*__attribute__ ((leaf, nonnull (1, 2), nothrow))
void updates_stat_naive (
   stat_t *restrict s,
   unigram_t val[], size_t nval) {
   size_t vi;
   for (vi = 0; vi != nval; vi++)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
      update_stat (s, val[vi], nval);
	#pragma GCC diagnostic pop
}*/

/* assuming your alternative implementation for multiple updates
 * can do better than multiplying the Big-Theta by n,
 * where n is the number of updates (i.e., nval) */
/*__attribute__ ((leaf, nonnull (1, 2), nothrow))
void updates_stat (
   stat_t *restrict s,
   unigram_t vals[], size_t nval) {
   s->updates (s->stats, vals, nval);
}*/

__attribute__ ((leaf, nonnull (1), nothrow))
void finish_stat (stat_t *restrict s, size_t nval) {
   s->finish (s->stat, nval);
}

__attribute__ ((nonnull (1, 2), nothrow))
void ez_stat (
   stat_t *restrict s,
   unigram_t const vals[], size_t nval) {
   size_t vi;
   init_stat (s, nval);
   for (vi = 0; vi != nval; vi++)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
      update_stat (s, vals[vi], nval);
	#pragma GCC diagnostic pop
   finish_stat (s, nval);
}

TODO (random sampling for sublinear time)
TODO (dynamic programming parallel version of ez_stat())
