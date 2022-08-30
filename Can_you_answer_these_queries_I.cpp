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
#define lld long long
#define INF (lld)1e16
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
const lld modulo = 1e9 + 7;
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn "\n"
struct Data
{
    lld prefix,suffix,sum,ans;
    Data(lld v1,lld v2,lld v3,lld v4){
        prefix=v1;
        suffix=v2;
        sum=v3;
        ans = v4;
    }
    Data(){
        prefix=0;
        suffix=0;
        sum=0;
        ans=0;
    }
    Data operator+(const Data &ob)const{
        Data m;
        m.sum = ob.sum+sum;
        m.prefix = max(ob.prefix,ob.sum+prefix);
        m.suffix = max(suffix,sum+ob.suffix);
        m.ans = max({ans,ob.ans,ob.suffix+prefix});
        return m;
    }
};

void build(lld node, lld b, lld e, vector<Data>&tree, vector<lld> &v)
{
    if (b == e)
    {
        tree[node] = Data(v[b],v[b],v[b],v[b]);
        return;
    }
    lld left = node * 2;
    lld right = left + 1;
    lld mid = (b + e) / 2;
    build(left, b, mid, tree, v);
    build(right, mid + 1, e, tree, v);
    tree[node] = tree[left]+tree[right];
}

Data query(lld node, lld b, lld e, vector<Data> &tree, lld l, lld r)
{
    if (l <= b && r >= e)
    {
        return tree[node];
    }
    lld left = node * 2;
    lld right = left + 1;
    lld mid = (b + e) / 2;
    if(r<=mid){
        return query(left, b, mid, tree, l, r);
    }else if(l>mid){
        return query(right, mid + 1, e, tree, l, r);
    }else
    return query(left, b, mid, tree, l, r)+query(right, mid + 1, e, tree, l, r);
}
void solve()
{
    lld n, q;

    cin >> n;

    vector<lld> v(n + 1);
    for (lld i = 1; i <= n; i++)
        cin >> v[i];

    vector<Data> tree(n * 4);
    build(1, 1, n, tree, v);
    cin >> q;
    while (q--)
    {

        lld l, r;
        cin >> l >> r;
        cout << query(1, 1, n, tree, l, r).ans << nn;
    }
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    // test{
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