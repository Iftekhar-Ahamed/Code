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
#define lld int
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1000000
// 1000000
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
struct data
{
    lld s = 0, e = 0, c = 0;
} tree[4*mXs];

void build(string &s, lld node, lld b, lld e)
{
    if (b == e)
    {
        if (s[b - 1] == '(')
        {
            tree[node].s = 1;
        }
        else
        {
            tree[node].e = 1;
        }
        return;
    }
    lld l = node * 2;
    lld r = l + 1;
    lld mid = (b + e) / 2;
    build(s, l, b, mid);
    build(s, r, mid + 1, e);
    lld nc = 0;
    if (tree[l].s <= tree[r].e)
    {
        nc = tree[l].s;
        tree[node].s = tree[r].s;
        tree[node].e = (tree[r].e - tree[l].s)+tree[l].e;
    }
    else
    {
        nc = tree[r].e;
        tree[node].s = tree[r].s + (tree[l].s - tree[r].e);
        tree[node].e = tree[l].e;
    }
    tree[node].c = tree[l].c + tree[r].c + nc;
}
struct data query(lld node, lld b, lld e, lld i, lld j)
{
    if (i > e || j < b)
    {
        struct data ob;
        return ob;
    }
    if (i <= b && j >= e)
    {
        return tree[node];
    }
    lld l = node * 2;
    lld r = l + 1;
    lld mid = (b + e) / 2;
    struct data ob = query(l, b, mid, i, j);
    struct data ob1 = query(r,mid+1,e, i, j);
    lld nc = 0;
    struct data ans;
    if (ob.s <= ob1.e)
    {
        nc = ob.s;
        ans.s = ob1.s;
        ans.e = (ob1.e - ob.s)+ob.e;
    }
    else
    {
        nc = ob1.e;
        ans.s = ob1.s + (ob.s - ob1.e);
        ans.e = ob.e;
    }
    ans.c = ob.c + ob1.c + nc;
    return ans;
}
void solve()
{
    string s; 
    cin >> s;
    lld x = s.size();
    build(s, 1, 1, x);
    lld n;
    cin >> n;
    while (n--)
    {
        lld l, r;
        cin >> l >> r;
        struct data ans = query(1, 1, s.size(), l, r);
        cout << ans.c * 2 << endl;
    }
}

int main()
{
    cin.tie(NULL);
    //read;
    // write;
    ios_base::sync_with_stdio(false);
    solve();
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