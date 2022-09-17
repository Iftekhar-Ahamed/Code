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

map<ll, vector<ll>> mp;
map<ll, bool> vis;
map<ll, ll> type;

ll bfs(ll node)
{
    vis[node] = true;
    type[node] = 1;
    ll lykan = 0, vampire = 1, i;
    queue<ll> trace;
    trace.push(node);

    while (!trace.empty())
    {
        node = trace.front();
        trace.pop();
        for (i = 0; i < mp[node].size(); i++)
        {
            if (!vis[mp[node][i]])
            {
                trace.push(mp[node][i]);
                vis[mp[node][i]] = true;
                if (type[node] == 1)
                {
                    type[mp[node][i]] = 0;
                    lykan++;
                }
                else
                {
                    type[mp[node][i]] = 1;
                    vampire++;
                }
            }
        }
    }
    return max(lykan, vampire);
}

void solve()
{
    mp.clear();
    vis.clear();
    type.clear();
    ll n, x, y, ans;
    cin >> n;
    ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (!vis[it->first])
            ans += bfs(it->first);
    }
    cout << ans << endl;
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