#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stats.h>

__attribute__ ((leaf, nonnull (1, 3), nothrow))
void stats (
   stats_t s[],      size_t nstats,
   unigram_t vals[], size_t nval) {
   size_t si, vi;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
   /* presumably si loop can be parallelized */
   for (si = 0; si != nstats; si++)
      s[si].init (s[si].stats, nval);
   /* vi loop cannot necessarily be parallelized,
    * because diffs() */
   for (vi = 0; vi != nval; vi++)
      for (si = 0; si != nstats; si++)
         s[si].update (s[si].stats, vals[vi], nval);
   for (si = 0; si != nstats; si++)
      s[si].finish (s[si].stats, nval);
	#pragma GCC diagnostic pop
}

TODO (stats2() fully parallelize-able)
