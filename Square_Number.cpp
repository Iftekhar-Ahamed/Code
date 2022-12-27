#include <stdio.h>
#include <math.h>

int main()
{
    int T, swap;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int num;
        scanf("%d", &num);
        double num2 = num;
        double square = sqrt(num2);
        int x = square;

        if (square == x)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }

        printf("\n");
    }
    return 0;
}