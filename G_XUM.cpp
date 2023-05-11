#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    double x, y, d;
    cin >> x >> y >> d;
    if (x == 0 and y == 0)
    {
        cout << 0 << ' ' << 0 << '\n';
        return 0;
    }
    double tn = 0;
    if (x != 0)
        tn = atan(y / x);
    if (x == 0 and y >= 0)
    {
        tn += (90 * pi) / 180;
    }
    else if (x <= 0 and y >= 0)
    {
        tn += (180 * pi) / 180;
    }
    else if (x >= 0 and y < 0)
    {
        tn += (360 * pi) / 180;
    }
    else if (x < 0 and y < 0)
    {
        tn += (270 * pi) / 180;
    }

    d = tn + ((d * pi) / 180);
    // cout<<(tn * 180)/pi<<' '<<(d * 180)/pi<<'\n';
    double r = sqrt((x * x) + (y * y));
    double x1 = r * cos(d);
    double y1 = r * sin(d);

    cout << setprecision(12) << fixed << x1 << ' ' << y1 << '\n';
}
