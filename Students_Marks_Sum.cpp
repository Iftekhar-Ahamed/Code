#include <stdio.h>
int main()
{
    int n, i, mark[100], sum = 0;
    char gen = 'x';
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &mark[i]);
    }

    // getchar();

    scanf("\n%c", &gen);
    // printf(" yy %c\n", gen);

    if (gen == 'g')
    {

        for (i = 0; i < n; i++)
        {
            // 0,1,2,3,4,5,6.....
            if (i % 2 == 1)
            {
                sum = sum + mark[i];
            }
        }
        printf("%d\n", sum);
    }
    else if (gen == 'b')
    {

        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                sum = sum + mark[i];
            }
        }
        printf("%d\n", sum);
    }
}   