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
lld maxx, sum, pos;
set<lld>treeedge;
void dfs(lld node, vector<vector<pair<lld, lld>>> &g, vector<lld> &c, set<lld> &ans, vector<lld> &trace)
{

    for (auto [a, b] : g[node])
    {
        if (c[a] == -1)
        {
            c[a] = (c[node] == 1 ? 0 : 1);
            dfs(a, g, c, ans, trace);
            sum += trace[a];
            if (maxx == sum)
            {
                treeedge.insert(b);
            }else if(maxx<sum){
                treeedge.clear();
                treeedge.insert(b);
                maxx=sum;
            }
        }
        else if (c[node] == c[a] && !ans.count(a))
        {
            trace[a]--;
            trace[node]++;
            ans.insert(b);
        }
    }
}

void solve()
{
    lld n, m;
    cin >> n >> m;
    vector<vector<pair<lld, lld>>> g(n + 1);
    vector<lld> c(n + 1, -1), trace(n + 1, 0);
    lld a, b;
    for (lld i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    set<lld> ans;
    lld count=0;
    for (lld i = 1; i <= n && count<2; i++)
    {
        if (c[i] == -1)
        {
            sum=0;
            pos=0;
            c[i] = 0;

            dfs(i, g, c, ans, trace);

            if(ans.size()!=0){
                count++;
                if(ans.size()==1){
                   continue;
                }else if(ans.size()==maxx){
                    ans=treeedge;
                }else{
                    count=100;
                }
            }
            
        }
    }

    if (ans.size() == 0)
    {
        cout << m << endl;
        for (lld i = 1; i <= m; i++)
        {
            cout << i << " ";
        }
    }
    else if(count<2)
    {
        cout << ans.size() << endl;
        for (auto i = ans.begin(); i != ans.end(); i++)
        {
            cout << *i + 1 << " ";
        }
    }else{
        cout<<0<<endl;
    }
    cout << endl;
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