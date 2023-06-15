#include <stdio.h>
int main()
{
    int N, X, M;
    scanf("%d%d%d", &X, &N, &M);
    if (X + M >= N)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}