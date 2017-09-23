#ifndef _IVARIANCE_H_
#define _IVARIANCE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

#include <stat.h>

typedef struct {
   double res;
   size_t sum; /* TODO use kahan's summation algo for floats */
   size_t df;
   unigram_t ct; /* central tendency */
} ivariance_t;

void init_ivariance (void *restrict ivariance)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void update_ivariance (void *restrict ivariance, unigram_t val)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void finish_ivariance (void *restrict ivariance)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void ez_ivariance (
   ivariance_t *restrict ivariance,
   unigram_t const vals[], size_t nval)
__attribute__ ((nonnull (1, 2), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _IVARIANCE_H_ */