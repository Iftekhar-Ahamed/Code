#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    double c = (a*1.0)/(b*1.0);
    printf("%.3lf",c);
    return 0;
}