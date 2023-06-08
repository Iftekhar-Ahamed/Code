#include <stdio.h>
int main()
{
    int totalTestCase;
    scanf("%d", &totalTestCase);
    for (int test = 1; test <= totalTestCase; test++)
    {
        int r1, r2, r3;
        scanf("%d%d%d", &r1, &r2, &r3);
        if (r1 + r2 == r3 || r1 + r3 == r2 || r2 + r3 == r1)
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