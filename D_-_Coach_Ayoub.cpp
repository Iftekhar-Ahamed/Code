
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
    if (n == 1)
    {
        if (a == b && a == s)
        {
            cout << "YES" << endl;
            return 0;
        }
        else
        {
            cout << "NO" << endl;
        }
        return 0;
    }
    if (a == b)
    {
        s -= a;
        n--;
    }
    else
    {
        s -= (a + b);
        n -= 2;
    }
    if (n == 0)
    {
        if (s == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return 0;
    }

    int u = s / n;

    if (u >= a && u <= b)
    {

        if (s % n == 0)
        {
            cout << "YES" << endl;
        }
        else if (u + 1 <= b)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}
