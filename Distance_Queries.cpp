/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long int
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn '\n'

void dfs(lld node, lld parent, vector<vector<lld>> &g, vector<vector<lld>> &p, vector<lld> &l)
{
    p[0][node] = parent;
    for (auto i : g[node])
    {
        if (i != parent)
        {
            l[i] = l[node] + 1;
            dfs(i, node, g, p, l);
        }
    }
}
lld lca(lld a, lld b, vector<vector<lld>> &g, vector<vector<lld>> &p, vector<lld> &l)
{
    lld u = a, v = b;
    if (l[u] < l[v])
    {
        swap(u, v);
    }



    for (lld i = p.size() - 1; i >= 0; i--)
    {
        if (p[i][u] != -1 && l[p[i][u]] >= l[v])
        {
            u = p[i][u];
        }
    }

    if (u == v)
    {
        return abs(l[a] - l[b]);
    }

    for (lld i = p.size() - 1; i >= 0; i--)
    {
        if (p[i][u] != -1 && p[i][u] != p[i][v])
        {
            u = p[i][u];
            v = p[i][v];
        }
    }
    lld ca = p[0][v];

    lld v1 = l[a] - l[ca], v2 = l[b] - l[ca];

    return v1 + v2;
}
void solve()
{
    lld n, q, a, b;
    cin >> n >> q;
    lld ss = log2(n) + 1;
    vector<vector<lld>> v(n + 1), p(ss, vector<lld>(n + 1, -1));
    vector<lld> l(n + 1, 0);
    for (lld i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 1, v, p, l);
    for (lld i = 1; i < ss; i++)
    {
        for (lld j = 1; j <= n; j++)
        {
            if (p[i - 1][j] != -1)
            {
                p[i][j] = p[i - 1][p[i - 1][j]];
            }
        }
    }
    while (q--)
    {
        cin >> a >> b;
        cout << lca(a, b, v, p, l) << nn;
    }
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    // test{
    solve();
    //}
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