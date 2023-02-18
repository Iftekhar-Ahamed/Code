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
vector<ll> prime;
void seive(ll n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        prime.push_back(i);
        if (is_prime[i] && (ll)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++)
    {
        if (n % prime[i] == 0)
        {
            ll c = 0;
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                c++;
            }
            v.push_back({c, prime[i]});
        }
    }
    if (n > 1)
    {
        v.push_back({1, n});
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < v.size(); i++)
    {
        ll mul = v[i].second;
        for (ll j = i + 1; j < v.size(); j++)
        {
            mul *= v[j].second;
            v[j].first -= v[i].first;
        }
        ans += (v[i].first * mul);
    }
    cout << ans << nn;
}

int main()
{
    FIO;
    // read;
    // write;
    seive(sqrt(1000000000) + 1);
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