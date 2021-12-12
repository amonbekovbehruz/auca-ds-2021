#include <stdio.h>

#define M 5
#define N 3

void printArray(int *start, int *end)
{
    while (start != end)
    {
        printf(" %d", *start++);
    }
}

int main(void)
{
    int a[M];
    int b[N];

    for (int i = 0; i < M; i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", b + i);
    }

    printArray(a, a + M);
    printArray(b, b + N);
}