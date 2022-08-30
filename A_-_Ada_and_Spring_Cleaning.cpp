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
#define mXs (lld)1e5 + 1
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
const lld mod = 2117566807;
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
#define nn "\n"
lld bigMod(lld base, lld power,lld Mod)
{
    if (power == 0)
        return 0;
    else if (power == 1)
        return base;
    else if (power % 2 == 0)
    {
        lld x = bigMod(base, power / 2,Mod) % Mod;
        return (x * x) % Mod;
    }
    else
    {
        lld x = bigMod(base, power - 1,Mod) % Mod;
        return (base * x) % Mod;
    }
}
void calculateInverseAndpower(vector<vector<lld>> &power, vector<vector<lld>> &inv, pair<lld, lld> &base, pair<lld, lld> Mod)
{
    power[1][0] = power[0][0] = 1;
    inv[0][0] = inv[1][0] = 1;

    pair<lld, lld> invMod = {bigMod(base.first, Mod.first - 2,Mod.first), bigMod(base.second, Mod.second - 2,Mod.second)};

    for (lld i = 1; i < mXs; i++)
    {
        power[0][i] = (power[0][i - 1] * base.first) % Mod.first;
        inv[0][i] = (inv[0][i - 1] * invMod.first) % Mod.first;

        power[1][i] = (power[1][i - 1] * base.second) % Mod.second;
        inv[1][i] = (inv[1][i - 1] * invMod.second) % Mod.second;
    }
}
void calculateHashOfString(vector<vector<lld>> &power, string &s, vector<vector<lld>> &hash, pair<lld, lld> &Mod)
{
    hash[0][0] = 0;
    hash[1][0] = 0;
    for (lld i = 1; i <= s.size(); i++)
    {
        hash[0][i] = (hash[0][i - 1] + (s[i - 1] * power[0][i - 1]) % Mod.first) % Mod.first;
        hash[1][i] = (hash[1][i - 1] + (s[i - 1] * power[1][i - 1]) % Mod.second) % Mod.second;
    }
}
lld cmpString(vector<vector<lld>> &hashValue, vector<vector<lld>> &inv, pair<lld, lld> &Mod, lld length, lld size)
{
    set<pair<lld, lld>> ans;
    for (lld i = 0; i <= size - length; i++)
    {
        lld tempPatternHash0 = hashValue[0][i + length] - hashValue[0][i], tempPatternHash1 = hashValue[1][i + length] - hashValue[1][i];

        tempPatternHash0 = (tempPatternHash0 * inv[0][i]) % Mod.first, tempPatternHash1 = (tempPatternHash1 * inv[1][i]) % Mod.second;

        if (tempPatternHash0 < 0)
            tempPatternHash0 += Mod.first;

        if (tempPatternHash1 < 0)
            tempPatternHash1 += Mod.second;

        tempPatternHash0 %= Mod.first;

        tempPatternHash1 %= Mod.second;

        ans.insert({tempPatternHash0, tempPatternHash1});
    }
    return ans.size();
}
void solve(vector<vector<lld>> &power, vector<vector<lld>> &inv, pair<lld, lld> &Mod)
{
    lld n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<lld>> hasValue(2, vector<lld>(n + 1));
    calculateHashOfString(power, s, hasValue, Mod);
    cout << cmpString(hasValue, inv, Mod, k, n) << nn;
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);

    pair<lld, lld> base = {1949313259, 1997293877};
    pair<lld, lld> Mod = {2091573227, 2117566807};

    vector<vector<lld>> power(2, vector<lld>(mXs)), inv(2, vector<lld>(mXs));
    calculateInverseAndpower(power, inv, base, Mod);

    test
    {
        solve(power, inv, Mod);
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
