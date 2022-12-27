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
void dfs(ll node, vector<vector<ll>> &G, vector<bool> &visit, ll &c, set<pair<ll, ll>> &path)
{
    visit[node] = true;
    c++;
    for (auto child : G[node])
    {
        path.insert({max(child, node), min(child, node)});
        if (visit[child] == false)
        {
            dfs(child, G, visit, c, path);
        }
    }
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<tuple<ll, ll, ll>> goverment(k);
    for (auto &[a, b, c] : goverment)
    {
        cin >> a;
        b = c = 0;
    }
    vector<vector<ll>> G(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll ans = 0;
    ll totalCountedPath = 0, totalCounedNode = 0;
    vector<bool> visit(n + 1, false);
    for (auto &[key, node, pathHave] : goverment)
    {
        set<pair<ll, ll>> path;
        dfs(key, G, visit, node, path);
        pathHave = path.size();
        totalCountedPath += pathHave;
        totalCounedNode += node;
    }
    ll extraNode = n - totalCounedNode, extraPath = m - totalCountedPath;
    ll mx = 0, pevneed = 0;
    for (auto [key, node, pathHave] : goverment)
    {
        ll need = (((node - 1) * node / 2) - pathHave);

        node += extraNode;
        pathHave += extraPath;

        ll need1 = (((node - 1) * node / 2) - pathHave);

        if (mx < need1)
        {
            mx = need1;
            ans += pevneed;
            pevneed = need;
        }
        else
        {
            ans += need;
        }
    }
    ans += mx;

    cout << ans << nn;
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