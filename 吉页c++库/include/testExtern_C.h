/* file: test_extern_c.h */

#ifndef __TEST_EXTERN_C_H__
#define __TEST_EXTERN_C_H__

#ifdef __cplusplus
extern "C" {
#endif
	/*
	   11.* this is a test function, which calculate
	   12.* the multiply of a and b.
	   13.*/

	extern int ThisIsTest(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
