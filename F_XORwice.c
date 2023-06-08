#include <stdio.h>
int main()
{
    int totalTestCase;
    scanf("%d", &totalTestCase);
    getchar();
    for (int test = 1; test <= totalTestCase; test++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int total = a | b;
        int overlaf = a & b;
        printf("%d\n", total - overlaf);
    }
    return 0;
}