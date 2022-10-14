#include <stdio.h>

int main()
{

    long long int a;

    for (int i = 0;; i++)
    {
        scanf("%lld", &a);

        if (a == 1999)
        {
            printf("Correct\n");
            return 0;
        }
        else
        {
            printf("Wrong\n");
        }
    }

    return 0;
}