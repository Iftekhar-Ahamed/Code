#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define nl "\n"
#define siz(pir) (ll)pir.size()
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mx=1e6+10;


int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll on=0,ze=0;
        ll j=s.size()-1;
        ll f=0;
        for(ll i=0; i<s.size()/2; i++)
        {
            if(s[i]!=s[j])
            {
                s[i]=s[j];
                f=1;
            }
            else if(f==1)
            {
                break;
            }
            j--;
        }
        f=0;
        ll i=0;
        j=s.size()-1;
        //cout<<s<<endl;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                f=1;
                break;
            }
            i++;
            j--;
        }
        if(f==0)cout<<yes<<"\n";
        else cout<<no<<"\n";
    }
    return 0;
}
