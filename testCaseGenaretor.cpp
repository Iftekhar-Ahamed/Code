#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nn '\n'
int main()
{
    freopen("input3.txt", "w", stdout);
    ll n = rand() % 1000000;
    cout << n << nn;
    for (ll i = 0; i < n; i++)
    {
        cout << rand() % 1000000 << " ";
    }
    cout << nn;
    ll q = rand() % 1000000;
    cout << q << nn;
    for (ll i = 0; i < q; i++)
    {
        ll a = rand() % (n + 1), b = rand() % (n + 1);
        if (a > b)
            swap(a, b);
        a = max(a, 1LL);
        b = max(b, 1LL);
        cout << a << " " << b << " " << rand() % 1000000000 << nn;
    }
}