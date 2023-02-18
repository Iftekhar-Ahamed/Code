
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pii pair<int, int>

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

using namespace std;

int main()
{
    int n, a, b, s;
    cin >> n >> a >> b >> s;
    int x = s - a - b;
    int y = n - 2;
    int u = x / y;
    int v;
    if (x % y != 0)
        v = (x / y) + 1;
    else
        v = x / y;

    if (u >= a and v <= b)
        cout << "YES" << endl;
    else
        cout << "N0" << endl;
}
