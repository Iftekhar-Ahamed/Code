#include <stdio.h>
int main()
{
    int totalTestCase;
    scanf("%d", &totalTestCase);
    getchar();
    for (int test = 1; test <= totalTestCase; test++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n; i++)
        {
            int x = a[i];
            for (int j = i + 1; j < n; j++)
            {
                x = x ^ a[j];
            }
            if (x == a[i - 1])
            {
                printf("%d\n", x);
                break;
            }
        }
    }
    return 0;
}