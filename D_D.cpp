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
bool cmp(pair<ll, ll> p, pair<ll, ll> p1)
{
    ll x = p.first;
    ll y = p.second;
    ll x1 = p1.first;
    ll y1 = p1.second;
    ll len = y - x;
    ll len1 = y1 - x1;
    if (len1 > len)
        return 1;
    if (len == len1 and x < x1)
        return 1;
    if (len == len1 and x == x1 and y < y1)
        return 1;
    return 0;
}
void solve()
{
    int n, m, k;
    cin >> n;
    vector<pair<ll, ll>> vp, vp1;
    map<ll, vector<ll>> mp;
    ll x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        vp.push_back({x, y});
    }
    sort(vp.begin(), vp.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        x = vp[i].first;
        y = vp[i].second;
        mp[(y - x + 1)].push_back(i);
    }
    map<ll, ll> use;
    ll ans = 0;
    for (auto [a, v] : mp)
    {
        ll sz = v.size();
        ll ls = vp[v[0]].first;
        while (use[ls] and ls <= vp[v[0]].second)
        {
            ls++;
        }
        if (ls <= vp[v[0]].second)
        {
            ans++;
            use[ls] = 1;
        }
        for (int i = 1; i < sz; i++)
        {
            ll ind = v[i];
            ll x = vp[ind].first;
            ll y = vp[ind].second;
            if (ls + 1 <= x)
                ls = x;
            while (use[ls] and ls <= y)
            {
                ls++;
            }
            if (ls <= y)
            {
                ans++;
                use[ls] = 1;
            }
        }
    }
    cout << ans << '\n';
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