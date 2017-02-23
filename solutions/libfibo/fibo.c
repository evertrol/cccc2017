#include "fibo.h"
#define N 100
#define MAXTERM 92

/*
 * fibonacci(int nterm)
 * - Calculates and returns the nterm-th value of the Fibonacci sequence
 *  
 * - The value is calculated by evaluating the Fibonacci sequence:
 *   Fn = Fn-1 + Fn-2
 *    with F0 = 0 and F1 = 1
 * - Argument nterm should be between 0 and …
 *    - the sequence is not defined for negative terms
 *    - at input values above … overflow occurs
 */
long long fibonacci(int nterm)
{
		if (nterm < 0 || nterm > MAXTERM) {
				return -1;
		}
		
		if (nterm == 0) {
				return 0;
		} else if (nterm == 1) {
				return 1;
		}
		long long F0 = 0;
		long long F1 = 1;
		long long F = F1 + F0;
		for (int i = 2; i <= nterm; ++i) {
				F = F1 + F0;
				F0 = F1;
				F1 = F;
		}
		
        return F;
}
