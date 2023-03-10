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
#define nn "\n"
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);

void make_table(lld n, lld a[], vector<vector<lld>> &v)
{

    for (lld i = 0; i < n; i++)
    {
        v[0][i] = a[i];
    }

    for (lld i = 1; (1 << i) <= n; i++)
    {
        for (lld j = 0; j + (1 << i) <= n; j++)
        {
            v[i][j] = max(v[i - 1][j], v[i - 1][j + (1 << i - 1)]);
        }
    }
    // for (lld i = 0; i < v.size(); i++)
    // {
    //     for (lld j = 0; j < n; j++)
    //     {
    //         cout << "i = " << i << " j = " << j << " :" << v[i][j] << endl;
    //     }
    //     cout << endl;
    // }
}
int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    lld n, Q;
    cin >> n >> Q;
    lld a[n];
    for (lld i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<lld>> v(log2(n) + 1, vector<lld>(n));
    make_table(n, a, v);

    lld ans = 0;
    while (Q--)
    {
        int x, y;
        cin >> x >> y;

        x--, y--;

        lld val = a[x];

        if (x > y)
        {
            y++;
        }
        else
        {
            y--;
        }

        if (x > y)
            swap(x, y);

        lld k = (y - x);
        k = log2(k);
        if (max(v[k][x], v[k][y - (1 << k) + 1]) == val)
        {
            ans++;
        }
    }
    cout << ans << nn;
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