#include <stdio.h>
int main()
{
    char a[100];
    int frquency[26];
    scanf("%s", a);

    for (int i = 0; i < 26; i++)
        frquency[i] = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        int index = a[i] - 97;
        frquency[index] = frquency[index] + 1;
    }

    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (frquency[i] >= 1)
        {
            count++;
        }
    }

    if (count % 2 == 0)
    {
        printf("CHAT WITH HER!\n");
    }
    else
    {
        printf("IGNORE HIM!\n");
    }
}