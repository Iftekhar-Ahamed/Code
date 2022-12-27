/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;

#define FIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define read freopen("fastfollow.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
#define ll long long
#define INF (ll)1e16
#define nn "\n"
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define test   \
    ll ct;     \
    cin >> ct; \
    while (ct--)
#define Dpos(n) fixed << setprecision(n)
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mXs = 1e6;
map<string, vector<string>> modify(vector<string> g)
{
    map<string, vector<string>> gram;
    for (auto i : g)
    {
        stringstream ss(i);
        string t, gar, rule;
        ss >> t >> gar;
        while (ss >> rule)
        {
            if (rule != "|")
                gram[t].push_back(rule);
        }
    }
    return gram;
}
bool isReady(vector<string> v, map<string, set<string>> ans)
{
    for (auto i : v)
    {
        string val = "";
        if (i.size() >= 2 && ((i[1] == '`') || (i[1] == 'p' && i[0] == 'e')))
        {
            val += i[0];
            val += i[1];
        }
        else
        {
            val += i[0];
        }

        if ((val[0] > 'Z' || val[0] < 'A') || ans[val].size() != 0)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool isReady(string key, map<string, vector<string>> gram, map<string, set<string>> ans, map<string, set<string>> first)
{
    for (auto i : gram)
    {
        for (auto j : i.second)
        {
            if (j.find(key) != string::npos)
            {
                ll pos = j.find(key);
                pos += key.size();
                if (pos + 1 == j.size() && ans[i.first].size() != 0)
                {
                    continue;
                }
                else if (pos + 1 == j.size() && ans[i.first].size() == 0)
                {
                    return false;
                }
            }
        }
    }
}
void calculateFirst(string key, vector<string> v, map<string, set<string>> &ans)
{
    for (auto i : v)
    {
        string val = "";
        if (i.size() >= 2 && ((i[1] == '`') || (i[1] == 'p' && i[0] == 'e')))
        {
            val += i[0];
            val += i[1];
        }
        else
        {
            val += i[0];
        }

        if (val[0] > 'Z' || val[0] < 'A')
        {
            ans[key].insert(val);
        }
        else
        {
            ans[key].insert(ans[val].begin(), ans[val].end());
        }
    }
}
map<string, set<string>> First(vector<string> g)
{
    map<string, vector<string>> gram = modify(g);
    map<string, set<string>> firstOfGram;

    ll c = 0;
    while (c != gram.size())
    {
        for (auto i : gram)
        {
            if (isReady(i.second, firstOfGram) && firstOfGram[i.first].size() == 0)
            {
                calculateFirst(i.first, i.second, firstOfGram);
                c++;
            }
        }
    }

    for (auto i : firstOfGram)
    {
        cout << i.first << " : { ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << "}" << nn;
    }
    return firstOfGram;
}
vector<string> findOcc(string key, map<string, vector<string>> gram)
{
    vector<string> v;
    for (auto i : gram)
    {
        for (auto j : i.second)
        {
            if (j.find(key) != string::npos)
            {
                ll pos = j.find(key) + key.size(), n = j.size();
                if (pos < n && (j[pos] > 'Z' || j[pos] < 'A'))
                {
                    string t = "";
                    t += j[pos];
                    v.push_back(t);
                }
                else if (pos < n)
                {
                }
            }
        }
    }
}
map<string, set<string>> Follow(vector<string> g, map<string, set<string>> first)
{
    map<string, vector<string>> gram = modify(g);
    map<string, set<string>> followOfGram;

    ll c = 0;
    while (c != gram.size())
    {

        for (auto i : gram)
        {
            set<string> oderlist;
            string key = i.first;
        }
    }

    return followOfGram;
}
void solve(vector<string> g)
{
    map<string, set<string>> firstOfg = First(g);
}
int main()
{
    read;
    // write;
    vector<string> g;
    string input;
    while (getline(cin, input) && input != "no")
    {
        g.push_back(input);
    }
    solve(g);

    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
/* Final check before submit :
1. array size or integer overflow,like uninitialised 0 index.
2. Think twice,code once.check all possible counter test case.
3. Be careful about corner case! n=1?k=1? something about 0?
4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?
5. if got WA than remember that you are missing something common.
*** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;
*/
/* IF WA???
1. corner case! n=1?k=1? something about 0?
2. check code(avoid stupid mistake)
3. read the statement again(if there any missing point???)
4. check the idea(check all possible counter test case again!!!)
5. be calm,don't be panic!!!.(***this problem not going to decide your future***)
6. don't waste too much time. move to next problem
*/