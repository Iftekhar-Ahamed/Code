#include <stdio.h>

int ok(int n)
{

    int rem;

    while (n > 0)
    {
        rem = n % 10;
        if (rem != 4 && rem != 7)
        {
            return 0;
        }

        n = n / 10;
    }
    return 1;
}
int main()
{

    long long int a, b, c = 0;

    scanf("%lld%lld", &a, &b);

    for (int i = a; i <= b; i++)
    {
        if (ok(i) == 1)
        {
            c++;
            printf("%d ", i);
        }
    }
    if (c == 0)
    {
        printf("-1");
    }

    return 0;
}