// including all header files
#include <bits/stdc++.h>

//<for policy based data structure>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//</for policy based data structure>

using namespace std;

//<shortcut macros>
#define ll long long int
#define dll long double
#define ull unsigned long long int

// most used numbers
const ll MM = 1e6 + 3;
const ll MD = 1e9 + 7;
const double PI = acos(-1.0);

// direction array
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

// runs test cases
#define test() \
    int TT;    \
    cin >> TT; \
    for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS " "
#define NN "\n"
#define pyes cout << "YES\n"
#define pno cout << "NO\n"

// template declarations simplified
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define All(x) x.begin(), x.end()

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1
//</shortcut macros>

// ordered set
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

const ll N = 1e5 + 7;
ll t[N * 4];
ll a[N + 1];

void build(ll n, ll l, ll r)
{
    if (l == r)
    {
        t[n] = a[l];
        return;
    }
    ll mid = (l + r) / 2, ln = 2 * n, rn = 2 * n + 1;
    build(ln, l, mid);
    build(rn, mid + 1, r);
    t[n] = __gcd(t[ln], t[rn]);
}

ll query(ll n, ll l, ll r, ll lin, ll rin)
{
    if (l > rin || r < lin)
        return 0;
    if (l >= lin && r <= rin)
    {
        return t[n];
    }
    ll mid = (l + r) / 2, ln = 2 * n, rn = 2 * n + 1;
    return __gcd(query(ln, l, mid, lin, rin), query(rn, mid + 1, r, lin, rin));
}

vector<ll> optimize_seive()
{
    ll N = 1e6 + 1;
    vector<ll> primes;
    vector<bool> vis(N, 0);
    primes.emplace_back(2);
    for (ll i = 3; i < N; i += 2)
    {
        if (vis[i] == 0)
        {
            primes.emplace_back(i);
            for (ll j = i * i; j < N; j += 2 * i)
            {
                vis[j] = 1;
            }
        }
    }
    return primes;
}

vector<ll> pr;
vector<ll> hasPrime[MM];

void precalc()
{
    pr = optimize_seive();
    for (ll i = 2; i < MM; i++)
    {
        ll x = i;
        for (int j = 0; j < pr.size() and pr[j] <= sqrt(x); j++)
        {
            if (x % pr[j] == 0)
            {
                hasPrime[i].push_back(pr[j]);
                while (x % pr[j] == 0)
                    x /= pr[j];
            }
        }
        if (x > 1)
            hasPrime[i].push_back(x);
    }
}

void answer()
{
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    set<ll> cur;
    map<ll, int> mp;
    for (auto p : hasPrime[a[0]])
    {
        cur.insert(p);
        mp[p] = 0;
    }
    ll l = 0;
    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
        if (cur.size() == k)
        {
            ll gc = query(1, 0, n - 1, l, i - 1);
            if (gc == 1)
            {
                ans = max(ans, (i - l));
            }
        }
        for (auto p : hasPrime[a[i]])
        {
            cur.insert(p);
            mp[p] = i;
        }
        if (cur.size() == k)
        {

            ll gc = query(1, 0, n - 1, l, i);
            if (gc == 1)
            {
                ans = max(ans, (i - l + 1));
            }
        }
        while (cur.size() > k and l < i)
        {
            for (auto p : hasPrime[a[l]])
            {
                if (mp[p] <= l)
                    cur.erase(p);
            }
            l++;
        }
    }
    if (cur.size() == k)
    {
        ll i = n - 1;
        ll gc = query(1, 0, n - 1, l, i);
        if (gc == 1)
        {
            ans = max(ans, (i - l + 1));
        }
    }
    cout << ans << NN;
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    fast();
    // inout();
    precalc();
    //     for no test case
    // answer();

    //     when test cases exist
    test()
    {
        // cout<<"Case "<<TK<<":"<<NN;
        pcs;
        answer();
    }

    return 0;
}