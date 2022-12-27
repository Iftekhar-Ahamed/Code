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
    while (ct--)
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;
set<pair<ll, ll>> backedge;
void dfs(ll node, ll parent, vector<vector<ll>> &g, vector<bool> &visit)
{
    visit[node] = true;
    for (auto child : g[node])
    {
        if (child != parent)
        {
            if (visit[child])
            {
                ll x = max(node, child), y = min(node, child);
                backedge.insert({x, y});
            }
            else
            {
                dfs(child, node, g, visit);
            }
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<bool> visit(n + 1, false);
    vector<ll> disconnect;
    for (ll i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            disconnect.push_back(i);
            dfs(i, -1, v, visit);
        }
    }
    cout << backedge.size() << nn;
    ll k = 1;
    for (auto [x, y] : backedge)
    {
        cout << x << " " << y << " " << disconnect[0] << " " << disconnect[k++] << nn;
    }
}

int main()
{
    FIO;
    // read;
    // write;

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