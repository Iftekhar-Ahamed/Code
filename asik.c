#include <stdio.h>
#include <string.h>
int asikBuildLength(char a[])
{
    int length = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        length = length + 1;
    }
    return length;
}
int main()
{
    char a[10], b[100];

    scanf("%s", a);

    int length = asikBuildLength(a);

    printf("%s %d\n", a, length);

    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    printf("%s %d\n", a, length);
    return 0;
}