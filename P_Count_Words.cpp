#include <stdio.h>
#include <string.h>
int main()

{

    char str[1000001];

    gets(str);
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')
        {
            str[i] = ' ';
        }
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        while (str[i] != '\0' && str[i] == ' ')
        {
            i++;
        }
        int f = 0;
        while (str[i] != '\0' && str[i] != ' ')
        {
            f = 1;
            i++;
        }
        count = count + f;
    }
    printf("%d", count);
    return 0;
}