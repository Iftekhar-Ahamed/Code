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
const ll mXs = 1e6;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
ordered_set v;
void add(ll pos, vector<ll> &ara)
{
    v.insert(ara[pos]);
}
void remove(ll pos, vector<ll> &ara)
{
    int rank = v.order_of_key(ara[pos]);
    auto it = v.find_by_order(rank);
    v.erase(it);
}
void print()
{
    cout << "********" << nn;
    for (ll i = 0; i < v.size(); i++)
    {
        cout << *v.find_by_order(i) << nn;
    }
}
ll quary(ll k)
{
    ll siz = v.size();

    if (k > mXs)
    {
        k -= siz;
        return mXs + k;
    }

    ll it = *v.find_by_order(k);
    return it;
}

void solve()
{
    for (ll i = 1; i <= mXs + 1; i++)
    {
        v.insert(i);
    }
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
            remove(l, a);
            l++;
        }
        // print();
        queryans[i] = quary(k - 1);
    }
    for (ll q = 1; q < m; q++)
    {
        auto [bpos, r, l, i, k] = queris[q];
        r = abs(r);

        while (L > l)
        {
            remove(--L, a);
        }
        while (R < r)
        {
            remove(++R, a);
        }
        while (R > r)
        {
            add(R--, a);
        }
        while (L < l)
        {
            add(L++, a);
        }

        // print();
        queryans[i] = quary(k - 1);
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