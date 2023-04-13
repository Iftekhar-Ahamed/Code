#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        char a[102];
        scanf("%s", &a);
        int ln;
        for (ln = 0; 1; ln++)
        {
            if (a[ln] == '\0')
                break;
        }
        int num = a[ln - 1] - '0';
        if (num % 2 == 0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }
}