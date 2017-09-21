#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <zepast.h>

__attribute__ ((leaf, nonnull (1, 3), nothrow, warn_unused_result))
void zepast (
   stat_cbs_t cbs[], size_t ncb,
   unigram_t vals[], size_t nval) {
   size_t vali, cbi;

   for (cbi = 0; cbi != ncb; cbi++)
      cbs[i].init (cbs[i].res);

   /* TODO parallelize? */
   for (vali = 0; vali != nval; vali++)
      for (cbi = 0; cbi != ncb; cbi++)
         cbs[i].update (cbs[i].res, vals[vali]);

   for (cbi = 0; cbi != ncb; cbi++)
      cbs[i].finish (cbs[i].res);
}