#include <stdio.h>
int main()
{
    double rad;
    double pi = 3.141592653;
    scanf("%lf", &rad);

    double area = pi * rad * rad;

    printf("%.9lf\n", area);

    return 0;
}