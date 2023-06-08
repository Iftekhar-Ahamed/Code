#include <stdio.h>
int main()
{
    int totalTestCase;
    scanf("%d", &totalTestCase);
    for (int test = 1; test <= totalTestCase; test++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int ok = 1;
        for (int i = 0; i < n && ok == 1; i++)
        {
            for (int j = i + 1; j < n && ok == 1; j++)
            {
                if (a[j] == a[i])
                {
                    ok = 0;
                }
            }
        }
        if (ok == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}