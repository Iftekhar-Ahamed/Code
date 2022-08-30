// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

// Driver code
int main()
{
    ordered_set s;
    int n,x,y;
    cin>>n;
    int a[n];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        cin>>x>>y;
        s.insert({x,y});
        a[s.order_of_key({x,y})]++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
