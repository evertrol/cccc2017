/* 
 * Program to calculate and print the first N terms of the Fibonacci sequence
 */

#include <stdio.h>
#include <stdlib.h>
#include "fibo.h"
#define N 100


int main()
{
		for (int i = -10; i <= N; i++) {
				printf("F%d = %lld\n", i, fibonacci(i));
		}

		return EXIT_SUCCESS;
}
