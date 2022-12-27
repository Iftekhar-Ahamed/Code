#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[21], x = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            x = __gcd(x, a[i]);
        }
        // printf("*%d ", x);
        if (x == 1)
        {
            printf("0\n");
        }
        else if (__gcd(x, n) == 1)
        {
            printf("1\n");
        }
        else if (__gcd(x, n - 1) == 1)
        {
            printf("2\n");
        }
        else
        {
            printf("3\n");
        }
    }
}
