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
void getPoint(ll n, ll &l, ll &r)
{
    if (n % 2)
    {
        r = (n / 2) + 1;
        l = (n / 2) - 1;
    }
    else
    {
        r = n / 2;
        l = r - 1;
    }
}

ll cal(ll a, ll b)
{
    ll need = 0;
    if (a < b)
    {
        need = 26 - (b - a);
    }
    else
    {
        need = a - b;
    }
    return need;
}
void solve(string &s)
{
    ll n = s.size();
    ll op = 0, ans = 0;
    for (ll i = n / 2; i < n; i++)
    {
        ll a = s[i] - 'a';
        ll b = s[n - i - 1] - 'a';
        a += op;
        a %= 26;
        ll t = cal(b, a);
        ans += t;
        op += t;
    }
    cout << ans << nn;
}

int main()
{
    FIO;
    // read;
    //  write;
    string s;
    while (cin >> s)
    {
        solve(s);
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