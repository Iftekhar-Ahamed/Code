#include <stdio.h>
int main()
{
    int test_case, rem, i;
    long long int n;
    scanf("%d", &test_case);

    for (i = 0; i < test_case; i++)
    {
        scanf("%lld", &n);
        if (n == 0)
        {
            printf("%lld", n);
        }

        while (n > 0)
        {
            rem = n % 10;
            printf("%d ", rem);
            n = n / 10;
        }

        printf("\n");
    }

    return 0;
}