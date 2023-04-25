#include <stdio.h>
int main()
{
    int n, p;
    scanf("%d%d", &n, &p);

    int ara[n][n], ans[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ara[i][j]);
            ans[i][j] = ara[i][j];
        }
    }
    if (p == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        p--;
        for (int power = 1; power <= p; power++)
        {
            int t[n][n];

            for (int i = 0; i < n; i++)
            {
                int temp[n][n];

                for (int c = 0; c < n; c++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        temp[c][j] = ans[i][c] * ara[c][j];
                    }
                }

                for (int c = 0; c < n; c++)
                {
                    int sum = 0;
                    for (int r = 0; r < n; r++)
                    {
                        sum += temp[r][c];
                    }

                    t[i][c] = sum;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ans[i][j] = t[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}