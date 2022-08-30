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
#define lld long long
#define INF (lld)1e16
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test long long int ct;cin >> ct;while (ct--)
const lld modulo=1e9+7;
const double pi = acos(-1.0);
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn "\n"


void solve(){
    lld n,m;
    cin>>n>>m;
    vector<lld>dis(n+1,INF);
    vector<vector<pair<lld,lld>>>v(n+1);
    lld a,b,c;
    for(lld i=0;i<m;i++){
        cin>>a>>b>>c;
        //cout<<a<<" "<<b<<nn;
        v[a].push_back(make_pair(b,c));
    }

    lld minn=INF,maxx=-INF;
    priority_queue<tuple<lld,lld,lld,lld,lld>>pq;
    pq.push(make_tuple(0,1,0,0,1));
    lld minimumpriceroute=0;
    dis[1]=0;
    
    
    while (!pq.empty())
    {
        auto [cost,node,mininum,maximum,path] = pq.top();
        
        pq.pop();

        while(!pq.empty()&&get<0>(pq.top())==cost && get<1>(pq.top())==node){
            mininum = min(mininum,(lld)get<2>(pq.top()));
            maximum = max(maximum,(lld)get<3>(pq.top()));
            path+=(get<4>(pq.top()))%modulo;
            path%=modulo;
            pq.pop();
        }
        cost*=-1;
        if(node==n && dis[n]==cost){
            minn=min(mininum,minn);
            maxx=max(maxx,maximum);
            minimumpriceroute+=path;
            minimumpriceroute%=modulo;
        }else{
            for(auto [child,pcost]:v[node]){
                if(dis[child]>=cost+pcost && cost+pcost <= dis[n] ){
                   dis[child]=dis[node]+pcost;
                   pq.push(make_tuple(-dis[child],child,mininum+1,maximum+1,path));
                }
            }
        }
    }
    cout<<dis[n]<<" "<<minimumpriceroute<<" "<<minn<<" "<<maxx<<nn;

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