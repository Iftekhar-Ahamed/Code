#include <bits/stdc++.h>

// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse,-fgcse-lm")
// #pragma GCC optimize("-ftree-pre,-ftree-vrp")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#define s second
#define f first
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) (int)a.size()
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define bk back

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (int i = 1; i < a.size(); i++)
        cin >> a[i];
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    return out;
}

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p)
{
    cin >> p.f >> p.s;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p)
{
    cout << p.f << ' ' << p.s;
    return out;
}

const int MOD = 1e9 + 7; // 998244353;
const int N = 2e5 + 5;
const ll INF = 1e18;
const int M = 3e3 + 5;
const double EPS = 1e-6;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rnd64(chrono::system_clock::now().time_since_epoch().count());
ll rndm(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rnd64);
}

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = a;
    if (a == 0)
    {
        cout << min(1ll, b + c + d) << '\n';
        return;
    }
    if (b == c)
        ans += b * 2 + min(a + 1, d);
    else
        ans += min(b, c) * 2 + min({a + 1, d + max(b, c) - min(b, c)});
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //    frp("");
    int t = 1, r = 1;
    cin >> t;
    while (t--)
    {
        // cout << r++ << '\n';
        solve();
    }
    return 0;
}
