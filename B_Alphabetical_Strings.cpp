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
const ll mXs = 1e6;
bool ok(string &s)
{

    ll a = 1, b = 1;
    for (ll i = 1; i < s.size(); i++)
    {
        if (s[i] > s[i - 1])
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    // for (ll i = 1; i < s.size(); i++)
    // {
    //     if (s[i - 1] < s[i])
    //     {
    //         a++;
    //     }
    // }
    // if (a == s.size())
    // {
    //     return true;
    // }
    // a = 1;
    // for (ll i = 1; i < s.size(); i++)
    // {
    //     if (s[i - 1] > s[i])
    //     {
    //         a++;
    //     }
    // }
    // if (a == s.size())
    // {
    //     return true;
    // }

    // return false;

    return (a == s.size() || b == s.size());
}
void solve()
{
    string t;
    cin >> t;
    string x, y;
    ll f = 0;
    set<ll> s;

    for (ll i = 0; i < t.size(); i++)
    {
        s.insert(t[i]);

        if (t[i] == 'a')
        {
            x += 'a';
            f = 1;
        }

        if (f == 0)
        {
            x += t[i];
        }
        else
        {
            y += t[i];
        }
    }

    for (ll i = 0; i < t.size(); i++)
    {
        char ch = 'a' + i;
        if (s.count(ch) == 0)
        {
            cout << "NO" << nn;
            return;
        }
    }
    // cout << x << " " << y << nn;
    if (ok(x) && ok(y))
    {
        cout << "YES" << nn;
    }
    else
    {
        cout << "NO" << nn;
    }
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