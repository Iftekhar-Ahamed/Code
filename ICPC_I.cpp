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
vector<pair<ll, ll>> ans;
void dfs(ll node, ll k, vector<bool> &visit, vector<vector<ll>> &g, vector<ll> &value, vector<tuple<ll, ll, ll>> &count)
{
    visit[node] = true;
    auto [a, b, c] = count[node];

    for (auto &child : g[node])
    {
        if (!visit[child])
        {
            count[child] = {0, value[child], 1};

            dfs(child, k, visit, g, value, count);

            auto [x, y, z] = count[child];

            b += y;
            c += z;
        }
    }
    a = b - (c * k);
    count[node] = {a, b, c};
}
void dfsPrintAnswer(ll node, ll k, vector<vector<ll>> &g, vector<ll> &value, vector<tuple<ll, ll, ll>> &count, vector<bool> &visit)
{
    visit[node] = true;

    vector<pair<ll, ll>> v;

    for (auto child : g[node])
    {
        if (!visit[child])
        {
            auto [a, b, c] = count[child];
            v.push_back({a, child});
        }
    }

    if (v.size() == 0)
    {
        if (value[node] >= k)
        {
            ans.push_back({-abs(k - value[node]), node});
            value[node] = k;
        }
        else
        {
            ans.push_back({abs(k - value[node]), node});
        }
    }
    else
    {
        sort(v.begin(), v.end());
        ans.push_back({-value[node], node});
        for (ll i = v.size() - 1; i >= 0; i--)
        {
            dfsPrintAnswer(v[i].second, k, g, value, count, visit);
            if (i == 0)
            {
                ans.push_back({k, node});
            }
            else
            {
                ans.push_back({0, node});
            }
        }
    }
}
void solve()
{
    ans.clear();
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> g(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<ll> value(n + 1, 0);
    ll start = 1;

    for (ll i = 1; i <= n; i++)
    {
        cin >> value[i];
    }

    vector<tuple<ll, ll, ll>> count(n + 1);
    vector<bool> visit(n + 1, false);

    count[start] = {0, value[start], 1};
    dfs(start, k, visit, g, value, count);

    visit.clear();
    visit.resize(n + 1, false);

    dfsPrintAnswer(start, k, g, value, count, visit);

    for (auto i : ans)
    {
        cout << i.second << " " << i.first << nn;
    }
}

int main()
{
    FIO;
    // read;
    //  write;
    ll i = 1;
    test
    {
        cout << "Case " << i++ << ": YES" << nn;
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