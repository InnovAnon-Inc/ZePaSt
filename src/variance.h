#ifndef _VARIANCE_H_
#define _VARIANCE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

#include <stat.h>

typedef struct {
   double ct; /* central tendency */
   double sum; /* TODO use kahan's summation algo for floats */
   double res;
   size_t df;
} variance_t;

void init_variance (void *restrict variance)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void update_variance (void *restrict variance, unigram_t val)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void finish_variance (void *restrict variance)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void ez_variance (
   variance_t *restrict variance,
   unigram_t const vals[], size_t nval)
__attribute__ ((nonnull (1, 2), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _VARIANCE_H_ */