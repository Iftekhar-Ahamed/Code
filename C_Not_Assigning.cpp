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
const ll mXs = 1e6;
bool isPrime[mXs];
vector<ll> primeList;
void cal_prime()
{
    for (ll i = 2; i < mXs; i++)
    {
        if (isPrime[i] == false)
        {
            primeList.push_back(i);
            for (ll j = i + i; j < mXs; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
}
void dfs(ll p, ll nd, ll c, map<pair<ll, ll>, ll> &mp, vector<vector<ll>> &v)
{
    for (auto child : v[nd])
    {
        if (child != p)
        {
            if (c == 2)
            {
                mp[{nd, child}] = 5;
                mp[{child, nd}] = 5;
                dfs(nd, child, 5, mp, v);
            }
            else
            {
                mp[{nd, child}] = 2;
                mp[{child, nd}] = 2;
                dfs(nd, child, 2, mp, v);
            }
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n + 1);
    map<pair<ll, ll>, ll> mp;
    vector<pair<ll, ll>> edge;
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        edge.push_back({x, y});
    }
    for (ll i = 1; i <= n; i++)
    {
        if (v[i].size() > 2)
        {
            cout << -1 << nn;
            return;
        }
    }
    ll f = 2;
    for (auto i : v[1])
    {
        mp[{1, i}] = f;
        mp[{i, 1}] = f;
        dfs(1, i, f, mp, v);
        f = 5;
    }

    for (auto i : edge)
    {
        cout << mp[i] << " ";
    }
    cout << nn;
}

int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(NULL), ios_base::sync_with_stdio(false);
#endif
    // read;
    // write;
    test
    {
        // testcase
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