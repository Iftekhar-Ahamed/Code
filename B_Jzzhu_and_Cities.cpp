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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, x;
        cin >> u >> v >> x;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    vector<ll> dis(n + 1, INF), dis1(n + 1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [c, node] = pq.top();
        pq.pop();

        if (dis[node] <= c)
            continue;

        for (auto [child, d] : g[node])
        {
            if (dis[child] > c + d)
            {
                dis[child] = c + d;
                pq.push({dis[child], child});
            }
        }
    }

    set<pair<ll, ll>> train;
    for (ll i = 0; i < k; i++)
    {
        ll v, u, x;
        v = 1;
        cin >> u >> x;
        train.insert({u, x});
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [c, node] = pq.top();
        pq.pop();

        if (dis1[node] <= c)
            continue;

        for (auto [child, d] : g[node])
        {
            if (dis1[child] > c + d)
            {
                dis1[child] = c + d;
                pq.push({dis1[child], child});
            }
        }
    }

    ll c = 0;
    for (auto i : train)
    {
        if (dis[i.first] > dis1[i.first] && dis1[i.first] == i.second)
            c++;
    }
    cout << k - c << nn;
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