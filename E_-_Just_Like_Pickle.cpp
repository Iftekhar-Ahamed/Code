#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define endl '\n'
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

using namespace std;

ll pcount(ll n)
{
    ll x = __popcount(n);
    return x;
}

int main()
{
    fastIO;

    int t;
    ll x;

    cin >> t;

    while (t--)
    {
        cin >> x;

        x = abs(x);

        if (x == 0)
            cout << 0 << endl;
        else if (pcount(x) == 1)
            cout << 1 << endl;
        else
        {
            ll pow = log2(x);
            ll xx = (1LL << pow);
            pow++;
            pow = (1LL << pow);

            ll dif = pow - x, dif2 = x - xx;
            // cout << xx << " " << pow << endl;

            if (pcount(dif) == 1 || pcount(dif2) == 1)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }
    }
    return 0;
}
