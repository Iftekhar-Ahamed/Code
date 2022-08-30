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
#define mXs 30
#define test long long int ct;cin >> ct;while (ct--)
const double pi = acos(-1.0);
lld a[mXs];
struct data{
    lld suff,pre,sum,ans;
    data(){
        suff=pre=sum=ans=0;
    }
    void init(lld v){
        suff=pre=sum=v;
        ans=max(v,(lld)0);
    }
}tree[4*mXs];
void marge(struct data &l,struct data &r,struct data &ans){
    ans.sum=l.sum+r.sum;
    if(max(l.pre,r.pre)<ans.sum){
        ans.pre=ans.sum;
        ans.suff=r.suff;
        ans.ans=ans.sum;
    }else{
       if(l.pre>)
    }
}
void buildtree(lld &ans,lld node, lld b,lld e){
    if(b==e){
        tree[node].init(a[b]);
        return;
    }
    lld l = node*2;
    lld r = l+1;
    lld mid = (b+e)/2;
    buildtree(ans,l,b,mid);
    buildtree(ans,r,mid+1,e);
    struct data ans;
    marge(tree[l],tree[r],tree[ans]);
}
void update(lld &ans,lld node, lld b,lld e,lld p,lld v){
    if(p<b || e<p){
        return; 
    }
    if(b==e){
        tree[node]=v;
        return;
    }
    lld l = node*2;
    lld r = l+1;
    lld mid = (b+e)/2;
    update(ans,l,b,mid,p,v);
    update(ans,r,mid+1,e,p,v);
    ans = max(ans,tree[l]);
    ans = max(ans,tree[r]);
    tree[node]=tree[l]+tree[r];
    ans = max(ans,tree[node]);
}
void solve(){
    lld n,m;
    cin>>n>>m;
    for(lld i=1;i<=n;i++){
        cin>>a[i];
    }
    lld ans=0;
    if(n%2!=0)a[n+1]=0,n++;
    buildtree(ans,1,1,n);
    cout<<ans<<endl;
    while (m--)
    {
        lld p,v;
        cin>>p>>v;
        update(ans,1,1,n,p+1,v);
        cout<<ans<<endl;
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