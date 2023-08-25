#include <bits/stdc++.h>
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vst vector<str>
#define nn '\n'
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)

#define pb push_back
#define ppb pop_back
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define sp " "
#define pi 3.1415926535897932384626433832795

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
ll mod = 1e9 + 7;
using namespace std;

void result()
{
    ll n, k;
    cin >> n >> k;
    ll lo = 1, hi = INT_MAX;
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll x = mid - mid / n;
        if (x >= k)
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << nn;
}
int main()
{
    optimize();
    ll t;
    cin >> t;

    while (t--)
    {
        result();
    }
    //    result();

    return 0;
}
