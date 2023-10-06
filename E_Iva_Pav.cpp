/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;

#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test                 \
    ll ct;                   \
    cin >> ct, cin.ignore(); \
    for (ll i = 1; i <= ct; i++)
#define testcase cout << "Case " << i << ": ";
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 200000;
ll Node[4 * mXs];
ll a[mXs + 10];
void build(ll l, ll r, ll nd)
{
    if (l == r)
    {
        Node[nd] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(l, mid, 2 * nd + 1);
    build(mid + 1, r, 2 * nd + 2);
    Node[nd] = Node[2 * nd + 1] & Node[2 * nd + 2];
}

ll range(ll l, ll e, ll nd, ll ql, ll qe)
{
    if (ql <= l && qe >= e)
        return Node[nd];
    if (ql > e || qe < l)
        return INT_MAX;
    ll mid = (l + e) / 2;
    ll nd1 = range(l, mid, 2 * nd + 1, ql, qe);
    ll nd2 = range(mid + 1, e, 2 * nd + 2, ql, qe);
    return nd1 & nd2;
}
void solve()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(0, n - 1, 0);
    ll q;

    cin >> q;
    while (q--)
    {
        ll ss, k;
        cin >> ss >> k;
        ss--;
        ll L = ss, R = n - 1, r = -1;

        while (L <= R)
        {
            ll mid = L + (R - L) / 2;
            ll ans = range(0, n - 1, 0, ss, mid);
            if (ans >= k)
            {
                r = mid + 1;
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }
        cout << r << " ";
    }
    cout << nn;
}

int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(NULL), ios_base::sync_with_stdio(false);
#endif
    // read;
    // write;
    test
    {
        // testcase
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