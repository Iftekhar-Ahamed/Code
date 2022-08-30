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
#define mXs (lld)1e5
#define test          \
    long long int ct; \
    cin >> ct;        \
    while (ct--)
const double pi = acos(-1.0);
struct node
{
    lld zero = 0, one = 0, two = 0,count=0;
    void print(){
        cout<<this->zero<<" "<<this->one<<" "<<this->two<<" "<<this->count<<endl;
    }
} tree[4 * mXs];

void build_tree(lld node, lld b, lld e)
{
    if (b == e)
    {
        tree[node].zero = 1;
        tree[node].one = 0;
        tree[node].two = 0;
        tree[node].count = 0;
        return;
    }
    lld l = node * 2;
    lld r = l + 1;
    lld mid = (b + e) / 2;
    build_tree(l, b, mid);
    build_tree(r, mid + 1, e);

    tree[node].zero = tree[l].zero + tree[r].zero;
    tree[node].one = tree[l].one + tree[r].one;
    tree[node].two = tree[l].two + tree[r].two;
    tree[node].count = tree[l].count+tree[r].count;
}
void update(lld node, lld b, lld e, lld i, lld j)
{
    if (j>=e && i<=b)
    {
        //cout<<i<<" "<<j<<" "<<tree[node].count<<endl;
        lld count = tree[node].count + 1;
        tree[node].count = 0;

        lld n = (count)%3;
        for(lld i=0;i<n;i++){
            swap(tree[node].one, tree[node].zero);
            swap(tree[node].two, tree[node].zero);
        }

        lld t = tree[node].one+tree[node].two+tree[node].zero;
        if(t>1){
            tree[node*2].count+=count;
            tree[(node*2)+1].count+=count;
        }
        return;
    }
    if (i > e || j < b)
    {
        lld count = tree[node].count;
        tree[node].count = 0;

        lld n = (count)%3;
        for(lld i=0;i<n;i++){
            swap(tree[node].one, tree[node].zero);
            swap(tree[node].two, tree[node].zero);
        }

        lld t = tree[node].one+tree[node].two+tree[node].zero;
        if(t>1){
            tree[node*2].count+=count;
            tree[(node*2)+1].count+=count;
        }
        return;
    }

    lld l = node * 2;
    lld r = l + 1;
    lld mid = (b + e) / 2;

    

    tree[l].count += tree[node].count;
    tree[r].count += tree[node].count;
    tree[node].count=0;

    update(l, b, mid,i,j);
    update(r, mid + 1, e,i,j);

    tree[node].zero = tree[l].zero + tree[r].zero;
    tree[node].one = tree[l].one + tree[r].one;
    tree[node].two = tree[l].two + tree[r].two;

}
node query(lld node, lld b, lld e, lld i, lld j,lld count)
{

    if (i <= b && j >= e)
    {
        
        struct node ob = tree[node];
        count+=tree[node].count;
        
        //cout<<b<<"-"<<e<<"-"<<count<<endl;

        lld n = count%3;

        for(lld i=0;i<n;i++){
            swap(ob.one, ob.zero);
            swap(ob.two, ob.zero);
        }

        return ob;
    }

    if (i > e || j < b)
    {
        struct node ob;
        return ob;
    }

    lld l = node * 2;
    lld r = l + 1;
    lld mid = (b + e) / 2;

    struct node left = query(l, b, mid, i, j, count + tree[node].count);
    struct node right = query(r, mid + 1, e, i, j, count + tree[node].count);

    struct node ob;
    ob.one = left.one + right.one;
    ob.two = left.two + right.two;
    ob.zero = left.zero + right.zero;

    //left.print();
    //right.print();

    //ob.print();

    return ob;
}
void check()
{

    for (lld i = 1; i <= 25; i++)
    {
        cout << i << " " << tree[i].zero << " " << tree[i].one << " " << tree[i].two << " " << tree[i].count << endl;
    }
}
void solve()
{
    lld n, q;
    cin >> n >> q;
    build_tree(1, 1, n);
    lld i, j, t;
    // check();
    while (q--)
    {
        cin >> t >> i >> j;
        if (t == 1)
        {
            //cout<<i+1<<" "<<j+1<<endl;
            cout << query(1, 1, n, i + 1, j + 1, 0).zero << endl;
        }
        else
        {
            update(1, 1, n, i + 1, j + 1);
            //cout<<"AFTER UPDATE : "<<i+1<<" "<<j+1<<endl;
            //check();
        }
        // check();
    }
}

int main()
{
    cin.tie(NULL);
    // read;
    // write;
    ios_base::sync_with_stdio(false);
    lld i = 1;
    string s;

    test
    {
        cout<<"Case "<<i++<<":"<<endl;
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