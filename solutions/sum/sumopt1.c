#include <stdio.h>
#include <stdlib.h>
#define N 100000
#define M 50000000

int main()
{
    long long sum = 0;
	for (long long j = 1; j <= M; j++) {
			sum = 0;
			for (long long i = 1; i <= N; ++i) {
					sum += i;
			}
	}
    printf("%lld\n", sum);

    return EXIT_SUCCESS;
}