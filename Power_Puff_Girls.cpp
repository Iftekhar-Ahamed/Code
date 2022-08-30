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
#define ll long long
#define INF (ll)1e16
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test long long int ct;cin >> ct;while (ct--)
const double pi = acos(-1.0);
const ll modulo=1e9+7;
int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};
#define nn "\n"
ll bfs(vector<vector<char>>&g,ll n,ll m,ll hX,ll hY,ll sX,ll sY){
    vector<vector<bool>>visit(n,vector<bool>(m,false));
    visit[sX][sY]=true;
    queue<tuple<ll,ll,ll>>q;
    q.push({sX,sY,0});
    while (!q.empty())
    {
        auto [u,v,c]=q.front();
        q.pop();

        if(u==hX && v == hY){
            return c;
        }

        for(ll i=0;i<4;i++){
            ll tr = u+dRow[i], tc = v+dCol[i];
            if(tr>=0 && tr<n && tc>=0 && tc<m && !visit[tr][tc] && g[tr][tc]!='#' && g[tr][tc]!='m'){
                q.push({tr,tc,c+1});
                visit[tr][tc]=true;
            }
        }
    }
    return 0;
}

void solve(){
    ll n,m,hi,hj,ans=0;
    cin>>n>>m;
    vector<vector<char>>g(n,vector<char>(m));
    vector<pair<ll,ll>>hero;

    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='a'||g[i][j]=='b'||g[i][j]=='c'){
                hero.push_back({i,j});
            }else if(g[i][j]=='h'){
                hi=i,hj=j;
            }
        }
    }
    for(auto [i,j]:hero){
        ans = max(ans,bfs(g,n,m,hi,hj,i,j));
    }
    cout<<ans<<nn;
}


int main()
{
    cin.tie(NULL);
    //read;
    //write;
    ios_base::sync_with_stdio(false);
    ll i=1;
    test{
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