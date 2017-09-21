#ifndef _STATS_H_
#define _STATS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <zepast.h>

typedef union {
   unigram_t n;
   double    d;
} stat_t;

void init_mean (stat_t *restrict mean)
__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result)) ;
void update_mean (stat_t *restrict mean, unigram_t val)
__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result)) ;
void finish_mean (stat_t *restrict mean)
__attribute__ ((leaf, nonnull (1), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _STATS_H_ */