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
ll dp[15];
ll check(ll num)
{
    string s = to_string(num);
    ll c = 0;
    for (auto i : s)
        if (i == '0')
        {
            c++;
        }
    return c;
}
ll digitDp(ll dep, string &limit, ll num, bool tight)
{
    if (dep == limit.size())
    {
        return check(num);
    }
    if (dp[dep] != -1)
    {
        return check(num) + dp[dep];
    }
    ll ub = tight ? limit[dep] - '0' : 9;
    ll ans = 0;
    for (ll i = 0; i <= ub; i++)
    {
        ans += digitDp(dep + 1, limit, (num * 10) + i, tight & (ub == i));
    }
    return dp[dep] = ans;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    string limit = to_string(m);
    ll x = 1;
    memset(dp, -1, sizeof(dp));
    limit = to_string(m);
    x = digitDp(0, limit, false, true);
    ll y = 0;
    memset(dp, -1, sizeof(dp));
    if (n != 0)
    {
        limit = to_string(--n);
        y = digitDp(0, limit, false, true);
    }
    cout << x - y << nn;
}

int main()
{
    FIO;
    // read;
    // write;
    test
    {
        testcase
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