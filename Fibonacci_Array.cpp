#include <stdio.h>
int main()
{
    long long int fibonacci[61];

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= 60; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    int test;
    scanf("%d", &test);

    while (test--)
    {
        int index;
        scanf("%d", &index);
        printf("Fib(%d) = %lld\n", index, fibonacci[index]);
    }

    return 0;
}