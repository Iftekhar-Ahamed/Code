/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define read freopen("0_input.txt", "r", stdin)
#define write freopen("0_output.txt", "w", stdout)
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long int
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1e6
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
void prime(vector<vector<lld>> &pf)
{
    vector<lld> p;
    vector<bool> vist(1001, false);
    p.push_back(2);
    for (lld i = 4; i < 1001; i += 2)
    {
        vist[i] = true;
    }
    for (lld i = 3; i < 1001; i += 2)
    {
        if (!vist[i])
        {
            p.push_back(i);
            for (lld j = i * i; j < 1001; j += i)
            {
                vist[j] = true;
            }
        }
    }

    for (lld i = 2; i < 1001; i++)
    {
        lld t = i;
        for (lld j = 0; j < p.size(); j++)
        {
            if (t % p[j] == 0)
            {
                pf[i].push_back(p[j]);
            }
            while (t % p[j] == 0)
            {
                t /= p[j];
            }
        }
    }
}
lld bfs(lld n, lld m, vector<vector<lld>> &pf)
{
    queue<pair<lld,lld>> q;
    q.push({n,0});
    map<lld, bool> visit;
    visit[n] = true;
    if(n==m)return 0;
    while (!q.empty())
    {
        lld number = q.front().first;
        lld step = q.front().second;
        for (lld i = 0; i < pf[number].size(); i++)
        {

            if (pf[number][i]!=number && number + pf[number][i] <= m && visit[number + pf[number][i]]==false)
            {
                if (number + pf[number][i] == m)
                {
                    return step+1;
                }
                else
                {
                    q.push({number + pf[number][i],step+1});
                    visit[number + pf[number][i]]=true;
                }
            }
        }
        q.pop();
    }
    return -1;
}
void solve(vector<vector<lld>> &pf)
{
    lld n, m;
    cin >> n >> m;
    cout << bfs(n, m, pf) << endl;
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    vector<vector<lld>> pf(1001);
    prime(pf);
    lld i = 1;
    test
    {
        cout << "Case " << i++ << ": ";
        solve(pf);
    }
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