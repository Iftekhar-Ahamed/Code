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
#define test        \
  long long int ct; \
  cin >> ct;        \
  while (ct--)
const double pi = acos(-1.0);

void buildTree(vector<lld>&a,vector<lld>&v, lld node, lld b, lld e)
{
  if(b==e){
    v[node]=a[b];
    return;
  }
  lld left = node*2;
  lld right = left+1;
  lld mid = (b+e)/2;
  buildTree(a,v,left,b,mid);
  buildTree(a,v,right,mid+1,e);
  v[node]=max(v[left],v[right]);
}
lld query(vector<lld>&tree,lld node,lld b,lld e, lld i,lld j){
  if(i>e || j<b){
    return INT_MIN;
  }
  if(j>=e && i<=b){
    return tree[node];
  }
  lld left = node*2;
  lld right = left+1;
  lld mid = (b+e)/2;
  lld p1 = query(tree,left,b,mid,i,j);
  lld p2 = query(tree,right,mid+1,e,i,j);
  return max(p1,p2);
}
void solve(vector<lld>&tree)
{
  lld i,j;
  cin>>i>>j;
  cout<<query(tree,1,1,7,i,j)<<endl;
}

int main()
{
  cin.tie(NULL);
  // read;
  // write;
  ios_base::sync_with_stdio(false);
  vector<lld> data = {INT_MIN,4, -9, 3, 7, 1, 0, 2};
  lld n = data.size()-1;
  vector<lld> tree((2 * n));
  buildTree(data,tree,1,1,n);
  test
  {
    solve(tree);
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