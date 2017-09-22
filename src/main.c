#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <zepast.h>


__attribute__ ((nothrow, warn_unused_result))
int main (void) {
   zepast_t z;
   stats_t ss[1];
   mean_t mean;
   unigram_t vals[]
   z.statss = ss;
   z.nstats = ARRSZ (ss);

   ss[0].init   = init_mean;
   ss[0].update = update_mean;
   ss[0].finish = finish_mean;
   ss[0].stats  = &mean;

   zepast (&z, (size_t) 1, vals, ARRSZ (vals));

   (void) printf ("mean:%d,%g\n", (int) (mean.sum), mean.res);
   return EXIT_SUCCESS;
}
