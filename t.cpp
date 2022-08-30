#include <stdio.h>
int main()
{
    double a = 5.0 / 3.0, b = 1.67;
    int suduDosomikErAgerValue_a = a, suduDosomikErAgerValue_b = b;//eikhane amra double er dosomik er ager number ta nicci sudu example (a = 1.67 -> b = a -> b = 1) 

    if (suduDosomikErAgerValue_a == suduDosomikErAgerValue_b)
    {
        a = a - suduDosomikErAgerValue_a; // a er value aikhane cilo 1.666 jeta theke 1 minus koreci tai 0.666 hbe
        a = a * 100;
        suduDosomikErAgerValue_a = a;
        a = a - suduDosomikErAgerValue_a;// a er value aikhane cilo 66.666 jeta theke 66 minus koreci tai 0.666 hbe
        a = a * 10;
        int t = a;
        if(t>=5){
            suduDosomikErAgerValue_a++;
        } 

        b = b - suduDosomikErAgerValue_b;
        b = b * 100;
        suduDosomikErAgerValue_b = b;
        b = b - suduDosomikErAgerValue_b;

        if(suduDosomikErAgerValue_a == suduDosomikErAgerValue_b){
            printf("ok\n");
        }else{
            printf("Not ok\n");
        }

    }else{
        printf("Not ok\n");
    }
    return 0;
}