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

void solve()
{
    ll n;
    cin >> n;
    string s, t, t1, x, x1;
    cin >> s;
    x = t = s;
    ll mx = -INF, mn = INF, mn1 = INF, mx1 = -INF;
    for (ll i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            mx = max(mx, j);
            mn = min(mn, j);
            mn1 = min(mn1, i);
            mx1 = max(mx1, i);
        }
    }
    if (mx == -INF && mn == INF)
    {
        cout << "Yes" << nn;
        return;
    }
    for (ll j = mn; j <= mx; j++)
    {
        if (t[j] == '0')
            t[j] = '1';
        else
        {
            t[j] = '0';
        }
    }
    for (ll j = mn1; j <= mx1; j++)
    {
        if (x[j] == '0')
            x[j] = '1';
        else
        {
            x[j] = '0';
        }
    }

    t1 = t;
    x1 = x;
    reverse(t1.begin(), t1.end());
    reverse(x1.begin(), x1.end());
    if (t1 == t || x1 == x)
    {
        cout << "Yes" << nn;
    }
    else
    {
        cout << "No" << nn;
    }
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