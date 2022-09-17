#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5, inf = 1e9 + 7;
vector<pair<char, ll>> g[N];
string ans = "";
bool Visit[N], possible[N];
vector<ll> path;
ll n;
bool f = true;

void dfs(ll node, ll c, vector<ll> &dis)
{
    if (node == n && dis[n] == c - 1)
    {
        f = false;
        return;
    }
    else if (dis[n] < c)
    {
        return;
    }
    Visit[node] = true;
    for (auto [ch, child] : g[node])
    {
        if (!Visit[child] && dis[child] == c && f)
        {
            path.push_back(child);
            ans.push_back(ch);
            dfs(child, c + 1, dis);
            if (f)
            {
                path.pop_back();
                ans.pop_back();
            }
        }
    }
}
void bfs(vector<ll> &dis)
{
    priority_queue<tuple<ll, ll>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        cost *= (-1);

        if (dis[node] < cost)
        {
            continue;
        }

        dis[node] = cost;

        for (auto [ch, child] : g[node])
        {
            if (dis[child] >= cost + 1)
            {
                dis[child] = cost + 1;
                pq.push({-(cost + 1), child});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll m;
    cin >> n >> m;
    ll a, b;
    char ch;
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> ch;
        g[a].push_back({ch, b});
        g[b].push_back({ch, a});
    }
    for (ll i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }

    vector<ll> dis(n + 1, inf);
    bfs(dis);
    dfs(1, 1, dis);

    cout << ans.size() << '\n';
    cout << 1 << " ";
    for (auto i : path)
    {
        cout << i << " ";
    }

    cout << '\n'
         << ans << '\n';
}