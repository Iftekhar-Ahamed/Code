#include <stdio.h>
#define size 1000001
int main()
{
    int n, a[size];
    scanf("%d", &n);
    for (int i = 0; i < size; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] >= 1)
        {
            count++;
        }
    }
    printf("%d\n", n - count);
    return 0;
}

/*
-1 -1 -1 1 2
2
3
-1 1 2
*/