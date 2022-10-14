#include <stdio.h>
int main()
{
    int n, L, a;
    scanf("%d%d%d", &n, &L, &a);

    if (n == 0)
    {
        printf("%d\n", L / a);
    }
    else
    {
        int t[n], l[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &t[i], &l[i]);
        }
        int ans = (t[0] / a) + ((L - (t[n - 1] + l[n - 1])) / a);

        for (int i = 0; i < n - 1; i++)
        {
            int diff = t[i + 1] - (t[i] + l[i]);

            ans = ans + (diff / a);
        }
        printf("%d\n", ans);
    }
}