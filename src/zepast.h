#ifndef _ZEPAST_H_
#define _ZEPAST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <sys/types.h>

#include <glitter.h>

#include <stats.h>

/*typedef struct {
   stats_t stats;
   void (*cb) ();
} stats_clj_t;*/

typedef __attribute__ ((nonnull (1, 3)))
void all_statss_t (
   zepast_t z[], size_t nzepast,
   unigram_t vals[], size_t nval) ;

/* modular collections of stats */
typedef struct {
   /*stats_clj_t *restrict statss;*/
   stats_t *restrict statss;
   size_t nstats;
   all_statss_t all_statss;
   TODO (mask output)
} zepast_t;

void zepast (
   zepast_t z[],     size_t nzepast,
   unigram_t vals[], size_t nval)
__attribute__ ((leaf, nonnull (1, 3), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _ZEPAST_H_ */