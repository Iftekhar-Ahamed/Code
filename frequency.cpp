#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int ara[n], frequency[100000];

    for (int i = 0; i < 100000; i++)
    {
        frequency[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);

        frequency[ara[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (frequency[ara[i]] != 0)
        {
            printf("Frequency of %d = %d\n", ara[i], frequency[ara[i]]);
            frequency[ara[i]] = 0;
        }
    }

    return 0;
}