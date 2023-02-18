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
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mxs = 1e4 + 5;

vector<ll> primes;
bool mark[mxs];

void isPrime()
{
    for (ll i = 2; i < mxs; i++)
    {
        if (mark[i] == false)
        {
            primes.push_back(i);
            for (ll j = i + i; j < mxs; j += i)
                mark[j] = true;
        }
    }
}

void primeFactor(set<ll> &v, ll n)
{
    for (ll i = 0; primes[i] * primes[i] <= n; i++)
    {
        ll p = primes[i];

        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n /= p;
            }
            v.insert(p);
        }
    }
    if (n > 1)
    {
        v.insert(n);
    }
}
void primeFactor1(map<ll, ll> &v, ll n)
{
    for (ll i = 0; primes[i] * primes[i] <= n; i++)
    {
        ll p = primes[i];
        if (n % p == 0)
        {

            while (n % p == 0)
            {
                n /= p;
                v[p]++;
            }
        }
    }
    if (n > 1)
    {
        v[n]++;
    }
}
void solve()
{
    // cout << primes.size() << nn;
    ll n;
    cin >> n;

    set<ll> x, y;
    ll gc = 0;
    ll a[n + 1], b[n + 1];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        primeFactor(x, a[i]);
        gc = __gcd(gc, a[i]);
    }
    ll xx = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == a[i])
            xx++;
        primeFactor(y, b[i]);
    }

    if (xx == n)
    {
        cout << "Yes Yes" << nn;
        return;
    }

    bool f = true;

    for (auto i : y)
    {
        if (x.count(i) == 0)
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "Yes ";

        // if (gc == 1)
        // {
        //     cout << "No" << nn;
        //     return;
        // }
        // map<ll, ll> a0, b0;
        // f = true;

        // primeFactor1(a0, a[0]);
        // primeFactor1(b0, b[0]);

        // ll div = 1, mul = 1;
        // for (auto [key, val] : a0)
        // {
        //     if (b0[key] < val)
        //     {
        //         div *= pow(key, val - b0[key]);
        //     }
        //     else if (b0[key] > val)
        //     {
        //         mul *= pow(key, val - b0[key]);
        //     }
        //     if (gc % key != 0)
        //     {
        //         f = false;
        //     }
        // }
        // for (auto [key, val] : b0)
        // {
        //     if (a0[key] == 0)
        //     {
        //         mul *= pow(key, val);
        //     }
        //     if (gc % key != 0)
        //     {
        //         f = false;
        //     }
        // }

        // if (f)
        // {

        //     for (ll i = 0; i < n; i++)
        //     {
        //         ll t = a[i] * mul;
        //         if (t % div == 0)
        //         {
        //             t /= div;
        //             if (t != b[i])
        //             {
        //                 f = false;
        //                 break;
        //             }
        //         }
        //         else
        //         {
        //             f = false;
        //             break;
        //         }
        //     }
        //     if (f)
        //     {
        //         cout << "Yes" << nn;
        //     }
        //     else
        //     {
        //         cout << "No" << nn;
        //     }
        // }
        // else
        // {
        //     cout << "No" << nn;
        // }
    }
    else
    {
        cout << "No No" << nn;
        return;
    }

    // if (f && gc > 1)
    // {

    //     cout << "Yes" << nn;

    // }
    // else
    // {

    //     cout << "No" << nn;
    // }
}

int main()
{
    FIO;
    // read;
    // write;
    isPrime();
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
