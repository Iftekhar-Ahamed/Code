#include <stdio.h>
int main()
{
    char a[1000008];
    scanf("%s", a);
    int sum = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        sum = sum + (a[i] - 48);

        // printf("Char -> a[%d] = %c Ascii %d\n", i, a[i], a[i]);
    }
    printf("%d\n", sum);
}