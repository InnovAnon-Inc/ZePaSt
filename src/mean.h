#ifndef _MEAN_H_
#define _MEAN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <zepast.h>

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