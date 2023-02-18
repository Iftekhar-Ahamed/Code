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
ll sumOfDigit(ll a)
{
    ll sum1 = 0;
    while (a > 0)
    {
        sum1 += (a % 10);
        a /= 10;
    }

    return sum1;
}

ll cc = 1001;

void brute(ll n)
{
    for (ll i = 0; i <= n; i += 1)
    {
        if (abs(sumOfDigit(i) - sumOfDigit(n - i)) <= 1)
        {
            cout << i << " " << n - i << nn;
            return;
        }
    }
}
void solve()
{
    ll n = cc;
    // cc += 2;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << nn;
    }
    else
    {
        ll y = n / 2;

        ll x = n - y;

        ll sum1 = sumOfDigit(y), sum2 = sumOfDigit(x);

        if (abs(sum1 - sum2) > 1)
        {
            ll sumn = sumOfDigit(n) / 2, nsum = 0;
            vector<ll> a, b;
            while (n > 0)
            {
                ll d = n % 10;

                if (nsum + d < sumn)
                {
                    a.push_back(0);
                    b.push_back(d);
                    nsum += d;
                }
                else if (sumn != nsum)
                {
                    ll t = sumn - nsum;
                    b.push_back(t);
                    a.push_back(d - t);
                    nsum += t;
                }
                else
                {
                    a.push_back(d);
                }
                n /= 10;
            }
            for (ll i = a.size() - 1; i >= 0; i--)
            {
                cout << a[i];
            }
            cout << " ";
            for (ll i = b.size() - 1; i >= 0; i--)
            {
                cout << b[i];
            }
            cout << nn;
        }
        else
            cout << y << " " << x << nn;
    }
}

int main()
{
    // FIO;
    //    read;
    //    write;
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