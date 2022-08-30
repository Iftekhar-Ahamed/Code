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
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
class process
{
public:
    lld at, bt, serial, p, wt, ct;
    process()
    {
        at = bt = serial = p = wt = ct = 0;
    }
};

void solve()
{
    lld n, at, bt, p;
    //cout << "Enter process number :";
    cin >> n;
    process ob[n + 1];
    priority_queue<pair<lld,pair<lld,lld>>> cpu,tcpu;

    for (lld i = 1; i <= n; i++)
    {
        cin >> ob[i].at >> ob[i].bt >> ob[i].p;
        ob[i].serial = i;
    }
    lld time = 0, pos = 2;
    pair<lld, pair<lld,lld>> temp={ob[1].p,{-ob[1].at,ob[1].serial}};
    cpu.push(temp);
    double avgwt;
    while ((!cpu.empty())||(pos<n))
    {

        if(!cpu.empty()){
            temp=cpu.top();
        }

        if (!cpu.empty())
        {
            ob[temp.second.second].bt--;
            tcpu = cpu;
            tcpu.pop();
            while (!tcpu.empty())
            {
                ob[tcpu.top().second.second].wt++;
                tcpu.pop();
            }
            if (ob[temp.second.second].bt == 0)
            {
                ob[temp.second.second].ct = time+1;
                cpu.pop();
            }
        }

        time++;

        if (ob[pos].at==time && pos<=n){
            temp={ob[pos].p,{-ob[pos].at,ob[pos].serial}};
            cpu.push(temp);
            pos++;
        }
    }
    

    for(lld i=1;i<=n;i++){
        avgwt+=(ob[i].wt);
        cout<<"Process Number\t"<<i<<"\tComplete time\t"<<ob[i].ct<<"\tWaiting time\t"<<ob[i].wt<<"\tPrority\t"<<ob[i].p<<endl;
    }

    cout<<"Averge waiting time : "<<(avgwt/(n*1.0))<<endl;
}

int main()
{
    cin.tie(NULL);
     read;
    // write;
    ios_base::sync_with_stdio(false);
    //test
    //{
        solve();
    //}
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