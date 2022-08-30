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
#define test        \
  long long int ct; \
  cin >> ct;        \
  while (ct--)
const double pi = acos(-1.0);
vector<vector<lld>> v;
vector<lld> low, et;
vector<bool> visit, used;
void dfs(lld node, lld parent, lld st)
{

  visit[node] = true;
  low[node] = et[node] = st;

  lld number_of_child = 0;

  for (lld i = 0; i < v[node].size(); i++)
  {

    lld child = v[node][i];

    if (!visit[child])
    {

      dfs(child, node, st + 1);

      low[node] = min(low[child], low[node]);

      if (low[child]>=et[node] && parent!= node )
      {
        used[node] = true;
      }
      number_of_child++;
    }
    else if(parent!=child)
    {
      low[node] = min(et[child], low[node]);
    }

    if(parent==node && number_of_child>1){
      used[node]=true;
    }
  }
}
void solve()
{
  lld n, m;
  cin >> n >> m;
  v.clear();
  v.resize(n + 1);
  low.clear();
  low.resize(n + 1);
  et.clear();
  et.resize(n + 1);
  visit.clear();
  visit.resize(n + 1, false);
  used.clear();
  used.resize(n + 2, false);

  lld x, y;
  for (lld i = 0; i < m; i++)
  {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 1, 1);
  lld ans = 0 ;
  for(lld i = 1;i<=n;i++ ){
    if (used[i])
      ans++;
  }
    cout << ans << endl; 
  
}

int main()
{
  cin.tie(NULL);
  // read;
  // write;
  ios_base::sync_with_stdio(false);
  lld t = 1;
  test
  {
    cout<<"Case "<<t++<<": ";
    solve();
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