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

struct singleHashing
{
    ll base1, mod1, inv1;
    vector<ll> powerType1, invType1;
    singleHashing()
    {
        base1 = 1949313259;
        mod1 = 2091573227;
        precal();
    }
    ll bigMod(ll base, ll power, ll Mod)
    {
        if (power == 0)
            return 0;
        else if (power == 1)
            return base;
        else if (power % 2 == 0)
        {
            ll x = bigMod(base, power / 2, Mod) % Mod;
            return (x * x) % Mod;
        }
        else
        {
            ll x = bigMod(base, power - 1, Mod) % Mod;
            return (base * x) % Mod;
        }
    }
    void precal()
    {
        inv1 = bigMod(base1, mod1 - 2, mod1);
        powerType1.resize(1000002), invType1.resize(1000002);
        powerType1[0] = invType1[0] = 1;

        for (ll i = 1; i <= 1000000; i++)
        {
            powerType1[i] = (powerType1[i - 1] * base1) % mod1;
            invType1[i] = (invType1[i - 1] * inv1) % mod1;
        }
    }

    void calculateHashValue(string &s, vector<ll> &hash)
    {
        ll n = s.size();
        hash[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            hash[i] = (hash[i - 1] + ((s[i - 1] * powerType1[i - 1]) % mod1)) % mod1;
        }
    }

    ll GetSubstrHash(ll l, ll r, vector<ll> &prehash)
    {
        ll hash_val = 0;
        hash_val = (prehash[r + 1] - prehash[l]) * invType1[l] % mod1;

        if (hash_val < 0)
            hash_val += mod1;

        return hash_val;
    }
};
void manipulation(string &t)
{
    for (auto &i : t)
    {
        if (i <= 'z' && i >= 'a')
        {
            i -= 32;
        }
        else
        {
            i += 32;
        }
    }
}
void solve()
{
    string s, t;
    cin >> s;
    ll n = s.size();
    t = s;
    manipulation(t);

    vector<ll> hashS(s.size() + 1), hashT(s.size() + 1);
    singleHashing ob;
    ob.calculateHashValue(s, hashS);
    ob.calculateHashValue(t, hashT);
    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll ln = 0; ln < n; ln++)
        {
            ll l = i, r = i + ln, x, y;
            if (r < n)
                x = ob.GetSubstrHash(l, r, hashS);
            else
                break;
            l = r + 1;
            r = l + ln;
            if (r < n)
                y = ob.GetSubstrHash(l, r, hashT);
            else
                break;

            if (x == y)
                ans++;
        }
    }
    cout << ans << nn;
}

int main()
{
    FIO;
    read;
    // write;

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