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
#include <conio.h>
#define ll long long
#define INF (ll)1e16
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
const ll modulo = 1e9 + 7;
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn "\n"
void dfs(ll node, ll p, vector<vector<ll>> &v, vector<ll> &child)
{
    for (auto i : v[node])
    {
        if (i != p)
        {
            dfs(i, node, v, child);
            child[node] += (child[i] + 1);
        }
    }
}
void showChild(vector<ll> &child)
{
    for (ll i = 1; i < child.size(); i++)
    {
        cout << i << "\t" << child[i] << nn;
    }
}
ll go(ll node, ll parent, vector<vector<ll>> &v, vector<ll> &child)
{

    ll maximum = 0;
    //cout << node << nn;
    //getch();
    for (ll i = 0; i < v[node].size(); i++)
    {
        if (v[node][i] == parent)
        {
            v[node].erase(v[node].begin() + i);
        }
    }

    ll way1 = 0, way2 = 0;

    if (v[node].size() == 0)
    {
        //cout << "LAST NODE " << node << "  SUM = " << child[node] << nn;
        //getch();
        return child[node];
    }
    else if (v[node].size() == 1)
    {
        //cout << "ONE NODE " << node << "  SUM = " << child[v[node][0]] << nn;
        //getch();
        return child[v[node][0]];
    }
    else
    {
        //cout << "SELECT " << v[node][1] << " CUT " << v[node][0] << nn;
        //getch();
        way1 = (child[v[node][0]] + go(v[node][1], node, v, child));
        //cout << "SELECT " << v[node][0] << " CUT " << v[node][1] << nn;
        //getch();
        way2 = (child[v[node][1]] + go(v[node][0], node, v, child));
    }
    maximum = max(way1, way2);
    //cout << "NODE ->" << node << " MAX" << maximum << nn;
    return maximum;
}
void solve()
{
    ll n, m, x, y;
    cin >> n;
    vector<vector<ll>> v(n + 1);
    vector<ll> child(n + 1, 0);
    for (ll i = 1; i < n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, -1, v, child);
    // showChild(child);
    cout << go(1, -1, v, child) << nn;
}

int main()
{
    // cin.tie(NULL);
    //read;
    // write;
    // ios_base::sync_with_stdio(false);
    test
    {
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