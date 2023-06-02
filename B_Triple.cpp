#include <bits/stdc++.h>
using namespace std;
#define nn '\n'
#define tt '\t'
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int m;
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            arr.push_back(m);
        }
        sort(arr.begin(), arr.end());

        int valu;
        int cc = 1, pos = -1;

        for (int i = 1; i < n; i++)
        {

            if (arr[i] == arr[i - 1])
            {
                cc++;
                valu = arr[i];
            }
            else
            {
                cc = 1;
            }
            if (cc >= 3)
            {
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            cout << arr[pos] << endl;
        }
        else
        {
            cout << -1 << nn;
        }
    }
    return 0;
}