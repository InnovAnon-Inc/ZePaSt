#ifndef _STAT_OFF_DIFF_H_
#define _STAT_OFF_DIFF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

#include <stat_off.h>

unigram_t diff_stat_off (unigram_t left, unigram_t right)
__attribute__ ((const, warn_unused_result)) ;

void ez_stat_off_diff (
   stat_off_t *restrict sum,
   unigram_t const vals[], size_t nval, size_t offset)
__attribute__ ((nonnull (1, 2), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SUM_H_ */