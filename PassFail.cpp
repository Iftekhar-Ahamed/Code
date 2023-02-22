#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, i;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        string x, y;
        ll z;
        cin >> x >> y >> z;

        if (x[0] == 'A' || y[0] == 'A')
            cout << "Case " << i + 1 << ": FaiL" << endl;
        else
        {
            if (x.size() == 2 && y.size() == 2)
            {
                ll p = ((x[0] - 48) * 10) + (x[1] - 48);
                ll q = ((y[0] - 48) * 10) + (y[1] - 48);

                if ((p + q + z) >= 40)
                    cout << "Case " << i + 1 << ": PasS" << endl;
                else if ((p + q + z) < 40)
                    cout << "Case " << i + 1 << ": FaiL" << endl;
            }
            else if (x.size() == 2 && y.size() == 1)
            {
                ll p = ((x[0] - 48) * 10) + (x[1] - 48);
                ll q = ((y[0] - 48) * 10);

                if ((p + q + z) >= 40)
                    cout << "Case " << i + 1 << ": PasS" << endl;
                else if ((p + q + z) < 40)
                    cout << "Case " << i + 1 << ": FaiL" << endl;
            }
            else if (x.size() == 1 && y.size() == 2)
            {
                ll p = ((x[0] - 48) * 10);
                ll q = ((y[0] - 48) * 10) + (y[1] - 48);

                if ((p + q + z) >= 40)
                    cout << "Case " << i + 1 << ": PasS" << endl;
                else if ((p + q + z) < 40)
                    cout << "Case " << i + 1 << ": FaiL" << endl;
            }
            else if (x.size() == 1 && y.size() == 1)
            {
                ll p = ((x[0] - 48) * 10);
                ll q = ((y[0] - 48) * 10);

                if ((p + q + z) >= 40)
                    cout << "Case " << i + 1 << ": PasS" << endl;
                else if ((p + q + z) < 40)
                    cout << "Case " << i + 1 << ": FaiL" << endl;
            }
        }
    }

    return 0;
}