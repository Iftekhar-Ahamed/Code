/*********************************************************************
**                Bismillahir Rahmanir Rahim                        **
**                                                                  **
**                                                                  **
**     Author: MD. ARIF KHAN                                        **
**     Bangladesh University of Business and Technology,(BUBT)      **
**     Department of Computer Science And Engineering               **
*********************************************************************/
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define sp " "
#define asort(a) sort(a.begin(), a.end())
#define code()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
void solve()
{
    ll x;
    cin >> x;
    string a, b;
    cin.ignore();
    getline(cin, a);
    getline(cin, b);

    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] == 'G')
        {
            a[i] = 'B';
        }
    }
    for (ll i = 0; i < b.size(); i++)
    {
        if (b[i] == 'G')
        {
            b[i] = 'B';
        }
    }
    if (a == b)
    {
        yes
    }
    else
    {
        no
    }
}
int main()
{
    code();
    ll test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
