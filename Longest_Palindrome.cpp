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
const ll Mod = 1e9 + 7;
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn "\n"
ll powerType[1000002];
ll invType[1000002];
struct singleHashing
{
    ll base, mod, inv;
    singleHashing()
    {
        base = 1949313259;
        mod = 2091573227;
        precal();
    }
    ll bigMod(ll base, ll power, ll Mod)
    {
        if (power == 0)
            return 0;
        else if (power == 1)
            return base;
        else if (power % 2 == 0)
        {
            ll x = bigMod(base, power / 2, Mod) % Mod;
            return (x * x) % Mod;
        }
        else
        {
            ll x = bigMod(base, power - 1, Mod) % Mod;
            return (base * x) % Mod;
        }
    }
    void precal()
    {
        inv = bigMod(base, mod - 2, mod);
        powerType[0] = invType[0] = 1;

        for (ll i = 1; i <= 1000000; i++)
        {
            powerType[i] = (powerType[i - 1] * base) % mod;
            invType[i] = (invType[i - 1] * inv) % mod;
        }
    }
    void calculateHashValue(string &s, vector<ll> &hash)
    {
        ll n = s.size();
        hash[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            hash[i] = (hash[i - 1] + ((s[i - 1] * powerType[i - 1]) % mod)) % mod;
        }
    }
    ll rangeHash(ll i, ll j, vector<ll> &hashValue)
    {
        ll th1 = hashValue[j] - hashValue[i];
        th1 = (th1 * invType[i]) % mod;
        if (th1 < 0)
            th1 += mod;
        return th1;
    }
};

void solve()
{
    string s, p;
    cin >> s;
    p = s;
    reverse(s.begin(), s.end());
    ll ns = s.size(), np = p.size();

    singleHashing ob;
    vector<ll> mainHash(ns + 1);
    ob.calculateHashValue(p, mainHash);
    vector<ll> reverseHash(np + 1);
    ob.calculateHashValue(s, reverseHash);
    set<ll> ss;

    for (ll i = ns; i > 0; i--)
    {
        for (ll j = 0; j + i <= ns; j++)
        {
            // cout<<p.substr(j,i)<<" "<<ob.rangeHash(j,j+i,mainHash)<<nn;
            ss.insert(ob.rangeHash(j, j + i, mainHash));
        }
    }
    // cout<<"S"<<nn;
    for (ll i = ns; i > 0; i--)
    {
        for (ll j = 0; j + i <= ns; j++)
        {
            // cout<<s.substr(j,i)<<" "<<ob.rangeHash(j,j+i,reverseHash)<<" "<<p.substr(j,i)<<nn;
            if (ss.count(ob.rangeHash(j, j + i, reverseHash)))
            {
                // ll t = i==0?1:i;
                cout << s.substr(j, i) << nn;
                return;
            }
        }
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