#ifndef _ABSDEV_H_
#define _ABSDEV_H_

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
} absdev_t;

void init_absdev (void *restrict absdev)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void update_absdev (void *restrict absdev, unigram_t val)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void finish_absdev (void *restrict absdev)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void ez_absdev (
   absdev_t *restrict absdev,
   unigram_t const vals[], size_t nval)
__attribute__ ((nonnull (1, 2), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _ABSDEV_H_ */