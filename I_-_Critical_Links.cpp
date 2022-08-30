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
bool visit[mXs];
vector<pair<lld, lld>> ans;
vector<vector<lld>> g;
lld eT[mXs], low[mXs];
void dfs(lld u, lld p, lld et)
{
    visit[u]=true;
    eT[u] = et;
    low[u] = et;
    for (auto it = g[u].begin(); it != g[u].end(); it++)
    {
        if (!visit[*it])
        {
            dfs(*it, u, et + 1);
            low[u] = min(low[u], low[*it]);
            if (eT[*it] <= low[*it])
            {
                ans.push_back({min(u, *it), max(u, *it)});
            }
        }
        else if (*it != p)
        {
            low[u] = min(low[u], low[*it]);
        }
    }
}
void solve()
{
    lld n, v, u, t;
    cin >> n;
    ans.clear();
    g.clear();
    g.resize(n);
    char ch;
    for (lld i = 0; i < n; i++)
    {
        cin >> u >> ch >> t >> ch;
        for (lld j = 0; j < t; j++)
        {
            cin >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    memset(visit, false, sizeof(visit));
    for (lld i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            dfs(i, i, 1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() <<" critical links"<< "\n";
    for (lld i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " - " << ans[i].second << "\n";
    }
}

int main()
{
    cin.tie(NULL);
    //read;
    // write;
    ios_base::sync_with_stdio(false);
    lld i=1;
    test
    {
        cout<<"Case "<<i++<<":"<<"\n";
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