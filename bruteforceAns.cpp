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

#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test                 \
    ll ct;                   \
    cin >> ct, cin.ignore(); \
    for (ll i = 1; i <= ct; i++)
#define testcase cout << "Case " << i << ": ";
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll MM = 1e6 + 3;
const ll MD = 1e9 + 7;

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

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    };
    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ll gc = a[i];
        set<ll> cur;
        for (ll j = i; j < n; j++)
        {
            gc = __gcd(a[j], gc);

            for (auto p : hasPrime[a[j]])
            {
                cur.insert(p);
            }
            if (cur.size() == k && gc == 1)
            {
                ans = max(ans, j - i + 1);
            }
            else if (cur.size() > k)
            {
                break;
            }
        }
    }
    cout << ans << nn;
}

int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(NULL), ios_base::sync_with_stdio(false);
#endif
    // read;
    // write;
    precalc();
    test
    {
        testcase
        solve();
    }
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