#include <stdio.h>

void reverse(int *begin, int *end)
{
    while (end > begin)
    {
        int temp = *end;
        *end = *begin;
        *begin = temp;
        begin++;
        end--;
    }
}

int main(void)
{
    int size;
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d ", &a[i]);
    }
    for (int *p = a; p != a + size; p++)
    {
        printf("%d ", *p);
    }
    reverse(a, a + (size - 1));
    printf("\n");
    for (int *p = a; p != a + size; p++)
    {
        printf("%d ", *p);
    }
}
