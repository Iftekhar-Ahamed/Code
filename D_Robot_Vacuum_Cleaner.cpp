#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nn "\n"
bool cmp(tuple<ll, ll, string> &a, tuple<ll, ll, string> &b)
{
    auto [x, y, z] = a;
    auto [xx, yy, zz] = b;

    ll s1, s2, h1, h2;
    s1 = count(z.begin(), z.end(), 's');
    h1 = count(z.begin(), z.end(), 'h');
    s2 = count(zz.begin(), zz.end(), 's');
    h2 = count(zz.begin(), zz.end(), 'h');

    s1 *= h2;
    s2 *= h1;

    if (s1 > s2)
    {
        return true;
    }
    return false;

    // return x > xx;

    // if (x > xx)
    // {
    //     return true;
    // }
    // else
    // {
    //     if (y < yy)
    //     {
    //         return true;
    //     }
    //     else
    //     {

    //         return z > zz;
    //     }
    // }
    // return true;
}

void f(string &s, tuple<ll, ll, string> &t)
{
    ll x = 0, y = 0;
    for (auto i : s)
    {
        if (i == 's')
            x++;
        else
            y++;
    }
    t = {x, y, s};
}
ll calc(string &s)
{
    ll ans = 0, h = 0;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 's')
            ans += h;
        else
            h++;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    ll ans = 0;

    string s;
    vector<tuple<ll, ll, string>> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> s;
        f(s, v[i]);
    }

    sort(v.begin(), v.end(), cmp);
    ll y = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        auto [a, b, xx] = v[i];
        ans += (y * a);
        ans += calc(xx);
        y += b;
    }
    cout << ans << nn;

    return 0;
}
