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

#define read freopen("0_input.txt","r",stdin)
#define write freopen("0_output.txt","w",stdout)
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long int
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test long long int ct;cin >> ct;while (ct--)
const double pi = acos(-1.0);
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
bool bfs(vector<vector<lld>>&v,vector<lld>&visit,vector<lld>&p){
    queue<lld>trace;
    trace.push(1);
    visit[1]=1;
    while (!trace.empty())
    {
        lld u = trace.front();
        trace.pop();
        for(lld i=0;i<v[u].size();i++){
            if(visit[v[u][i]]==-1){
                visit[v[u][i]]=visit[u]+1;
                trace.push(v[u][i]);
                p[v[u][i]]=u;
                //cout<<v[u][i]<<" "<<v.size()-1<<endl;
                if(v[u][i]==v.size()-1){
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){
    lld n , m, x, y;
    cin>>n>>m;
    
    vector<vector<lld>>v(n+1);
    vector<lld>visit(n+1,-1);
    vector<lld>parent(n+1,-1);
    for(lld i=0;i<m;i++){
        cin>>x>>y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    if(bfs(v,visit,parent)){
        cout<<visit[n]<<endl;
        vector<lld>ans;
        lld u = n;
        while (u!=1)
        {

            ans.push_back(u);
            u=parent[u];
            //cout<<u<<endl;
        }
        ans.push_back(1);
        for(lld i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}


int main()
{
    cin.tie(NULL);
    //read;
    //write;
    ios_base::sync_with_stdio(false);
    //test{
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