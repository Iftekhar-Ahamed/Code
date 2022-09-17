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
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;
ll bfs(ll &si, ll &sj, char des, vector<vector<char>> &g, ll n)
{
    vector<vector<ll>> dis(n, vector<ll>(n, INF));
    dis[si][sj] = 0;
    queue<pair<ll, ll>> q;
    q.push({si, sj});
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll xx = r + dRow[i], yy = c + dCol[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && dis[xx][yy] == INF && g[xx][yy] != '#')
            {
                if (g[xx][yy] == '.' || g[xx][yy] < des)
                {
                    dis[xx][yy] = dis[r][c] + 1;
                    q.push({xx, yy});
                }
                else if (g[xx][yy] == des)
                {
                    si = xx, sj = yy;
                    return dis[r][c] + 1;
                }
            }
        }
    }
    return -1;
}
void solve()
{
    ll n, food = 0, si = 0, sj = 0;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
                si = i, sj = j;
            if (g[i][j] >= 'B' && g[i][j] <= 'Z')
                food++;
        }
    }
    char des = 'B';
    ll cost = 0;

    for (ll i = 0; i < food; i++)
    {
        ll t = bfs(si, sj, des, g, n);
        if (t == -1)
        {
            cout << "Impossible" << nn;
            return;
        }
        cost += t;
        des++;
    }
    cout << cost << nn;
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