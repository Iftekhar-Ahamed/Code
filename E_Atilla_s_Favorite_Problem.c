#include <stdio.h>
int main()
{
    int totalTestCase;
    scanf("%d", &totalTestCase);
    getchar();
    for (int test = 1; test <= totalTestCase; test++)
    {
        char a[101];
        int n;
        scanf("%d", &n);
        getchar();
        scanf("%s", a);
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = (a[i] - 97) + 1;
            if (pos > mx)
                mx = pos;
        }
        printf("%d\n", mx);
    }
    return 0;
}