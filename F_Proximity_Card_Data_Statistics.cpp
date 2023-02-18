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
string datetime(string &a)
{
    string date;
    for (auto i : a)
    {
        if (i == '#')
        {
            reverse(date.begin(), date.end());
        }
        else
            date.push_back(i);
    }
    return date;
}
string yearf(string &a)
{
    string x;
    for (ll i = 6; i <= 9; i++)
    {
        x.push_back(a[i]);
    }
    return x;
}

void solve()
{
    map<string, pair<string, string>> mp;
    map<string, string> t;
    ll n;
    cin >> n;
    set<pair<string, ll>> bg, year;

    for (ll i = 0; i < n; i++)
    {
        string time, email, blood, year;
        cin >> time >> email >> year >> blood;
        year = yearf(year);
        string now = datetime(time);
        if (t[email] == "")
        {
            mp[email].first = blood;
            mp[email].second = year;
            t[email] = now;
        }
        else
        {

            if (t[email] <= now)
            {
                t[email] = now;
                mp[email] = {blood, year};
            }
        }
    }

    map<string, ll> x, yy;

    for (auto i : mp)
    {
        x[i.second.first]++;
        yy[i.second.second]++;
    }

    cout << "A+"
         << " " << x["A+"] << nn;
    cout << "A-"
         << " " << x["A-"] << nn;
    cout << "AB+"
         << " " << x["AB+"] << nn;
    cout << "AB-"
         << " " << x["AB-"] << nn;
    cout << "B+"
         << " " << x["B+"] << nn;
    cout << "B-"
         << " " << x["B-"] << nn;
    cout << "O+"
         << " " << x["O+"] << nn;
    cout << "O-"
         << " " << x["O-"] << nn;

    for (auto i : yy)
    {
        cout << i.first << " " << i.second << nn;
    }
}

int main()
{
    FIO;
    // read;
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