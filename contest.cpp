#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

const int N = 3e5 + 5;
vector<int> edge[N];
int depth[N], p[25][N], sub[N];
int n;

void dfs(int src, int par, int far)
{
    p[0][src] = par;
    depth[src] = far;
    sub[src] = 1;

    for (auto v : edge[src])
    {
        if (v == par)
            continue;

        dfs(v, src, far + 1);
        sub[src] += sub[v];
    }
}

ll lca(ll u, ll v)
{
    if (depth[v] > depth[u])
    {
        swap(v, u);
    }

    ll ss = 25;

    for (ll i = ss - 1; i >= 0; i--)
    {
        if (p[i][u] != -1)
        {
            if (depth[p[i][u]] >= depth[v])
            {
                u = p[i][u];
            }
        }
    }
    for (ll i = ss - 1; i >= 0; i--)
    {
        if (p[i][u] != -1)
        {
            if (p[i][u] != p[i][v])
            {
                u = p[i][u];
                v = p[i][v];
            }
        }
    }
    if (u == v)
    {
        return u;
    }
    return p[0][u];
}

int kth_parent(int a, int b)
{
    ll N = log2(n) + 1;
    for (ll i = N - 1; i >= 0; i--)
    {
        ll t = p[i][a];
        if ((1LL << i) <= b && t != -1)
        {
            b -= (1LL << i);
            a = t;
        }
    }

    return a;
}
int main()
{
    int t, q;
    int u, v;

    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        for (int i = 1; i <= n; i++)
        {
            edge[i].clear();
            sub[i] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;

            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        dfs(1, -1, 0);

        ll ss = log2(n) + 1;

        for (ll i = 1; i < ss; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (p[i - 1][j] != -1)
                {
                    p[i][j] = p[i - 1][p[i - 1][j]];
                }
            }
        }

        while (q--)
        {
            cin >> u >> v;

            int node = lca(u, v);

            int ud = depth[node] - depth[u];
            int vd = depth[node] - depth[v];
            int len = ud + vd;
            int mid = len / 2;

            if (len & 1)
            {
                cout << 0 << endl;
                continue;
            }

            if (ud == vd)
            {
                int a = kth_parent(u, ud - 1);
                int b = kth_parent(v, vd - 1);

                cout << n - sub[a] - sub[b] << endl;
            }

            else
            {
                if (vd < ud)
                {
                    swap(u, v);
                    swap(vd, ud);
                }

                int a = kth_parent(v, mid);
                int b = kth_parent(v, mid - 1);

                cout << sub[a] - sub[b] << endl;
            }
        }
    }
}