#include <stdio.h>
int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        int number = 0;
        char s[100000];

        scanf("%s", s);

        for (int i = 0; s[i] != '\0'; i++)
        {
            number = number + (s[i] - '0');
        }

        while (number > 9)
        {
            int sum = 0;
            while (number > 0)
            {
                sum = sum + (number % 10);
                number = number / 10;
            }
            number = sum;
        }

        if (number == 9)
        {
            printf("Case %d: YES\n", i);
        }
        else
        {
            printf("Case %d: NO\n", i);
        }
    }

    return 0;
}