#include <stdio.h>
int myfunc(char a[])
{
    int ln = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {

        printf("%c", a[i]);
        ln = ln + 1;
    }
    return ln;
}
int main()
{
    char a[101];
    scanf("%s", &a);
    int ln = myfunc(a);
    printf("%d", ln);
    return 0;
}