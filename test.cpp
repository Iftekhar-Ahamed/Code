#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define INF 100000000
#define abc "abcdefghijklmnopqrstuvwxyz"
#define ABC "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define PI 3.1415926535897932384626433832795
// define sort function
#define asort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define gsort(a) sort(a.begin(), a.end(), greater<int>())
#define issort(a) is_sorted(a.begin(), a.end())
#define areverse(a) reverse(a.begin(), a.end())
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// default define end
bool atik(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> ans;
    vector<pair<int, int>> data;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        x %= k;
        if (x == 0)
        {
            ans.push_back(i + 1);
        }
        else
        {
            data.push_back({x, i + 1});
        }
    }
    sort(data.begin(), data.end(), atik);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    for (auto i : data)
    {
        cout << i.second << " ";
    }
    cout << endl;
}
int main()
{
    Faster;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
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
* Be confident!!! who knows? may be your one step back to AC *
4. minus mod ans=(ans-k+mod)%mod;
*/
/* IF WA???
1. corner case! n=1?k=1? something about 0?
2. check code(avoid stupid mistake)
3. read the statement again(if there any missing point???)
4. check the idea(check all possible counter test case again!!!)
5. be calm,don't be panic!!!.(**this problem not going to decide your future**)
6. don't waste too much time. move to next problem
*/