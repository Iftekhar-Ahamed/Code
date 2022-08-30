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
const double pi = acos(-1.0);
const lld modulo=1e9+7;
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn "\n"
struct Node
{
    lld start,end,sum;
    Node(){
        start=end=sum=0;
    }
    Node operator+(const Node& ob)const{
        Node add;
        add.start=ob.start;
        add.end=end;
        add.sum+=sum+ob.sum;
        return add;
    }
}Data;

void build_tree(lld node,lld b,lld e,vector<Node>&bit,vector<lld>&v){
    if(b==e){
        bit[node].start=bit[node].end=b;
        bit[node].sum = v[b];
        return;
    }
    lld left = node*2;
    lld right = left+1;
    lld mid = (b+e)/2;
    build_tree(left,b,mid,bit,v);
    build_tree(right,mid+1,e,bit,v);
    bit[node]=bit[right]+bit[left];
}
void update(lld node,lld b,lld e,vector<Node>&bit,lld pos,lld value){
    if(b==pos && e==pos){
        bit[node].sum+=value;
        return;
    }
    if(b>pos || e<pos){
        return;
    }
    lld left = node*2;
    lld right = left+1;
    lld mid = (b+e)/2;
    update(left,b,mid,bit,pos,value);
    update(right,mid+1,e,bit,pos,value);
    bit[node]=bit[right]+bit[left];
}
Node query(lld l,lld r,lld node,lld b,lld e,vector<Node>&bit){
    if(l<=bit[node].start && r >= bit[node].end){
        return bit[node];
    }
    if(l>bit[node].end || r<bit[node].start){
        return Node();
    }
    lld left = node*2;
    lld right = left+1;
    lld mid = (b+e)/2;
    Node ob = query(l,r,left,b,mid,bit);
    Node ob1 = query(l,r,right,mid+1,e,bit);
    Node ans = ob1+ob;
    return ans;
}
void solve(){
    lld n,q;
    cin>>n>>q;

    vector<lld>v(n);
    for(lld i=0;i<n;i++)cin>>v[i];

    vector<tuple<char,lld,lld>>querylist;
    char type;
    lld a,b;

    vector<lld>mergin(v.begin(),v.end());

    for(lld i=0;i<q;i++){
        cin>>type>>a>>b;
        querylist.push_back(make_tuple(type,a,b));
        if(type=='!'){
            mergin.push_back(b);
        }else{
            mergin.push_back(b);
            mergin.push_back(a);
        }
    }

    sort(mergin.begin(),mergin.end());
    mergin.erase(unique(mergin.begin(),mergin.end()),mergin.end());

    vector<lld>bit(mergin.size()+1);
    vector<Node>tree(4*mergin.size());
    lld bn = sqrt(mergin.size());

    for(lld i=0;i<n;i++){
        lld pos = lower_bound(mergin.begin(),mergin.end(),v[i])-mergin.begin()+1;
        v[i]=pos;
        bit[pos]++;
    }
    build_tree(1,1,mergin.size(),tree,bit);
    for(auto [ch,x,y]:querylist){
        if(ch=='!'){
            lld pos = lower_bound(mergin.begin(),mergin.end(),y)-mergin.begin()+1;
            update(1,1,mergin.size(),tree,pos,1);
            update(1,1,mergin.size(),tree,v[x-1],-1);
            v[x-1]=pos;
        }else{
            lld l = lower_bound(mergin.begin(),mergin.end(),x)-mergin.begin()+1;
            lld r = lower_bound(mergin.begin(),mergin.end(),y)-mergin.begin()+1;
            cout<<query(l,r,1,1,mergin.size(),tree).sum<<nn;
        }
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