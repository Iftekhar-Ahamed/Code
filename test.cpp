#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define read freopen("input1.txt", "r", stdin)
#define write freopen("out1.txt", "w", stdout)
int main()
{
    //read, write;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        ll n, k;
        cin >> n;
        cin >> s;
        ll ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (i - 2 >= 0 and s[i] == s[i - 2])
                continue;
            else
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
