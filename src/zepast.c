#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <zepast.h>

__attribute__ ((leaf, nonnull (1, 3), nothrow))
void zepast (
   zepast_t z[],     size_t nzepast,
   unigram_t vals[], size_t nval) {
   size_t zi, zsi, vi;
   /*
   for (zi = 0; zi != nzepast; zi++)
      for (zsi = 0; zsi != z[zi]->nstats; zsi++)
         z[zi].statss[zsi].init (z[zi].statss[zsi].stats, nval);
   for (vi = 0; vi != nval; vi++)
      for (zi = 0; zi != nzepast; zi++)
         for (zsi = 0; zsi != z[zi]->nstats; zsi++)
            z[zi].statss[zsi].update (z[zi].statss[zsi].stats, vals[vi], nval);
   for (zi = 0; zi != nzepast; zi++)
      for (zsi = 0; zsi != z[zi]->nstats; zsi++)
         z[zi].statss[zsi].finish (z[zi].statss[zsi].stats, nval);
   */
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
   for (zi = 0; zi != nzepast; zi++) {
      for (zsi = 0; zsi != z[zi].nstats; zsi++)
         z[zi].statss[zsi].init (z[zi].statss[zsi].stats, nval);
      for (vi = 0; vi != nval; vi++)
         for (zsi = 0; zsi != z[zi].nstats; zsi++)
            z[zi].statss[zsi].update (z[zi].statss[zsi].stats, vals[vi], nval);
      for (zsi = 0; zsi != z[zi].nstats; zsi++)
         z[zi].statss[zsi].finish (z[zi].statss[zsi].stats, nval);
	#pragma GCC diagnostic pop
   }
}