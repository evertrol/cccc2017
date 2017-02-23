/* 
 * Program to calculate and print the first N terms of the Fibonacci sequence
 */

#include <stdio.h>
#include <stdlib.h>
#define N 50


int main()
{
		long long f0 = 0;
		long long  f1 = 1;
		printf("F0 = %lld\n", f0);
		printf("F1 = %lld\n", f1);
		for (int i = -10; i <= N; i++) {
				long long f = f0 + f1;
				printf("F%d = %lld\n", i, f);
				f0 = f1;
				f1 = f;
		}

		return EXIT_SUCCESS;
}
