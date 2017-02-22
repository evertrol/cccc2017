#include <stdio.h>
#include <stdlib.h>
#define N 1000


int main()
{
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += i;
    }
    printf("%d\n", sum);

    return EXIT_SUCCESS;
}
