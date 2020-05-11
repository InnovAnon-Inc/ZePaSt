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
#ifndef NDEBUG
      uint_fast16_t act0;
      unsigned short act1;
      int act2;
      size_t act3;
      size_t act4;
      size_t act5;
#endif
      size_t act;
      exp = sqrt ((double) n);

#ifndef NDEBUG
      act0 = isqrt ((uint_fast64_t) n);
      act1 = isqrt_orig ((unsigned long) n);
      act2 = isqrt_orig0 ((int) n);
      act3 = isqrt_orig1 (n);
      act4 = isqrt_orig2 (n);
      act5 = isqrt_orig3 (n);
      printf ("n:%d\n", (int) n);
      printf ("act0:%d\n", (int) act0);
      printf ("act1:%d\n", (int) act1);
      printf ("act2:%d\n", (int) act2);
      printf ("act3:%d\n", (int) act3);
      printf ("act4:%d\n", (int) act4);
      printf ("act5:%d\n", (int) act5);
      puts ("");
#endif

      act = isqrt_size_t (n);
      error_check (act != (size_t) exp) {
         printf ("n:%d\nact:%d\nexp:%g\n", (int) n, (int) act, exp);
         return EXIT_FAILURE;
      }
   }
   return EXIT_SUCCESS;
}
