
#include <bits/stdc++.h>
#define endl '\n'
#define yes "YES"
#define no "NO"
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
int main()
{

    int test;
    cin >> test;

    while (test--)
    {
        string str;
        cin >> str;
        int i, j, flag = 0;
        int len = str.size();

        for (i = 0; i < len - 1; i++)
        {
            if (str[i] != str[i + 1])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            cout << no << endl;

        else
        {
            int flag2 = 0, flagA = 1;

            if (len % 2 == 0)
            {
                cout << yes << endl;
            }

            else
            {

                for (i = 0; i < len / 2 - 1; i++)
                {
                    if (str[i] != str[i + 1])
                    {
                        flagA++;
                    }
                }

                for (i = 0, j = (len / 2) + 1; i < len / 2, j < len; i++, j++)
                {
                    if (str[i] != str[j])
                    {
                        flag2++;
                    }
                }
                if (flag2 == 0 && flagA == 1)
                    cout << no << endl;
                else if (flag2 == 0 && flagA >= 2)
                    cout << yes << endl;
                else if (flag2 != 0)
                    cout << yes << endl;
            }
        }
    }

    return 0;
}
