#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f = 0;
bool vis[1000];
void findValid(ll nde, ll parent, vector<vector<ll>> &v)
{
    vis[nde] = true;
    // for (int i = 0; i < v[nde].size(); i++)
    for (auto child : v[nde])
    {
        // ll child = v[nde][i];
        if (child == parent)
        {
            continue;
        }
        else
        {
            if (vis[child])
            {
                f = 1;
            }
            else
            {
                findValid(child, nde, v);
            }
        }
    }
}
int main()
{
    int n;
    cout << "ENTER NUMBER OF NODE :" << endl;
    cin >> n;
    vector<vector<ll>> tree(n + 1);
    cout << "ENTER NUMBER OF PATH :" << endl;
    ll path;
    cin >> path;
    for (ll i = 0; i < path; i++)
    {
        ll x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    findValid(1, -1, tree);
    if (f == 0)
    {
        cout << "TREE" << endl;
    }
    else
    {
        cout << "GRAPH" << endl;
    }

    return 0;
}