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

#define read freopen("0_input.txt","r",stdin)
#define write freopen("0_output.txt","w",stdout)
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define mXs 1000
#define test long long int ct;cin >> ct;while (ct--)
#define nn '\n'
const double pi = acos(-1.0);
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};
char direction[] = {'D', 'L', 'U', 'R'};
int rdRow[] = {1, 0, -1, 0, 1, 1, -1, -1};
int rdCol[] = {0, -1, 0, 1, 1, -1, -1, 1};

char g[mXs+3][mXs+3];
char visit[mXs+3][mXs+3];
lld n,m;
pair<lld,lld> bfs(lld i,lld j){
    visit[i][j]='#';
    queue<pair<lld,lld>>trace;
    trace.push({i,j});
    string t;
    while (!trace.empty())
    {
        lld u = trace.front().first,v = trace.front().second;

        for(lld i=0;i<4;i++){

            lld r = u+dRow[i] , c = v+dCol[i];

            if(r<n && r>=0 && c<m && c>=0 && g[r][c]!='#'){

                trace.push({r,c});

                visit[r][c]=direction[i];

                if(g[r][c]=='B'){
                    return {r,c};
                }

                g[r][c]='#';
            }
        }
        trace.pop();
    }
    return {-1,-1};
}

void solve(){
    lld si=-1,sj=-1;
    cin>>n>>m;
    for(lld i=0;i<n;i++){
        for(lld j=0;j<m;j++){
            cin>>g[i][j];
            visit[i][j]=false;
            if(g[i][j]=='A'){
                si = i;
                sj = j;
            }
        }
    }
    pair<lld,lld> ans = bfs(si,sj);

    if(ans.first==-1 && ans.second==-1){
        cout<<"NO"<<nn;
    }else{
        cout<<"YES\n";
        lld i = ans.first , j = ans.second,count=0;
        string s="";
        while (i!=si || j != sj)
        {
            if(visit[i][j]=='D'){
                i += rdRow[0];
                j += rdCol[0];
                s.push_back('U');
            }else if(visit[i][j]=='L'){
                i += rdRow[1];
                j += rdCol[1];
                s.push_back('R');
            }else if(visit[i][j]=='U'){
                i += rdRow[2];
                j += rdCol[2];
                s.push_back('D');
            }else{
                i += rdRow[3];
                j += rdCol[3];
                s.push_back('L');
            }
            count++;
        }
        reverse(s.begin(),s.end());
        cout<<s.size()<<nn<<s<<nn;
    }
}


int main()
{
    cin.tie(NULL);
    //read;
    //write;
    ios_base::sync_with_stdio(false);
    //test{
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