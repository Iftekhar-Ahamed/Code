#include <stdio.h>
#include <math.h>
int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n;
        scanf("%d", &n);
        int count = 0;

        while (n != 0)
        {
            count += (n % 2 == 0 ? 0 : 1);

            n /= 2;
        }
        /*int ans = 0;
        for (int i = 1; count--; i *= 2)
        {
            ans += i;
        }*/
        int ans = 0;
        for (int i = 0; i < count; i++)
        {
            ans += pow(2, i);
        }
        printf("%d\n", ans);
    }
}