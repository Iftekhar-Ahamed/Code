#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        n--;
        ll p = sqrt(n);
        ll ans = p * p;
        cout << p << endl;
    }
}
