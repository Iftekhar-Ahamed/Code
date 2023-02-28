/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;

#define FIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll int
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test   \
    ll ct;     \
    cin >> ct; \
    for (ll i = 1; i <= ct; i++)
#define testcase cout << "Case " << i << ": ";
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 2e6;
vector<bool> v;
vector<ll> trace;
void add(ll pos, vector<ll> &ara, ll blockSize)
{

    ll blockpos;
    v[ara[pos] - 1] = true;
    ll l = ara[pos];
    blockpos = --l / blockSize;
    trace[blockpos]++;
}
void remove(ll pos, vector<ll> &ara, ll blockSize)
{

    ll blockpos;
    v[ara[pos] - 1] = false;
    ll l = ara[pos];
    blockpos = --l / blockSize;
    trace[blockpos]--;
}

ll quary(ll k, ll totalBlock, ll blockSize)
{
    ll i, pos = 0;
    for (i = 0; i < totalBlock && k >= trace[i]; i++)
    {
        k -= trace[i];
        pos += blockSize;
    }
    while (k > 0 && pos < mXs)
    {
        if (v[pos++])
            k--;
    }
    return pos + k;
}

void solve()
{
    v.resize(mXs, true);
    ll mtotalBlock = sqrt(mXs);
    ll mblockSize = mXs / mtotalBlock;
    trace.resize(mtotalBlock, mblockSize);
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }

    ll m;
    cin >> m;

    ll totalBlock = sqrt(n), dist = 0;
    ll blockSize = n / totalBlock;
    vector<tuple<ll, ll, ll, ll, ll>> queris(m);
    vector<ll> queryans(m);

    for (ll i = 0; i < m; i++)
    {
        ll blockpos, r, l, k;
        cin >> l >> r >> k;
        --r;
        blockpos = --l / blockSize;
        queris[i] = make_tuple(blockpos, (r % 2 == 0 ? r : -r), l, i, k);
    }
    sort(queris.begin(), queris.end());

    ll R, L;
    if (m >= 1)
    {
        auto [bpos, r, l, i, k] = queris[0];
        r = abs(r);
        L = l;
        R = r;
        while (l <= r)
        {
            remove(l, a, mblockSize);
            l++;
        }
        queryans[i] = quary(k, mtotalBlock, mblockSize);
    }
    for (ll q = 1; q < m; q++)
    {
        auto [bpos, r, l, i, k] = queris[q];
        r = abs(r);

        while (L > l)
        {
            remove(--L, a, mblockSize);
        }
        while (R < r)
        {
            remove(++R, a, mblockSize);
        }
        while (R > r)
        {
            add(R--, a, mblockSize);
        }
        while (L < l)
        {
            add(L++, a, mblockSize);
        }
        queryans[i] = quary(k, mtotalBlock, mblockSize);
    }
    for (auto i : queryans)
    {
        cout << i << nn;
    }
}

int main()
{
    FIO;
    // read;
    // write;
    // testcase
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