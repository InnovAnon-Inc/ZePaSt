#ifndef _MEAN_H_
#define _MEAN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

#include <zepast.h>

typedef struct {
   size_t sum;
   /*size_t cnt;*/
   double res;
} mean_t;

void init_mean (void *restrict mean, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow)) ;
void update_mean (void *restrict mean, unigram_t val, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow)) ;
void finish_mean (void *restrict mean, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _MEAN_H_ */