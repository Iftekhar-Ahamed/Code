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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_multiset;
const double pi = acos(-1.0);


pair<lld,lld> Bfs(vector<vector<pair<lld,lld>>>&data,lld s)
{
    map<lld,bool>trace;
    queue<pair<lld,lld>>q;
    q.push({s,0});
    trace[s]=true;
    pair<lld,lld>ans= {0,0};
    while(!q.empty())
    {
        pair<lld,lld> u = q.front();
        if(ans.second<u.second)
        {
            ans=u;
        }
        q.pop();
        for(lld i=0; i<data[u.first].size(); i++)
        {
            if(!trace[data[u.first][i].first])
            {
                q.push({data[u.first][i].first,u.second+data[u.first][i].second});
                trace[data[u.first][i].first]=true;
            }
        }
    }
    //cout<<ans.first<<endl;
    return ans;
}

void solve()
{
    lld c,n,u,v;
    cin>>n;

    vector<vector<pair<lld,lld>>>data(n);
    for(lld i=0; i<n-1; i++)
    {
        cin>>u>>v>>c;
        data[u].push_back({v,c});
        data[v].push_back({u,c});
    }
    /*for(lld i=0;i<n;i++){
        for(lld j=0;j<data[i].size();j++){
            cout<<i<<" "<<data[i][j].first<<" "<<data[i][j].second<<endl;
        }
    }*/
    lld first = Bfs(data,0).first;
    cout<<Bfs(data,first).second<<endl;
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
        cout<<"Case "<<i++<<": ";
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

