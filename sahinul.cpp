#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxn=2e4+10;
vector<ll>g[mxn+10];
set<pair<ll,ll>>bridge;
ll Time=0,Start[mxn+10],End[mxn+10],low[mxn+10],vi[mxn+10],f=0;
ll arti[mxn+10];
void dfs(ll u,ll pa=-1)
{
    vi[u]=1;
    Start[u]=++Time;
    low[u]=Start[u];
    ll no_of_child=0;
    for(auto v:g[u])
    {
        if(vi[v]==0)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=Start[u]&&pa!=-1)
            {
                arti[u]=1;
            }
            no_of_child++;
        }
        else if(v!=pa)
        {
            low[u]=min(low[u],Start[v]);
        }
        if(pa==-1&&no_of_child>1)
            arti[u]=1;
    }
    End[u]=Time;
}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m,u,v;
        cin>>n>>m;
        for(ll i=0;i<m;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(ll i=1; i<=n; i++)
        {
            if(!vi[i])
            {
                Time=0;
                dfs(i);
            }
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(arti[i])cnt++;
        }
        cout<<"Case "<<tt++<<": "<<cnt<<endl;
        for(ll i=0; i<=n+5; i++)
        {
            g[i].clear();
            vi[i]=0;
            low[i]=0;
            End[i]=0;
            Start[i]=0;
            arti[i]=0;
        }
        Time=0;
    }
}