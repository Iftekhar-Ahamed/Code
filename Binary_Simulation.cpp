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
#include <iomanip>
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
#define mXs 100000
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_multiset;
const double pi = acos(-1.0);
string a;
pair<char,bool>Tree[mXs*4];
void buildtree(lld node,lld b, lld e){
    if(b==e){
        Tree[node]={a[b-1],false};
        return;
    }
    lld left = node*2;
    lld right = left+1;
    lld mid = (b+e)/2;
    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
    Tree[node]={0,false};
}
void update(lld node,lld b,lld e,lld i,lld j){
    //cout<<node<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<endl;
    if(b>j  || e<i){
             //cout<<node<<" Exit :"<<b<<" "<<e<<" "<<i<<" "<<j<<endl;
        return;
    }
    if(b>=i && j>=e){
        //cout<<node<<" Exit with update :"<<b<<" "<<e<<" "<<i<<" "<<j<<endl;
        // cout<<fixed<<setprecision(2)<<node<<" "<<i<<" "<<j<<endl;
        Tree[node].second = !Tree[node].second;
        return;
    }
    lld left = node*2;
    lld right = left+1;
    lld mid = (b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
}
char ans;
void print_node(){
    for(lld i=1;i<=23;i++){
       cout<<fixed<<i<<" :"<<Tree[i].first<<" "<<Tree[i].second<<endl;
    }
}
void query(lld node,lld b,lld e,lld pos,bool status){
    if(b>pos || e<pos){
        return;
    }
    if(pos == b && pos == e){
        //cout<<"Node : "<<node<<" NodeS :"<<Tree[node].second<<" Status :"<<status<<endl;
        if(status){
            if(Tree[node].first=='1'){
                ans = '0';
            }else{
                ans = '1';
            }
        }else{
            ans = Tree[node].first;
        }
        return;
    }
    lld left = node*2;
    lld right = left+1;
    lld mid = (b+e)/2;
    pair<lld,bool>l,r;

    //cout<<"left "<<left<<" "<<Tree[left].second<<" "<<"Right "<<right<<" "<<Tree[right].second<<" Status :"<<status<<endl;
    query(left,b,mid,pos,!(status==Tree[left].second));
    query(right,mid+1,e,pos,!(status==Tree[right].second));
}

void solve()
{
    lld n;
    cin>>a;
    n=a.size();
    lld q;
    cin>>q;
    char ch;
    buildtree(1,1,n);
    while(q--){
        cin>>ch;
        if(ch=='I'){
            lld i,j;
            cin>>i>>j;
            //cout<<"Before Update : "<<i<<","<<j<<endl;
            //print_node();
            update(1,1,n,i,j);
            //cout<<"After Update : "<<i<<","<<j<<endl;
            //print_node();
        }else{
            lld p;
            cin>>p;
            //cout<<"Query :"<<p<<endl;
            query(1,1,n,p,Tree[1].second);
            cout<<ans<<endl;
        }
    }
}

int main()
{
    cin.tie(NULL);
    //read;
    // write;
    ios_base::sync_with_stdio(false);
    lld c=1;
    test
    {
        cout<<"Case "<<c++<<":"<<endl;
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

