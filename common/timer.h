/*
 * timer.h
 *
 *  Created on: Apr 8, 2016
 *      Author: zhi
 */

#ifndef TIMER_H_
#define TIMER_H_

#if defined __GNUC__
	#define INLINE	 inline __attribute__((always_inline))
	#define NOINLINE __attribute__((noinline))

	#if defined(AMD64) || defined(__GNUC__)
		#include <sys/types.h>
      	#include <stdint.h>
	#else
		typedef long long			 int64_t;
		typedef unsigned long long uint64_t;
	#endif
#elif defined _MSC_VER
	#define __MSVC__
	#define INLINE	 __forceinline
	#define NOINLINE __declspec(noinline)
	typedef  long long			 int64_t;
	typedef unsigned  long long uint64_t;
#else
	#error not supported system
#endif

/*
 * RDTSC is used to counter the number of CPU cycles
 */
#ifdef __GNUC__
	#if defined(__i386__)

	static INLINE uint64_t rdtsc(void)
	{
	    uint64_t rax,rdx;
	    uint32_t aux;

	    __asm__ volatile( "rdtscp\n" : "=a" (rax), "=d" (rdx), "=c" (aux) : : );

	    return (rdx << 32) + rax;
	}
	#elif defined(__x86_64__)

	static INLINE uint64_t rdtsc(void)
	{
	    uint64_t rax,rdx;
	    uint32_t aux;

	    __asm__ volatile( "rdtscp\n" : "=a" (rax), "=d" (rdx), "=c" (aux) : : );

	    return (rdx << 32) + rax;
	}

	#elif defined(__powerpc__)

	static INLINE uint64_t rdtsc(void)
	{
		register uint64_t result=0;
		unsigned long int upper, lower,tmp;
		__asm__ volatile(
				"0:                  \n"
				"\tmftbu   %0           \n"
				"\tmftb    %1           \n"
				"\tmftbu   %2           \n"
				"\tcmpw    %2,%0        \n"
				"\tbne     0b         \n"
				: "=r"(upper),"=r"(lower),"=r"(tmp)
		);
		result = upper;
		result = result<<32;
		result = result|lower;

		return(result);
	}

	#endif
#elif defined __ICC__

	static INLINE uint64_t rdtsc(void) {
	    uint64_t rax,rdx;
	    uint32_t aux;

	    __asm__ volatile( "rdtscp\n" : "=a" (rax), "=d" (rdx), "=c" (aux) : : );

	    return (rdx << 32) + rax;
	}

#elif defined __MSVC__

	static INLINE uint64_t rdtsc(void) {
		__asm { rdtsc };
	}

#else
	#error not supported compiler
#endif


#endif /* TIMER_H_ */
