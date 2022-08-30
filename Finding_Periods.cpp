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
struct doubleHashing
{
    ll base1, base2, mod1, mod2, inv1, inv2;
    vector<ll> powerType1, powerType2, invType1, invType2;
    doubleHashing()
    {
        base1 = 1949313259;
        base2 = 1997293877;
        mod1 = 2091573227;
        mod2 = 2117566807;
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
        inv1 = bigMod(base1, mod1 - 2, mod1); 
        powerType1.resize(1000002), invType1.resize(1000002);
        powerType1[0] = invType1[0]  = 1;

        for (ll i = 1; i <= 1000000; i++)
        {
            powerType1[i] = (powerType1[i - 1] * base1) % mod1;
            invType1[i] = (invType1[i - 1] * inv1) % mod1;
        }
    }
    void calculateHashValue(string &s, vector<ll> &hash)
    {
        ll n = s.size();
        hash[0]= 0;
        for (ll i = 1; i <= n; i++)
        {
            hash[i]= (hash[i - 1] + ((s[i - 1] * powerType1[i - 1]) % mod1)) % mod1;
        }
    }

    ll occarenceOfpatren(vector<vector<ll>> &hashMain, vector<vector<ll>> &hashPatern)
    {
        ll ps = hashPatern.size() - 1, n = hashMain.size() - 1;
        ll hashOfPatern1 = hashPatern[ps][0], hashOfPatern2 = hashPatern[ps][1];
        ll count = 0;
        for (ll i = 0; i + ps <= n; i++)
        {
            ll th1 = hashMain[i + ps][0] - hashMain[i][0], th2 = hashMain[i + ps][1] - hashMain[i][1];
            th1 = (th1 * invType1[i]) % mod1, th2 = (th2 * invType2[i]) % mod2;
            if (th1 < 0)
                th1 += mod1;
            if (th2 < 0)
                th2 += mod2;
            if (th1 == hashOfPatern1 && th2 == hashOfPatern2)
            {
                count++;
            }
        }
        return count;
    }
};

void solve()
{
    string s;
    cin >> s;
    doubleHashing ob;
    vector<ll> hash(s.size() + 1);
    ob.calculateHashValue(s, hash);
    ll n = s.size();

    for (ll i = 1; i <= n; i++)
    {
        bool ok = true;
        for (ll j = i; (j+i) <= n; j+=i)
        {
            ll t = i+j;
            ll prefixHash1 = ((hash[j+i] - hash[j]) * ob.invType1[j]) % ob.mod1;
            if (prefixHash1 < 0)
            {
                prefixHash1 += ob.mod1;
            }

            if (hash[i] != prefixHash1 )
            {
                ok = false;
                break;
            }
        }
        if(s.size()%i && ok){
            ll j = (s.size()/i)*i;
            ll l = s.size()-j;
            ll hashOfShortString1 =((hash[s.size()] - hash[j]) * ob.invType1[j]) % ob.mod1;
            if(hashOfShortString1<0)hashOfShortString1+=ob.mod1;
            
            if(hash[l]!=hashOfShortString1){
                ok=false;
            }
        }
        if(ok){
            cout<<i<<" ";
        }
    }
    cout << nn;
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