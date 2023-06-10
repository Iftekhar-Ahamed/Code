#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{

    ll n;
    cin >> n;
    vector<ll> a, b;
    for (ll i = 0; i < 2 * n; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 == 0)
        {
            a.push_back(i + 1);
        }
        else
        {
            b.push_back(i + 1);
        }
    }
    if (a.size() % 2 == 0 && b.size() % 2 == 0)
    {

        if (a.empty())
        {
            b.pop_back();
            b.pop_back();
        }
        else
        {
            a.pop_back();
            a.pop_back();
        }
    }
    else if (a.size() % 2 && b.size() % 2)
    {
        a.pop_back();
        b.pop_back();
    }
    else if (a.size() % 2)
    {
        a.pop_back();
        a.pop_back();
    }
    else
    {
        b.pop_back();
        b.pop_back();
    }
    for (ll i = 1; i < a.size(); i += 2)
    {
        cout << a[i] << " " << a[i - 1] << endl;
    }
    for (ll i = 1; i < b.size(); i += 2)
    {
        cout << b[i] << " " << b[i - 1] << endl;
    }
    // cout << endl;
}

int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        solve();
    }
}