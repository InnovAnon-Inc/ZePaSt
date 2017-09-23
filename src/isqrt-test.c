#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#define NDEBUG 1

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <math.h>

#include <isqrt.h>

__attribute__ ((nothrow, warn_unused_result))
int main (void) {
   size_t n, maxn;
   maxn = 100;
   /*for (n = 0; n != maxn; n++) {*/
   for (n = maxn - 1; n != SIZE_MAX; n--) {
      double exp;
      size_t act;
      exp = sqrt ((double) n);
      act = isqrt_size_t (n);
      error_check (act != (size_t) exp) {
         printf ("n:%d\nact:%d\nexp:%g\n", (int) n, (int) act, exp);
         return EXIT_FAILURE;
      }
   }
   return EXIT_SUCCESS;
}
