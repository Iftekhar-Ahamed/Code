#include <stdio.h>
#include <stdbool.h>
char makeSmall(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
    }
    return ch;
}
int main()
{
    char a[100], b[100];
    scanf("%s%s", a, b);

    int i = 0;
    bool firstStringSmall = false, secondStringSmall = false, equal = false;

    while (a[i] != '\0' && b[i] != '\0')
    {
        a[i] = makeSmall(a[i]);
        b[i] = makeSmall(b[i]);

        if (a[i] < b[i])
        {
            firstStringSmall = true;
            break;
        }
        else if (a[i] > b[i])
        {
            secondStringSmall = true;
            break;
        }
        else
        {
            equal = true;
        }
        i++;
    }

    if (firstStringSmall == true)
    {
        printf("-1\n");
    }
    else if (secondStringSmall)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}