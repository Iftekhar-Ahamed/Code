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
ll vv[1000002];
void seive(vector<ll> &v)
{
    /*
    ll n = 1000002;
    bool mark[n + 2];
    memset(mark, true, sizeof(mark));
    for (ll i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            v.push_back(i);
            for (ll j = i * i; j <= n; j += i)
            {
                mark[j] = false;
            }
        }
    }*/
    for(ll i=2;i<=1000000;i++){
        for(ll j=i;j<=1000000;j+=i)vv[j]++;
    }
}

void solve(vector<ll> &v)
{
    ll n, ans = 1;
    cin >> n;
    //cout<<v[v.size()-1]<<nn;
    /*
    for (ll i = 0; i < v.size() && n != 1 && v[i]<=n; i++)
    {
        ll c = 1;

        while (n % v[i] == 0 && n!=1)
        {
            //cout<<n<<" "<<v[i]<<nn;
            n /= v[i];
            c++;
            //cout<<n<<" "<<v[i]<<nn;
        }

        ans*=c;
    }
    cout<<ans<<nn;
    */
   cout<<vv[n]+1<<nn;
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    vector<ll> v;
    seive(v);
    test
    {
        solve(v);
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