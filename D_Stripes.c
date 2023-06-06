#include <stdio.h>
int main()
{
    int totalTestCase;
    scanf("%d", &totalTestCase);
    getchar();
    for (int test = 1; test <= totalTestCase; test++)
    {
        getchar();
        char ara[8][8];
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                scanf("%c", &ara[i][j]);
            }
            getchar();
        }
        int ok = 0;
        for (int i = 0; i < 8 && ok == 0; i++)
        {
            int c = 0;
            for (int j = 0; j < 8; j++)
            {
                if (ara[i][j] == 'R')
                    c++;
            }
            if (c == 8)
            {
                ok = 1;
            }
        }
        if (ok == 1)
        {
            printf("R\n");
        }
        else
        {
            printf("B\n");
        }
    }
    return 0;
}