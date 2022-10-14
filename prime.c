#include <stdio.h>
#include <math.h>
int main()
{
    int n, limit;
    scanf("%d", &n);
    limit = sqrt(n);
    int ans = 1;
    for (int i = 2; i <= limit; i++)
    {
        if (n % i == 0)
        {
            ans = 0;
            break;
        }
    }

    if (ans == 1)
    {
        printf("%d is prime\n", n);
    }
    else
    {
        printf("%d is not prime\n", n);
    }
    main();
}
/*
#include <stdio.h>
#define write freopen("0_output.txt", "w", stdout);
int main()
{
    write;

    for (long long n = 3; n <= 200; n += 2)
    {

        if (n == 2 || n == 3 || n == 5)
        {
            printf("%d Prime Number\n", n);
        }
        else
        {
            if (n % 2 == 0)
            {
                printf("%d Non-Prime Number \n", n);
            }
            else
            {
                if (n % 3 == 0 || n % 5 == 0 || n == 1)
                {
                    printf("%d Non-Prime Number\n", n);
                }
                else
                {
                    printf("%d Prime number\n", n);
                }
            }
        }
    }
    return 0;
}
* /