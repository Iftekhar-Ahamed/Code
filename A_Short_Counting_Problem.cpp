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
bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
set<ll> primeFact(ll num)
{
    set<ll> s;
    if (num % 2 == 0)
    {
        s.insert(2);
        while (num % 2 == 0)
        {
            num /= 2;
        }
    }

    for (ll i = 3; i * i <= num; i += 2)
    {
        if (isPrime(i) && num % i == 0)
        {
            s.insert(i);
            while (num % i == 0)
            {
                num /= i;
            }
        }
    }

    if (num > 1)
    {
        s.insert(num);
    }
    return s;
}
ll cal(vector<ll> primeList, ll R)
{
    ll n = (1 << primeList.size());
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll mul = 1LL;
        ll c = 0;
        for (ll j = 0; j < primeList.size(); j++)
        {
            if (i & (1 << j))
            {
                mul *= primeList[j];
                c++;
            }
        }
        ll t = R / mul;
        if (c % 2 == 0)
        {
            ans += t;
        }
        else
        {
            ans -= t;
        }
    }
    return ans;
}
void solve()
{
    ll A, B, L, R;
    cin >> A >> B >> L >> R;

    set<ll> primeList = primeFact(A), b = primeFact(B);
    vector<ll> a;

    for (auto i : primeList)
    {
        a.push_back(i);
    }

    ll ans = cal(a, R) - cal(a, L - 1);

    a.clear();
    for (auto i : b)
    {
        a.push_back(i);
    }

    ans += (cal(a, R) - cal(a, L - 1));

    primeList.insert(b.begin(), b.end());

    vector<ll> v;
    for (auto i : primeList)
    {
        v.push_back(i);
    }

    ans -= (cal(v, R) - cal(v, L - 1));
    cout << ans << nn;
}

int main()
{
    FIO;
    // read;
    //  write;

    // testcase
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