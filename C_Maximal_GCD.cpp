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
ll n, k;
vector<ll> divsor()
{
    vector<ll> div;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if ((k * i) <= n)
            {
                div.push_back(i);
            }
            if ((n / i) * k <= n)
            {
                div.push_back(n / i);
            }
        }
    }
    return div;
}

void solve()
{

    cin >> n >> k;
    if (k > (2LL * 1e5 + 2))
    {
        cout << -1 << '\n';
        return;
    }

    vector<ll> div = divsor();
    ll mx_gcd = -1;

    for (auto i : div)
    {
        ll total = i * (k * (k - 1) / 2);

        if (n - total > (k - 1) * i)
        {
            mx_gcd = max(i, mx_gcd);
        }
    }

    if (mx_gcd == -1)
    {
        cout << mx_gcd << nn;
    }
    else
    {
        for (ll i = 1; i < k; i++)
        {
            cout << i * mx_gcd << " ";
        }
        cout << n - (mx_gcd * (k * (k - 1) / 2)) << nn;
    }
}

int main()
{
    FIO;
    // read;
    // write;

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