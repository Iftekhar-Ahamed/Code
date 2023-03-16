#include <bits/stdc++.h>
using namespace std;
int ty = 0;
string go = "";
int cnt = 0;
string left_fac(string temp, int x)
{
    string s[x + 2];
    for (int i = 0; i < x; i++)
        s[i] = "";
    int f;
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] != ' ' && temp[i] != '-' && temp[i] != '>' && temp[i] != '$' && temp[i] != '|')
        {
            f = i;
            break;
        }
        // cout<<ok<<nn;
    }
    int j = 0;
    for (int i = f; i < temp.size(); i++)
    {
        if (temp[i] == '|')
        {
            j++;
        }
        else if (temp[i] != ' ')
        {
            s[j] += temp[i];
        }
    }
    string ex = s[0];
    f = 0;
    for (int i = 0; i < s[0].size(); i++)
    {
        for (int k = 1; k <= j; k++)
        {
            if (s[k].substr(0, ex.size()) == ex)
            {
                ty++;
                f = 1;
                break;
            }
        }
        if (f)
            break;
        ex.erase(ex.size() - 1, 1);
    }
    if (f == 0)
    {
        if (ty == 0)
            cout << "There is no left recursion" << endl;
        return "NO";
    }
    if (cnt == 0)
        cout << go << "-> " << ex;
    else
        cout << go << cnt << "-> " << ex;
    cout << go << ++cnt;
    for (int k = 1; k <= j; k++)
    {
        if (s[k].substr(0, ex.size()) != ex)
        {
            cout << "|" << s[k] << go << (cnt - 1);
        }
    }
    cout << endl;
    string tr = "";
    for (int i = 0; i <= j; i++)
    {
        int siz = s[i].size();
        string ss = s[i];
        if (s[i].substr(0, ex.size()) != ex)
            continue;
        for (int k = 0; k < siz; k++)
        {
            if (ex[k] != ss[k])
                break;
            else
                s[i].erase(0, 1);
        }
        if (tr.size() != 0)
            tr += '|';

        if (s[i].size() == 0)
            tr += '$';
        else
            tr += s[i];
        tr += "A" + to_string(cnt);
    }
    return tr;
}
int main()
{
    freopen("leftfact.txt", "r", stdin);
    string g;
    getline(cin, g);
    go += g[0];
    while (1)
    {
        string s = left_fac(g, g.size());
        if (s == "NO")
            break;
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ' && s[i] != '-' && s[i] != '>' && s[i] != '$' && s[i] != '|')
            {
                u++;
                break;
            }
        }
        if (u == 0)
            break;
        cout << go << cnt << "-> " << s << endl;
        g.clear();
        g = s;
    }
}
