#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, char> a[4];
    for (int c = 0; c < 4; c++)
    {
        string s;
        cin >> s;
        a[c] = {s.size() - 2, 'A' + c};
    }
    sort(a, a + 4);
    if (a[0].first * 2 <= a[1].first && a[3].first >= a[2].first * 2)
    {
        cout << "C" << endl;
    }
    else if (a[0].first * 2 <= a[1].first)
    {
        cout << (char)(a[0].second) << endl;
    }
    else if (a[3].first >= a[2].first * 2)
    {
        cout << (char)(a[3].second) << endl;
    }
    else
    {
        cout << "C" << endl;
    }
    return 0;
}