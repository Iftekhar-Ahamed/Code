#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nn '\n'
int main()
{
    freopen("input1.txt", "w", stdout);
    cout << 100 << nn;
    for (ll j = 0; j < 100; j++)
    {
        ll n = 2000;
        cout << n << nn;
        for (ll i = 0; i < n; i++)
        {
            char ch = 'a' + (rand() % 25);
            cout << ch;
        }
        cout << nn;
    }
}