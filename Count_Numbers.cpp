#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    getchar();
    for (int c = 1; c <= test; c++)
    {
        string s;
        getline(cin, s);

        int ans = 0;
        int f = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (f == 1)
                {
                    ans++;
                }
                f = 0;
            }
            else
            {
                f = 1;
            }
        }
        if (f == 1)
            ans++;
        cout << ans << endl;
    }
}