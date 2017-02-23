#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100000
#define M 5000

int main()
{
    long long sum = 0;
	for (long long j = 1; j <= M; j++) {
			sum = 0;
			for (long long i = 1; i <= N; ++i) {
					sum += log(i);
			}
	}

    return EXIT_SUCCESS;
}
