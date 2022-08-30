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

void dfs(lld node,lld p,bool &f,vector<vector<pair<lld,lld>>>&v,vector<lld>&sw,vector<int>&visit){
    if(f){
        for(auto [child,status]:v[node]){
            if(visit[child]==-1){

                if(status==0){
                    if(visit[node]==1){
                        visit[child]=0;
                    }else{
                        visit[child]=1; //u-->v (0) v=1;
                    }
                }else{
                    if(visit[node]==1){
                        visit[child]=1;
                    }else{
                        visit[child]=0; //u-->v (0) v=1;
                    }
                }
    
                dfs(child,node,f,v,sw,visit);


            }else{
                if(visit[child]==visit[node]){
                    if(status==0){
                        f=false;
                    }
                }else{
                    if(status==1){
                        f=false;
                    }
                }
            }
        }
    }
}

void solve(){
    lld x,y,n,m;
    cin>>n>>m;
    vector<vector<lld>>v(n+1);
    vector<vector<pair<lld,lld>>>graph(m+1);
    vector<lld>ds(n+1,1);

    for(lld i=1;i<=n;i++){
        cin>>ds[i];
    }
    
    for(lld i=1;i<=m;i++){
        lld t;
        cin>>t;
        while (t--)
        {
            cin>>x;
            v[x].push_back(i);
        }
    }
    /*
    map<pair<lld,lld>,lld>mp;
    for(lld i=1; i<=n; i++)
    {
        lld a=v[i][0];
        lld b=v[i][1];
        if(mp[ {a,b}]>0&&mp[ {a,b}]!=ds[i]+1)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(mp[ {a,b}])
            continue;
        mp[ {a,b}]=ds[i]+1;
        mp[ {b,a}]=ds[i]+1;
        graph[a].push_back({b,ds[i]});
        graph[b].push_back({a,ds[i]});
    }*/
    
    for(lld i=1;i<=n;i++){
        graph[v[i][0]].push_back({v[i][1],ds[i]});
        graph[v[i][1]].push_back({v[i][0],ds[i]});
    }


    vector<int>visit(m+1,-1);
    

    bool f = true;
    for(lld i=1; i<=m && f; i++)
    {
        if(visit[i]==-1)
        {
            visit[i]=0;
            dfs(i,i,f,graph,ds,visit);
        }
    }
   

    if(f){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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