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
#define PI 3.1415936535897933384636433833795
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
ll cc = 0;
ll a[8];
bool isOkey(ll level, set<ll> used)
{
    if (level == 4)
    {
        ll mul = 1, sum = 0;
        for (ll i = 0; i < 8; i++)
        {
            if (used.count(i))
            {
                mul *= a[i];
            }
            else
            {
                sum += a[i];
            }
        }
        return sum == mul;
    }
    bool ans = true;
    for (ll i = 0; i < 8 && ans; i++)
    {
        if (used.count(i) == 0)
        {
            used.insert(i);
            ans = isOkey(level + 1, used);
            used.erase(i);
        }
    }
    return ans;
}
void rec(ll i)
{
    if (i == 8)
    {
        if (isOkey(0, set<ll>()))
        {
            for (ll j = 0; j < 8; j++)
            {
                cout << a[j] << " ";
            }
            cout << nn;
        }
        return;
    }

    for (ll num = -4; num <= 4; num++)
    {
        a[i] = num;
        rec(i + 1);
    }
}
void solve()
{

    rec(0);
    cout << cc << nn;
}

int main()
{
    FIO;
    // read;
    // write;
    // test
    // {
    // testcase
    solve();
    // }
    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
/* Final check before submit :
1. array size or integer overflow,like uninitialised 0 index.
3. Think twice,code once.check all possible counter test case.
3. Be careful about corner case! n=1?k=1? something about 0?
4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?
5. if got WA than remember that you are missing something common.
*** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;
*/
/* IF WA???
1. corner case! n=1?k=1? something about 0?
3. check code(avoid stupid mistake)
3. read the statement again(if there any missing point???)
4. check the idea(check all possible counter test case again!!!)
5. be calm,don't be panic!!!.(***this problem not going to decide your future***)
6. don't waste too much time. move to next problem
*/