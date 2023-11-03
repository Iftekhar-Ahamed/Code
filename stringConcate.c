#include <stdio.h>
int length(char ch[])
{
    int len = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
int main()
{
    char a[10], b[5];
    scanf("%s%s", a, b);
    printf("%s + %s\n", a, b);

    int lena = length(a), lenb = length(b);

    a[lena] = ' ';

    for (int i = lena + 1, j = 0; j <= lenb; i++, j++)
    {
        a[i] = b[j];
    }
    lena = length(a);

    printf("%s %d", a, lena);
}