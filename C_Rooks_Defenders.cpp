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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

#define FIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
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
const ll mXs = 1e5 + 2;
ordered_set row, coulum;
map<ll, ll> mpcol, mprow;
void insertRook(ll x, ll y)
{
    row.insert(x);
    coulum.insert(y);
    mpcol[y]++;
    mprow[x]++;
}
void deleteRook(ll x, ll y)
{
    mpcol[y]--;
    mprow[x]--;
    if (mpcol[y] == 0)
    {
        coulum.erase(coulum.find(y));
    }
    if (mprow[x] == 0)
    {
        row.erase(row.find(x));
    }
}
void print()
{
    cout << "COLUMN" << nn;
    for (auto i : coulum)
    {
        cout << i << nn;
    }
}

bool aseNaki(ll x1, ll y1, ll x2, ll y2)
{
    ll dif = (x2 - x1);
    ll y = row.order_of_key(x2), x = row.order_of_key(x1);

    if (mprow[x2] && mprow[x1])
    {

        if ((y - x) == dif)
        {
            return true;
        }
    }
    // print();
    y = coulum.order_of_key(y2), x = coulum.order_of_key(y1);

    if (mpcol[y1] && mpcol[y2])
    {
        dif = y2 - y1;
        if ((y - x) == dif)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    ll n, q;
    cin >> n >> q;

    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            insertRook(x, y);
        }
        else if (t == 2)
        {
            ll x, y;
            cin >> x >> y;
            deleteRook(x, y);
        }
        else
        {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            if (aseNaki(a, b, c, d))
            {
                cout << "Yes" << nn;
            }
            else
            {
                cout << "No" << nn;
            }
        }
    }
}

int main()
{
    FIO;
    // read;
    //  write;

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
