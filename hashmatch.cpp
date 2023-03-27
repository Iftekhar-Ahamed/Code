/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;

#define FIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test   \
    ll ct;     \
    cin >> ct; \
    for (ll i = 1; i <= ct; i++)
#define testcase cout << "Case " << i << ": ";
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 2091573227;
const ll base = 1949313259;
const ll mXs = 1e6 + 1;

ll power[mXs], inv[mXs];

ll bigMod(ll x, ll y, ll m)
{
    if (y == 0)
    {
        return 0;
    }
    else if (y == 1)
    {
        return x;
    }

    if (y % 2 == 0)
    {
        ll t = bigMod(x, y / 2, m) % m;
        return (t * t) % m;
    }

    ll t = bigMod(x, y - 1, m) % m;
    return (t * x) % m;
}

void pecal()
{
    ll v = bigMod(base, mod - 2, mod);
    power[0] = 1, inv[0] = 1;
    for (ll i = 1; i < mXs; i++)
    {
        power[i] = (power[i - 1] * base) % mod;
        inv[i] = (inv[i - 1] * v) % mod;
    }
}

void calculateHashValue(string &s, vector<ll> &v)
{
    v[0] = 0;
    for (ll i = 1; i <= s.size(); i++)
    {
        v[i] = ((s[i - 1] * power[i - 1]) + v[i - 1]) % mod;
    }
}
ll rangeHash(ll l, ll r, vector<ll> &hash)
{
    ll ans = hash[r] - hash[l];

    ans = (ans * inv[l]) % mod;

    if (ans < 0)
    {
        ans += mod;
    }
    return ans;
}

bool ok(ll prefixHash, ll ln, vector<ll> &hash, ll n)
{

    for (ll i = 0; i + ln <= n; i += ln)
    {
        ll t = rangeHash(i, i + ln, hash);

        if (prefixHash != t)
        {
            return false;
        }
    }

    if (n % ln)
    {
        ln = n % ln;
        ll x = rangeHash(0, ln, hash);
        ll y = rangeHash(n - ln, n, hash);

        if (x != y)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;
}
void solve()
{
    string s;
    cin >> s;
    vector<ll> hashValue(s.size() + 1);
    calculateHashValue(s, hashValue);

    ll n = s.size();

    for (ll ln = 1; ln <= n; ln++)
    {
        ll val = rangeHash(0, ln, hashValue);
        if (ok(val, ln, hashValue, n))
        {
            cout << ln << " ";
        }
    }
}

int main()
{
    FIO;
    // read;
    // write;

    // testcase
    solve();

    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
/* Final check before submit :
1. array size or integer overflow,like uninitialised 0 index.
2. Think twice,code once.check all possible counter test case.
3. Be careful about corner case! n=1?k=1? something about 0?
4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?
5. if got WA than remember that you are missing something common.
*** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;
*/
/* IF WA???
1. corner case! n=1?k=1? something about 0?
2. check code(avoid stupid mistake)
3. read the statement again(if there any missing point???)
4. check the idea(check all possible counter test case again!!!)
5. be calm,don't be panic!!!.(***this problem not going to decide your future***)
6. don't waste too much time. move to next problem
*/