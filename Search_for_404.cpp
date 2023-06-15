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

#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test                 \
    ll ct;                   \
    cin >> ct, cin.ignore(); \
    for (ll i = 1; i <= ct; i++)
#define testcase cout << "Case " << i << ": ";
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll mXs = 1e6;
ll cal(ll N, string &S, vector<vector<ll>> &dp)
{
    for (int i = 1; i <= N; i++)
    {
        if (S[i - 1] == '*')
        {
            dp[i][0] = (2 * dp[i - 1][0]) % MOD;
        }
        else if (S[i - 1] == '4')
        {
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }
        else if (S[i - 1] == '0')
        {
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        }

        dp[i][3] = (2 * dp[i - 1][3]) % MOD;
    }
    return dp[N][3];
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> v(n + 1, vector<ll>(4, 0));
    v[0][0] = 1;
    cout << cal(n, s, v) << nn;
}

int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(NULL), ios_base::sync_with_stdio(false);
#endif
    // read;
    // write;
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