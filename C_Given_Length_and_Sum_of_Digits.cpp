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
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;

void small(ll m, ll sum)
{
    ll need = ceil(sum * 1.0 / 9.0);
    if (m == need)
    {
        vector<ll> v;
        for (ll i = 9; i >= 1; i--)
        {
            while (sum >= i)
            {
                v.push_back(i);
                sum -= i;
            }
        }
        sort(v.begin(), v.end());
        for (auto i : v)
        {
            cout << i;
        }
        cout << " ";
        for (auto i = v.rbegin(); i != v.rend(); i++)
        {
            cout << *i;
        }
        cout << nn;
    }
    else
    {
        vector<ll> v;
        v.push_back(1);
        ll x = sum;
        sum -= 1;
        for (ll i = 9; i >= 1; i--)
        {
            while (sum >= i)
            {
                v.push_back(i);
                sum -= i;
            }
        }
        sort(v.begin(), v.end());
        ll zero = m - v.size();
        cout << v[0];
        for (ll i = 1; i <= zero; i++)
        {
            cout << 0;
        }
        for (ll i = 1; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << " ";
        sum = x;
        for (ll i = 9; i >= 0 && m; i--)
        {
            i = max(i, 0ll);
            while (sum >= i && m)
            {
                cout << i;
                m--;
                sum -= i;
            }
        }
        cout << nn;
    }
}

void solve()
{
    ll m, s;
    cin >> m >> s;
    if (m == 1 && s <= 9)
    {
        cout << s << " " << s << nn;
    }
    else if (m * 9 < s || s == 0)
    {
        cout << -1 << " " << -1 << nn;
    }
    else
    {
        small(m, s);
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