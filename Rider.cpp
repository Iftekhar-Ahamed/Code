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
int dRow[] = {1, +1, +2, +2, -1, -1, -2, -2};
int dCol[] = {2, -2, +1, -1, +2, -2, +1, -1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;

void solve()
{
    ll n, m, id = 0;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    queue<tuple<ll, ll, ll, ll>> pq;
    vector<pair<ll, ll>> v;
    vector<ll> rider;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> g[i][j];

            if (g[i][j] >= '0' && g[i][j] <= '9')
            {
                v.push_back({i, j});
                rider.push_back(g[i][j] - '0');
            }
        }
    }
    ll dis[rider.size()][n][m];

    for (ll id = 0; id < rider.size(); id++)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {

                dis[id][i][j] = INF;
            }
        }

        pq.push({1, v[id].first, v[id].second, rider[id]});

        dis[id][v[id].first][v[id].second] = 0;
    
        while (!pq.empty())
        {
            auto [cost, r, c, k] = pq.front();
            pq.pop();

            for (ll i = 0; i < 8; i++)
            {

                ll x = r + dRow[i], y = c + dCol[i];

                if (x < n && x >= 0 && y < m && y >= 0 && dis[id][x][y] > cost)
                {
                    dis[id][x][y] = cost;
                    if (k == 1)
                    {
                        pq.push({cost + 1, x, y, rider[id]});
                    }
                    else
                    {
                        pq.push({cost, x, y, k - 1});
                    }
                }
            }
        }
    }

    ll ans = INF;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll t = 0;
            for (ll k = 0; k < rider.size(); k++)
            {

                t += dis[k][i][j];
            }
            ans = min(ans, t);
        }
    }

    cout << (ans == INF ? -1 : ans) << nn;
}

int main()
{
    FIO;
    // read;
    // write;
    ll i = 1;
    test
    {
        cout << "Case " << i++ << ": ";
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
