#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <zepast.h>

__attribute__ ((leaf, nonnull (1, 3), nothrow))
void stats (
   stats_t s[],      size_t nstats,
   unigram_t vals[], size_t nval) {
   size_t si, vi;
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
}

TODO (stats2() fully parallelize-able)

__attribute__ ((leaf, nonnull (1, 3), nothrow))
void zepast (
   zepast_t z[],     size_t nzepast,
   unigram_t vals[], size_t nval) {
   size_t zi, zsi, vi;
   /*
   for (zi = 0; zi != nzepast; zi++)
      for (zsi = 0; zsi != z[zi]->nstats; zsi++)
         z[zi][zsi].init (z[zi][zsi].stats, nval);
   for (vali = 0; vali != nval; vali++)
      for (zi = 0; zi != nzepast; zi++)
         for (zsi = 0; zsi != z[zi]->nstats; zsi++)
            z[zi][zsi].update (z[zi][zsi].stats, vals[vali], nval);
   for (zi = 0; zi != nzepast; zi++)
      for (zsi = 0; zsi != z[zi]->nstats; zsi++)
         z[zi][zsi].finish (z[zi][zsi].stats, nval);
   */
   for (zi = 0; zi != nzepast; zi++) {
      for (zsi = 0; zsi != z[zi]->nstats; zsi++)
         z[zi][zsi].init (z[zi][zsi].stats, nval);
      for (vali = 0; vali != nval; vali++)
         for (zsi = 0; zsi != z[zi]->nstats; zsi++)
            z[zi][zsi].update (z[zi][zsi].stats, vals[vali], nval);
      for (zsi = 0; zsi != z[zi]->nstats; zsi++)
         z[zi][zsi].finish (z[zi][zsi].stats, nval);
   }
}