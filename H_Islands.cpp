
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int n, k;

bool cmp(pii a, pii b)
{
    return a.first > b.first;
}

ll solve(vector<pii> v)
{
    sort(v.begin(), v.end(), cmp);

    ll ans = 0, letters = 0;

    int sz = v.size();

    for (int i = 0; i < sz; i++)
    {
        ll mn = min((ll)v[i].second, letters);
        letters -= mn;
        v[i].second -= mn;

        if (v[i].second > 0)
        {
            ll cnt = (v[i].second / k) + (v[i].second % k > 0);

            ans += (cnt * 2 * v[i].first);
            letters += cnt * k;
            letters -= v[i].second;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vector<pii> a, b;

    for (int i = 0; i < n; i++)
    {
        int x, y;

        cin >> x >> y;

        if (x > 0)
            a.push_back({x, y});
        else if (x < 0)
            b.push_back({abs(x), y});
    }

    ll ans = 0;

    ans += solve(a);
    // cout << ans << endl;
    ans += solve(b);

    cout << ans << endl;

    return 0;
}
