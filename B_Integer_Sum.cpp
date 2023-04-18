#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int num, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        sum = sum + num;
    }
    printf("%d\n", sum);
    return 0;
}