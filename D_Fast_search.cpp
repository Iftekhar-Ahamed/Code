/*********************************************************************
**                 Bismillahir Rahmanir Rahim                       **
**                       ALLAHU AKBAR                               **
**                                                                  **
**     Author: Miraz Hossain Shahin                                 **
**     Bangladesh University of Business and Technology,(BUBT)      **
**     Dept. of CSE.                                                **
*********************************************************************/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define miraz()                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define ld long long double
#define str string
#define nn '\n'
#define vec vector<ll>

#define yes cout << "YES\n"
#define no cout << "NO\n"

#define asort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define gsort(a) sort(v.begin(), v.end(), greater<int>())
#define sp " "

using namespace std;
/*
ll Lower_Bound(vec &v, ll q)
{
    ll a = 0, b = v.size() - 1, ans = 0;
    while (a < b && a > -1)
    {
        ll mid = (a + b) / 2;
        if (v[mid] < q)
        {
            a = mid + 1;
        }
        else
        {
            ans = mid;
            if (v[mid] == q)
            {
                a = mid - 1;
            }
            else
            {
                b = mid - 1;
            }
        }
    }
    return ans;
}
ll Upper_Bound(vec &v, ll r)

{
    ll a = 0, b = v.size() - 1, ans = 0;
    while (a < b)
    {
        ll mid = (a + b) / 2;
        if (v[mid] <= r)
        {
            ans = mid;
            a = mid + 1;
        }
        else
        {
            b = mid - 1;
        }
    }
    return ans;
}
*/
ll Lower_Bound(vec &v, ll q)
{
    ll a = 0, b = v.size() - 1;
    while (b - a > 1)
    {
        ll mid = (a + b) / 2;
        if (v[mid] < q)
        {
            a = mid + 1;
        }
        else
        {
            b = mid;
        }
    }
    if (v[a] >= q)
    {
        return a;
    }
    if (v[b] >= q)
    {
        return b;
    }
}
ll Upper_Bound(vec &v, ll r)
{
    ll a = 0, b = v.size() - 1;
    while (b - a > 1)
    {
        ll mid = (a + b) / 2;
        if (v[mid] <= r)
        {
            a = mid + 1;
        }
        else
        {
            b = mid;
        }
    }
    if (v[a] > r)
    {
        return a;
    }
    if (v[b] > r)
    {
        return b;
    }
}
void result()
{
    ll n;
    cin >> n;
    vec v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    asort(v);
    ll k;
    cin >> k;
    while (k--)
    {
        ll l, r;
        cin >> l >> r;
        ll xlwrbound = Lower_Bound(v, l);
        ll yuprbound = Upper_Bound(v, r);
        auto it = upper_bound(v.begin(), v.end(), r);
        auto itr = lower_bound(v.begin(), v.end(), l);
        cout << it - itr << " ";
    }
    cout << nn;
}
int main()
{

    miraz();
    //    ll t;
    //    cin>>t;
    //
    //    while(t--)
    //    {
    result();
    //    }

    return 0;
}

/********************************************************************
**    Do something great...                                        **
**                                                                 **
**    Never loss your hope,Allah is the best planner.....          **
**                                                                 **
**    Believe in Allah,he will solute your all problem.....        **
********************************************************************/
