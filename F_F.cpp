#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

using namespace std;
const ll N = 1010;
vector<ll> g[N + 1];
ll par[N + 1];
ll sub[N + 1];

ll find(ll a)
{
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void join(ll a, ll b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        par[b] = a;
        sub[a] += sub[b];
    }
}

ll go(ll node)
{
    ll sum = 1;

    for (auto x : g[node])
        sum += go(x);

    return sum;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            par[i] = i, sub[i] = 1;
            g[i].clear();
        }

        ll a, b;
        bool f = true;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;

            if (a == b)
                f = false;

            g[a].push_back(b);
            join(a, b);
        }

        for (int i = 1; i <= n; i++)
        {
            if (f)
            {
                ll sz = sub[find(i)];
                ll subsz = go(i);

                if (sz % 2)
                {
                    ll mid = (sz + 1) / 2;
                    if (mid == subsz)
                        cout << 1;
                    else
                        cout << 0;
                }
                else
                {
                    ll mid = sz / 2;
                    if (mid == subsz or mid + 1 == subsz + 1)
                        cout << 1;
                    else
                        cout << 0;
                }
            }

            else
                cout << 0;
        }

        cout << endl;
    }
}