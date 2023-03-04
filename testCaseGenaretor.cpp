#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nn '\n'
int main()
{
    freopen("input4.txt", "w", stdout);
    cout << 100 << nn;
    for (ll j = 0; j < 100; j++)
    {
        ll n = rand() % 100;
        cout << n << nn;
        for (ll i = 0; i < n; i++)
        {
            ll r = rand() % 25;
            cout << (char)(97 + r);
        }
        cout << nn;
    }
}