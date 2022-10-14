#include <stdio.h>
int main()
{
    int N, x, i, j;
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &x);
        int f = 0;

        for (j = 2; j < x; j++)
        {
            if (x % j == 0)
            {
                f = 1;
                printf("%d nao eh primo\n", x);
                break;
            }
        }
        if (f == 0)
        {
            printf("%d eh primo\n", x);
        }
    }

    return 0;
}
