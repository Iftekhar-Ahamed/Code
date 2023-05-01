#include <stdio.h>
int main()
{
    int test_case;
    scanf("%d", &test_case);
    for (int ca = 1; ca <= test_case; ca++)
    {
        // ইনপুট নিব
        int length;
        scanf("%d", &length);
        char s[length];
        getchar();
        scanf("%s", &s);

        // আমি প্রোসেসিং করব ঃ
        int trace[length];
        for (int i = 0; i < length; i++)
        {
            trace[i] = -1;
        }

        for (int i = 0; i < length; i++)
        {
            if (s[i] == s[0])
            {
                trace[i] = 0;
            }
        }

        for (int i = 1; i < length; i++)
        {
            if (trace[i] == -1)
            {
                int bosabo;
                if (trace[i - 1] == 0)
                {
                    bosabo = 1;
                }
                else
                {
                    bosabo = 0;
                }

                for (int j = i; j < length; j++)
                {
                    if (s[j] == s[i])
                    {
                        trace[j] = bosabo;
                    }
                }
            }
        }
        int flag = 1;
        for (int i = 1; i < length; i++)
        {
            if (trace[i] == trace[i - 1])
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}