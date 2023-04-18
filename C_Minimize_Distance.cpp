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
    for (ll i = 1; i <= ct; i++)
#define testcase cout << "Case " << i << ": ";
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;
ll cal(vector<ll> &mp, ll k)
{

    reverse(mp.begin(), mp.end());
    ll ans = 0, bag = k, pev = 0;
    bool f = 1;
    while (!mp.empty())
    {
        ll pev = mp.back();
        for (ll i = 0; i < k && !mp.empty(); i++)
        {
            mp.pop_back();
        }
        ans += (pev * 2);
        if (f)
        {
            ans -= pev;
            f = 0;
        }
    }

    return ans;
}
ll cal1(vector<ll> &mp, ll k)
{
    reverse(mp.begin(), mp.end());
    ll ans = 0, bag = k, pev = 0;
    while (!mp.empty())
    {
        ll pev = mp.back();
        for (ll i = 0; i < k && !mp.empty(); i++)
        {
            mp.pop_back();
        }
        ans += (pev * 2);
    }

    return ans;
}
void solve()
{
    ll n, k, x = 0, y = 0;
    cin >> n >> k;
    ll a[n];
    vector<ll> mp, mp1;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= 0)
        {
            mp.push_back(a[i]);
        }

        else
        {
            mp1.push_back(a[i] * -1);
        }
    }
    sort(mp.rbegin(), mp.rend());
    sort(mp1.rbegin(), mp1.rend());
    if (mp1.size() == 0 || (!mp.empty() && mp[0] > mp1[0]))
    {
        swap(mp, mp1);
    }

    ll ans = cal1(mp, k) + cal(mp1, k);
    cout << ans << nn;
}

int main()
{
    FIO;
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