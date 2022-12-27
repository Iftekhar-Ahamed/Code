//
// 	problem: D. Problem with Random Tests
// 	created: 2022-10-17 22:35:26

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
bool change = false;
string cmp(string &s1, string &s2)
{
    // cout << s1 << " " << s2 << endl;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '1' && s2[i] == '0')
        {
            return s1;
        }
        if (s1[i] == '0' && s2[i] == '1')
        {
            change = true;
            return s2;
        }
    }
    return s1;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (s.find('1') == string::npos)
    {
        cout << 0 << endl;
        return;
    }

    int i = 0;
    while (s[i] != '1')
        i++;
    s = s.substr(i);
    string ans = s;

    vector<int> ones;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            ones.push_back(i);
        }
    }
    change = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            for (auto pos : ones)
            {
                if (pos > i)
                    continue;
                // cout << pos << " " << i << endl;
                string cur = s;
                for (int j = pos; j < n && i + j - pos < n; j++)
                {
                    if (s[j] == '1')
                    {
                        cur[i + j - pos] = s[j];
                    }
                }

                ans = cmp(ans, cur);
            }
            if (change)
                break;
        }
    }
    /*
    i: 3
    invalid pos:
    */
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _tst = 1;
    // cin >> _tst;
    while (_tst--)
        solve();
}
/*
 */