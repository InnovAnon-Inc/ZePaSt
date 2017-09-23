#ifndef _ISQRT_H_
#define _ISQRT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <sys/types.h>

#include <glitter.h>

#include <stat.h>

uint_fast16_t isqrt (uint_fast64_t a)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

size_t isqrt_size_t (size_t a)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _ISQRT_H_ */