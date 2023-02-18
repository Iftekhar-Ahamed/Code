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

struct NCR
{
    // এইখানে মড যেটা টেম্পলেট এ দেওয়া আছে সেটাই ইউজ করা হইছে
    vector<ll> fact, invfact;
    NCR(ll n)
    {
        fact.resize(n + 1);
        invfact.resize(n + 1);
        fact[0] = 1;
        for (ll i = 1; i <= n; i++)
        {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invfact[n] = big_mod(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--)
        {
            invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
        }
    }
    ll big_mod(ll base, ll power)
    {
        if (power == 0)
            return 1;
        if (power % 2 == 1)
        {
            ll p1 = base % mod;
            ll p2 = (big_mod(base, power - 1)) % mod;
            return (p1 * p2) % mod;
        }

        ll p1 = (big_mod(base, power / 2)) % mod;
        return (p1 * p1) % mod;
    }
    ll ncr(ll n, ll r)
    {
        if (r == 0 || r > n)
            return 1;
        ll ans = ((fact[n] * invfact[r]) % mod * invfact[n - r]) % mod;
        return ans;
    }
};

void solve(NCR &ob)
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    n = a.size();
    ll c = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            c++;
    }

    if ((n - c) % 2)
    {
        cout << 0 << nn;
    }
    else
    {
        ll ans = ob.big_mod(2, c);
        ll x = ob.ncr((n - c), (n - c) / 2);
        ans = (ans * x) % mod;
        cout << ans << nn;
    }
}

int main()
{
    FIO;
    // read;
    // write;
    NCR ob(200000); // Range
    test
    {
        // testcase
        solve(ob);
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