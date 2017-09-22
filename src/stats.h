#ifndef _STATS_H_
#define _STATS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <zepast.h>

void init_mean (void *restrict mean, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result)) ;
void update_mean (void *restrict mean, unigram_t val, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result)) ;
void finish_mean (void *restrict mean, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _STATS_H_ */