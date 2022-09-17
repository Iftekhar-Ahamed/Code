#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mXs (ll)(3 * (1e5))

#define nn "\n"

ll powerType[mXs];
ll invType[mXs];
ll hashValue[mXs];

string s;
ll base = 1949313259, mod = 2091573227, inv, n;

void precal()
{
    inv = 51894831;
    powerType[0] = invType[0] = 1;

    for (ll i = 1; i < mXs; i++)
    {
        powerType[i] = (powerType[i - 1] * base) % mod;
        invType[i] = (invType[i - 1] * inv) % mod;
    }
}
void calculateHashValue()
{
    hashValue[0] = 0;
    for (ll i = 1; i <= n + n; i++)
    {
        hashValue[i] = (hashValue[i - 1] + ((s[i - 1] * powerType[i - 1]) % mod)) % mod;
    }
}
ll rangeHash(ll i, ll j)
{
    ll th1 = hashValue[j] - hashValue[i] + mod;
    th1 = (th1 * invType[i]) % mod;
    return th1;
}
bool binarySearchOnHash(pair<ll, ll> &a, pair<ll, ll> &b)
{
    ll x1 = a.first;
    ll y1 = a.second;
    ll x2 = b.first;
    ll y2 = b.second;
    ll left = x2;
    ll right = y2;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (rangeHash(x1, x1 + abs(mid - x2)) != rangeHash(x2, mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (s[x1 + abs(left - x2) - 1] > s[left - 1])
    {
        return 0;
    }
    else if (s[x1 + abs(left - x2) - 1] < s[left - 1])
    {
        return 1;
    }
    else
    {
        if (x1 < x2)
            return 1;
        else
            return 0;
    }
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);

    cin >> s;
    n = s.size();
    s += s;
    precal();
    vector<pair<ll, ll>> v(n);

    for (ll i = 0; i < n; i++)
    {
        v[i] = {i, i + n - 1};
    }

    calculateHashValue();

    sort(v.begin(), v.end(), binarySearchOnHash);

    ll pos;

    for (ll i = 0; i < n; i++)
    {
        if (v[i].first == 0 && v[i].second == n - 1)
        {
            pos = i + 1;
            break;
        }
    }
    cout << pos << nn;
    for (ll i = 0; i < n; i++)
    {
        cout << s[v[i].second];
    }
    cout << nn;

    return 0;
}
