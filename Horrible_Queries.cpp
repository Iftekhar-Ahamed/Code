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
    while (ct--)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;
struct Data
{
    ll lazyVlaue = 0, sum = 0;
};
void merge(struct Data &node, struct Data x, struct Data y, ll renge)
{
    node.sum = x.sum + y.sum + (renge * node.lazyVlaue);
}
struct Data update(ll node, ll b, ll e, ll x, ll y, ll value, vector<struct Data> &v)
{
    if (b >= x && e <= y)
    {
        v[node].lazyVlaue += value;
        v[node].sum += (e - b + 1) * value;
        return v[node];
    }
    else if (e < x || b > y)
    {
        return v[node];
    }
    ll l = node * 2;
    ll r = l + 1;
    ll mid = (b + e) / 2;
    merge(v[node], update(l, b, mid, x, y, value, v), update(r, mid + 1, e, x, y, value, v), e - b + 1);
    return v[node];
}
ll query(ll node, ll b, ll e, ll x, ll y, ll lazyValue, vector<struct Data> &v)
{
    if (b >= x && e <= y)
    {
        ll sum = (e - b + 1) * lazyValue + v[node].sum;
        return sum;
    }
    else if (e < x || b > y)
    {
        return 0;
    }
    ll l = node * 2;
    ll r = l + 1;
    ll mid = (b + e) / 2;
    ll sum = query(l, b, mid, x, y, lazyValue + v[node].lazyVlaue, v) + query(r, mid + 1, e, x, y, lazyValue + v[node].lazyVlaue, v);
    return sum;
}
void solve()
{
    ll n, q;

    cin >> n >> q;

    vector<struct Data> v(4 * n);

    while (q--)
    {
        ll x, y, value, type;
        cin >> type;
        if (type == 0)
        {
            cin >> x >> y >> value;
            update(1, 1, n, x + 1, y + 1, value, v);
        }
        else
        {
            cin >> x >> y;
            cout << query(1, 1, n, x + 1, y + 1, 0, v) << nn;
        }
    }
}

int main()
{
    FIO;
    // read;
    //  write;
    ll i = 1;
    test
    {
        cout << "Case " << i++ << ": " << nn;
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