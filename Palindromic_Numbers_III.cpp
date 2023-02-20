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
string anss;
ll len, mid;
bool ok = false, odd = false;
void go(ll ind, ll pos, string &ans, bool setZero)
{
    if (ind == len && !ok)
    {
        anss = ans;
        ok = true;
    }
    else if (!ok)
    {
        ll up = setZero ? 0 : ans[ind] - '0';

        if (ind <= mid)
        {
            if (mid == ind)
            {
                if (odd)
                {
                    pos = mid - 1;
                }
                else
                {
                    pos = mid;
                }
            }
            if (ind == 0)
                up = ans[ind] - '0';

            for (ll i = up; i <= 9 && !ok; i++)
            {
                ans[ind] = '0' + i;
                go(ind + 1, pos, ans, (up == i ? false : true) | setZero);
            }
        }
        else
        {
            ll need = ans[pos] - '0';

            if (need >= up)
            {
                ans[ind] = '0' + need;
                go(ind + 1, pos - 1, ans, setZero);
            }
            else
            {
                return;
            }
        }
    }
}
bool isPalindrome(ll n)
{
    string t = to_string(n);
    string x = t;
    reverse(x.begin(), x.end());
    return x == t;
}
string brute(ll n)
{
    for (ll i = n;; i++)
    {
        if (isPalindrome(i))
            return to_string(i);
    }
    return "";
}
void solve()
{
    ll n;
    cin >> n;
    string num = to_string(n + 1);

    len = num.size();
    mid = (len / 2);

    ok = false;

    if (len % 2)
    {
        odd = true;
    }
    else
    {
        odd = false;
        mid--;
    }
    anss.clear();

    go(0, -1, num, false);
    cout << anss << nn;
    // string y = brute(n + 1);
    // if (ans != y)

    //     cout << y << nn;
}

int main()
{
    FIO;
    //   read;
    //   write;
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