#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#include <mean.h>

typedef struct {
   size_t sum;
   /*size_t cnt;*/
   double res;
} mean_t;

__attribute__ ((leaf, nonnull (1), nothrow))
void init_mean (void *restrict _dest, size_t nval) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   dest->sum = 0;
   /*dest->cnt = 0;*/
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_mean (void *restrict _dest, unigram_t val, size_t nval) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   TODO (check overflow)
   dest->sum += val;
   /*dest->cnt++;*/
}

__attribute__ ((leaf, nonnull (1), nothrow))
void finish_mean (void *restrict _dest, size_t nval) {
   mean_t *restrict dest = (mean_t *restrict) _dest;
   dest->res = (double) (dest->sum) / (double) (/*dest->cnt*/nval);
}