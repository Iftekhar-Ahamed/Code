#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    map<ll, ll> a;
    map<ll, ll> b;
    while (n--)
    {
        ll val;
        cin >> val;
        a[val]++;
    }
    while (m--)
    {
        ll val;
        cin >> val;
        b[val]++;
    }
    ll sum = 0;
    /*for (auto it : a)
    {
        cout << it.first << " " << it.second << endl;
    }*/
    for (auto it = a.begin(); it != a.end(); it++)
    {
        sum += (it->second * b[it->first]);
    }
    cout << sum << endl;
    return 0;
}