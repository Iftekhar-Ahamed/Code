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
#define nn "\n"
lld f;
vector<lld> vv;
void dfs(lld node, lld parent, vector<vector<lld>> &g, vector<lld> &visit, vector<lld> &ans)
{
    if (g[node].size() != 0 && f == -1)
    {
        visit[node] = visit[parent] + 1;
        ans[node] = parent;

        for (auto it : g[node])
        {

            if (visit[it] == -1)
            {
                dfs(it, node, g, visit, ans);
            }
            else if (node != parent && f == -1)
            {
                ans[it] = node;
                f = it;

                for (lld i = f;; i = ans[i])
                {
                    vv.push_back(i);
                    if(i==ans[i]){
                        vv.clear();
                        break;
                    }
                    if (i == f && vv.size() > 1)
                    {
                        break;
                    }
                    
                }

                if(vv.size()==0){
                    f=-1;
                }
                
            }
        }
    }
}

void solve()
{
    lld n, m;
    cin >> n >> m;
    vector<vector<lld>> v(n + 1);
    lld a, b;
    for (lld i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
    }

    vector<lld> visit(n + 1, -1);
    vector<lld> p(n + 1, -1);

    f = -1;
    for (lld i = 1; i <= n && f == -1; i++)
    {
        f = -1;
        if (v[i].size() > 0 && visit[i] == -1)
        {
            dfs(i, i, v, visit, p);
        }
    }
    if (f != -1)
    {
        cout << vv.size() << nn;
        vector<lld> ans;

        for (lld i = vv.size() - 1; i >= 0; i--)
        {
            cout << vv[i] << " ";
        }
        cout << nn;
    }
    else
    {
        cout << "IMPOSSIBLE" << nn;
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