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
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;
string s[2];
ll go(ll r, ll pr, ll c, ll n)
{
    ll ans = 0;
    if (c + 1 == n)
    {
        ans = 1;

        if (r == 0)
        {
            if (s[r + 1][c] == 'B')
                ans++;
        }
        else
        {
            if (s[r - 1][c] == 'B')
                ans++;
        }
        return ans;
    }

    if (r == 0)
    {
        if (r + 1 != pr && s[r + 1][c] == 'B' && s[r][c + 1] == 'B')
        {
            ans = 1 + go(r + 1, r, c, n);
        }
        else
        {
            if (r + 1 != pr && s[r + 1][c] == 'B')
            {
                ans = 1 + go(r + 1, r, c, n);
            }
            else if (s[r][c + 1] == 'B')
            {
                ans = 1 + go(r, r, c + 1, n);
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        if (r - 1 != pr && s[r - 1][c] == 'B' && s[r][c + 1] == 'B')
        {
            ans = 1 + go(r - 1, r, c, n);
        }
        else
        {
            if (r - 1 != pr && s[r - 1][c] == 'B')
            {
                ans = 1 + go(r - 1, r, c, n);
            }
            else if (s[r][c + 1] == 'B')
            {
                ans = 1 + go(r, r, c + 1, n);
            }
            else
            {
                return 0;
            }
        }
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    cin >> s[0] >> s[1];

    ll b = 0, x = INF, y = INF;

    for (ll i = 0; i < n; i++)
    {
        if (s[0][i] == 'B')
            b++, x = min(x, i);

        if (s[1][i] == 'B')
            b++, y = min(y, i);
    }
    if (x == y)
    {
        if (b == go(0, -1, x, n) || b == go(1, -1, x, n))
        {
            cout << "YES" << nn;
        }
        else
        {
            cout << "NO" << nn;
        }
    }
    else
    {
        if (x < y && b == go(0, -1, x, n))
        {
            cout << "YES" << nn;
        }
        else if (b == go(1, -1, y, n))
        {
            cout << "YES" << nn;
        }
        else
        {
            cout << "NO" << nn;
        }
    }
}

int main()
{
    FIO;
    // read;
    // write;
    test
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