#include <bits/stdc++.h>
using namespace std;

typedef struct p{
    int station;
    int index;
}Pair;

int findFirstOccurrence(Pair* pair, int n, int target){

    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high){
        int mid = (low + high)/2;
        if (target == pair[mid].station ) result = mid, high = mid - 1;
        else if (target < pair[mid].station ) high = mid - 1;
        else low = mid + 1;
    }

    return result;
}

int findLastOccurrence(Pair* pair, int n, int target){

    int low = 0, high = n - 1;
    int result = -1;
 
    while (low <= high){
        int mid = (low + high)/2;
        if (target == pair[mid].station)  result = mid, low = mid + 1;
        else if (target < pair[mid].station)  high = mid - 1;
        else  low = mid + 1;
    }

    return result;
}


int compare(const void* a, const void* b){
    return (*(Pair*)a).station - (*(Pair*)b).station;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    //freopen("0_input.txt","r",stdin);
    int t; cin >> t;
    while (t--){

        int n, k; cin >> n >> k;
        
        Pair* pair = (Pair*) calloc(n, sizeof(Pair));
        for ( int i = 0; i < n; i++ ) cin >> pair[i].station, pair[i].index = i;
        qsort(pair, n, sizeof(Pair), compare );


        for ( int i = 0; i < k; i++ ){
            int a, b; cin >> a >> b;
            int initial = findFirstOccurrence( pair, n, a );
            int final   = findLastOccurrence ( pair, n, b );

            if ( initial < 0 || final < 0 ) cout << "NO" << '\n';
            else if ( pair[initial].index < pair[final].index ) cout << "YES" << '\n';
            else cout << "NO" << '\n';

        }

        free(pair);

    }
    

    return 0;
}




















/***
**      Bismillahir Rahmanir Rahim
**              ALLAHU AKBAR
**
**     Author: Iftekhar Ahamed Siddiquee
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
/*
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
#include <unordered_map>
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
#define mXs 1e6
#define test long long int ct;cin >> ct;while (ct--)
const double pi = acos(-1.0);
int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dCol[] = {0, 1, 0, -1, 1, -1, -1, 1};


void solve(){
    lld n,k;
    cin>>n>>k;
    unordered_map<lld,pair<lld,lld>>mp;
    lld x;
    for(lld i=1;i<=n;i++){
        cin>>x;
        if(mp[x].first==0){
            mp[x].first=i;
            mp[x].second=i;
        }else{
            mp[x].second=i;
        }
    }
    lld a,b;
    while (k--)
    {
        cin>>a>>b;
        if(mp.find(a)==mp.end() || mp.find(b)==mp.end()){
            cout<<"NO\n";
        }else{
            if(mp[a].first<mp[b].second){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    

}


int main()
{
    cin.tie(NULL);
    //read;
    //write;
    ios_base::sync_with_stdio(false);
    test{
      solve();
    }
    return 0;
}*/
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