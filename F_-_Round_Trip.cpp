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
vector<bool>visit;
vector<lld>ans;
bool f;
vector<vector<lld>>g;
void dfs(lld node,lld &root,lld parent){
    visit[node]=true;

    for(auto it:g[node]){

        if(!visit[it] && root == -1){
            dfs(it,root,node);
            if(root!=-1 && !f){
                ans.push_back(it);
                if(root == node){
                    ans.push_back(root);
                    f = true;
                }
            }
        }else if(parent!=it && root == -1 && f){
            root = it;
            ans.push_back(it);
            f = false;
        }
    }
}
void solve(){
    lld n,m,x,y;
    cin>>n>>m;
    visit.clear();
    ans.clear();
    visit.resize(n+1,false);
    g.resize(n+1);
    for(lld i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    f = true;
    
    lld root = -1;
    for(lld i=1;i<=n;i++){
        if(!visit[i] && root==-1){
            dfs(i,root,i);
        }
    }
    
    if(ans.size()<3){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<ans.size()<<endl;
        for(lld i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
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