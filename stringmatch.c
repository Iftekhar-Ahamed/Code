#include <stdio.h>
int main()
{
    char a[100], b[100];
    scanf("%s%s", a, b);
    for (int i = 0; a[i] != '\0'; i++)
    {
        int ok = 1, k = i;
        for (int j = 0; b[j] != '\0'; j++, k++)
        {
            if (b[j] != a[k])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {

            printf(" Matched\n");
            return 0;
        }
    }
    printf("Not Matched\n");
    return 0;
}