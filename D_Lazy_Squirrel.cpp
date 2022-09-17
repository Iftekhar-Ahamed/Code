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
#define ll long long
#define INF (ll)1e16
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
const ll mXs = 1e6 + 10;
const ll modulo = 1e9 + 7;
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn "\n"
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
ll ans;
ll powerType[mXs], base = 1949313259, mod = 2091573227;
string s;

void precal()
{
    powerType[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
    {
        powerType[i] = (powerType[i - 1] * base) % mod;
    }
}
void dfs(ll node, ll parent, ll pre, ll suff, ll l, vector<vector<ll>> &G)
{

    pre = (pre + s[node - 1] * powerType[l]) % mod;
    if (pre < 0)
        pre += mod;
    suff = ((suff * powerType[1]) % mod + s[node - 1]) % mod;
    if (suff < 0)
    {
        suff += mod;
    }
    if (suff == pre)
        ans++;

    // cout << node << " " << parent << " " << suff << " " << pre << nn;

    for (auto i : G[node])
    {
        if (i != parent)
        {
            dfs(i, node, pre, suff, l + 1, G);
        }
    }
}
void solve()
{
    ans = 0;
    ll n, x, y;

    cin >> n;
    cin >> s;

    vector<vector<ll>> G(n + 1);

    for (ll i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 1, 0, 0, 0, G);
    ll g = __gcd(ans, n);

    cout << (ans / g) << "/" << (n / g) << nn;
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    precal();
    ll i = 1;
    ios_base::sync_with_stdio(false);
    test
    {
        cout << "Case " << i++ << ": ";
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