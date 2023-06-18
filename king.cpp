#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int nowr = 0, nowc = 0, targetr, targetc;
        scanf("%d%d", &targetr, &targetc);
        int ans = 0;
        int f = 0;

        while (nowr != targetr || nowc != targetc)
        {
            if (f != 1 && nowr != targetr)
            {
                f = 1;
                if (nowr < targetr)
                {
                    nowr++;
                }
                else
                {
                    nowr--;
                }
            }
            else if (f != 2 && nowc != targetc)
            {
                f = 2;
                if (nowc < targetc)
                {
                    nowc++;
                }
                else
                {
                    nowc--;
                }
            }
            else
            {
                f = 0;
            }
            ans++;
        }
        int ans1 = 0;
        f = nowc = nowr = 0;

        while (nowr != targetr || nowc != targetc)
        {
            if (f != 2 && nowc != targetc)
            {
                f = 2;
                if (nowc < targetc)
                {
                    nowc++;
                }
                else
                {
                    nowc--;
                }
            }
            else if (f != 1 && nowr != targetr)
            {
                f = 1;
                if (nowr < targetr)
                {
                    nowr++;
                }
                else
                {
                    nowr--;
                }
            }
            else
            {
                f = 0;
            }
            ans1++;
        }
        if (ans > ans1)
            ans = ans1;
        printf("%d\n", ans);
    }
}