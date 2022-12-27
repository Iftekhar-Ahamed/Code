#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("0_input.txt", "r", stdin);
    int arrival_time;
    int burst_time;
    priority_queue<pair<int, int>> pq;
    int n;
    cin >> n;
    vector<tuple<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrival_time >> burst_time;
        v[i] = {arrival_time,
                burst_time};
    }
    int i = 0, t = 0;
    vector<pair<int, int>> ans;
    while (!pq.empty() || i < n)
    {
        auto [at, bt] = v[i];
        if (at == t)
        {
            if (bt != 0 && i < n)
            {
                pq.push({-bt, i});
                i++;
            }
        }

        if (!pq.empty())
        {

            auto [btt, ii] = pq.top();
            pq.pop();
            btt *= -1;
            cout << "Time :" << t << " TASK :" << ii + 1 << " BRUST TIME = " << btt << endl;
            btt--;
            if (ans.size() != 0)
            {
                if (ans[ans.size() - 1].first != ii)
                {
                    ans.push_back({ii, btt});
                }
                else
                {
                    ans[ans.size() - 1].second--;
                }
            }
            else
            {
                ans.push_back({ii, btt});
            }

            if (btt != 0)
            {
                pq.push({-btt, ii});
            }
        }
        else
        {
            cout << "Time :" << t << " NO TASK" << endl;
        }
        t++;
    }
    cout << "FINAL :" << endl;
    for (auto [a, b] : ans)
    {
        cout << "TASK :" << a + 1 << " BURST TIME  RE :" << b << endl;
    }
}