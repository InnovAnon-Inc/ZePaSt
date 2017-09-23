#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <mean.h>

__attribute__ ((nothrow, warn_unused_result))
int main (void) {
   mean_t mean;

   char const str[] = "Hello, World!";
   unigram_t vals[sizeof (str) * sizeof (char)];
   size_t vi;

   /*(void) memcpy (vals, str, sizeof (str));*/
   TODO (check overflow)
   for (vi = 0; vi != ARRSZ (vals); vi++)
      vals[vi] = (unigram_t) str[vi];

   ez_mean (&mean, vals, ARRSZ (vals));

   (void) printf ("sum:%d\n",      (int) (mean.sum));
   (void) printf ("mean:%g\n",     mean.res);

   return EXIT_SUCCESS;
}
