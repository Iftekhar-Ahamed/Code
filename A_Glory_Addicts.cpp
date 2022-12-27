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

void solve()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> a, b;
    vector<bool> take(n, false);
    int type[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> type[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (type[i] == 1)
        {
            a.push_back(x);
        }
        else
        {
            b.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a.size() == b.size() && a.size() >= 1 && b.size() >= 1)
    {

        if (a[0] < b[0])
        {
            ans += a[0];
            for (ll i = 1; i < a.size(); i++)
                ans += 2 * a[i];
            for (ll i = 0; i < b.size(); i++)
                ans += 2 * b[i];
        }
        else
        {
            ans += b[0];
            for (ll i = 1; i < b.size(); i++)
                ans += 2 * b[i];
            for (ll i = 0; i < a.size(); i++)
                ans += 2 * a[i];
        }
    }
    else if (a.size() < b.size())
    {
        for (ll i = 0; i < b.size() - a.size(); i++)
            ans += b[i];
        for (ll i = b.size() - a.size(), j = 0; i < b.size(); j++, i++)
        {
            ans += (2 * a[j]) + (2 * b[i]);
        }
    }
    else
    {
        for (ll i = 0; i < a.size() - b.size(); i++)
            ans += a[i];
        for (ll i = a.size() - b.size(), j = 0; i < a.size(); j++, i++)
        {
            ans += (2 * b[j]) + (2 * a[i]);
        }
    }

    cout << ans << nn;
}

int main()
{
    FIO;
    // read;
    // write;
    test
    {
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