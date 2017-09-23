#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#define NDEBUG 1

#ifndef NDEBUG
#include <stdio.h>
#endif

#include <isqrt.h>

/* https://stackoverflow.com/questions/4930307/fastest-way-to-get-the-integer-part-of-sqrtn */
__attribute__ ((const, leaf, nothrow, warn_unused_result))
uint_fast16_t isqrt (uint_fast64_t a) {
   uint_fast64_t rem = 0;
   uint_fast32_t root = 0;
   int i;

   for (i = 0; i < 16; i++) {
      root <<= 1;
      rem <<= 2;
      rem += a >> 30;
      a <<= 2;

      if (root < rem) {
          root++;
          rem -= root;
          root++;
      }
   }

   return (uint_fast16_t) (root >> 1);
}

__attribute__ ((const, leaf, nothrow, warn_unused_result))
size_t isqrt_size_t (size_t a) {
#ifndef TEST
   uint_fast16_t ret = isqrt ((uint_fast64_t) a);
   return (size_t) ret;
#else
   size_t rem = 0;
   size_t root = 0;
   size_t i;

   for (i = 0; i < sizeof (size_t) * 8; i++) {
      root <<= 1;
      rem <<= 2;
      rem += a >> ((sizeof (size_t) * 8 - 1) * 2);
      a <<= 2;

      if (root < rem) {
          root++;
          rem -= root;
          root++;
      }
   }

   return (size_t) (root >> 1);
#endif
}
