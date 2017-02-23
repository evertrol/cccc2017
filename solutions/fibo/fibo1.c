#include <stdio.h>
#include <stdlib.h>
#define N 50


/* 
 * Calculate and print the first N terms of the Fibonacci sequence
 */
int main()
{
		int F0 = 0;
		int F1 = 1;
		// First two terms are defined, and can't really be computed
		// Simply print them
		printf("F0  = %12d\n", F0);
		printf("F1  = %12d\n", F1);
		for (int i = 2; i <= N; ++i) {
				int F = F1 + F0;
				printf("F%-2d = %12d\n", i, F);
				F0 = F1;
				F1 = F;
		}

		return EXIT_SUCCESS;
}
