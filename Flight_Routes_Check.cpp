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
#define mXs 10010
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
pair<lld, lld> a;
void dfs(lld u, lld p, vector<vector<lld>> &g, vector<bool> &visit, vector<lld> &et, vector<lld> &low, bool &ans)
{
    visit[u] = true;
    et[u] = et[p] + 1;
    low[u] = et[u];

    for (auto it = g[u].begin(); it != g[u].end() && ans; it++)
    {
        if (!visit[*it])
        {
            dfs(*it, u, g, visit, et, low, ans);
            low[u] = min(low[u], low[*it]);
            if (et[*it] <= low[*it] && ans)
            {
                a = {*it, u};
                ans = false;
                return;
            }
        }
        else
        {
            low[u] = min(low[u], low[*it]);
        }
    }
}
void solve()
{
    lld n, v, u, t, m;
    bool ans = true;
    cin >> n >> m;
    vector<vector<lld>> g(n + 1);
    vector<bool> visit(n + 1, false);
    vector<lld> et(n + 1, 0), low(n + 1, 0);

    for (lld i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (lld i = 1; i <= n && ans; i++)
    {
        if (!visit[i] && i == 1)
        {
            dfs(i, i, g, visit, low, et, ans);
        }
        else if (!visit[i])
        {
            a = make_pair(1, i);
            ans = false;
            break;
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl
             << a.first << " " << a.second << endl;
    }
}

int main()
{
    cin.tie(NULL);
    // read;
    //  write;
    ios_base::sync_with_stdio(false);
    // lld i=1;
    // test
    //{
    // cout<<"Case "<<i++<<":"<<endl;
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