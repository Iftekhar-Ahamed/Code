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
#define lld long long
const lld INF = 10000000000000000LL;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
void bfs(lld s, vector<lld>&cost , vector<vector<pair<lld, lld>>> &g)
{
    priority_queue<pair<lld, lld>> trace;
    trace.push({0,s});

    cost[s] = 0;
    vector<bool>visit(cost.size(),false);

    while (!trace.empty())
    {
        lld c = -trace.top().first, node = trace.top().second;

        trace.pop();
        if(visit[node])continue;
        visit[node]=true;

        for (lld i = 0; i < g[node].size(); i++)
        {
            lld u = g[node][i].first, uc = g[node][i].second;

            if (cost[u] > c + uc)
            {
                cost[u] = c + uc;
                trace.push({-cost[u],u});
            }
        }
    }
}

void solve()
{
    lld n, m, u, v, c;
    cin >> n >> m;
    vector<vector<pair<lld, lld>>> g(n + 2),rg(n + 2);
    vector<lld> cost(n + 1, INF),rcost(n + 1, INF);
    vector<pair<lld,pair<lld,lld>>>tarce;
    for (lld i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        tarce.push_back({u,{v,c}});
        g[u].push_back({v, c});
        rg[v].push_back({u, c});
    }
    bfs(1, cost, g);
    bfs(n, rcost, rg);
    lld ans = INF;
    for(lld i=0;i<m;i++){
        ans = min(ans,(cost[tarce[i].first]+rcost[tarce[i].second.first])+tarce[i].second.second/2);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    // test{
    solve();
    // }
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