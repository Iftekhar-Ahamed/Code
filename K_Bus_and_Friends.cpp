#include<iostream>
#include<cstdio>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
int n,t[300011],L;
int x[300011],l[300011],r[300011];
ll ans=0;
int main(){

	scanf("%d%d",&n,&L);

	fo(i,1,n)scanf("%d",&x[i]);

	fo(i,1,n){
		scanf("%d",&t[i]);
		ans+=t[i]/(L<<1),t[i]%=(L<<1);
		if(!t[i]){
			--ans,t[i]=L*2;
		}
		l[i]=(t[i]<=x[i]*2),r[i]=(t[i]<=(L-x[i])*2);
	}

	ans+=n+(!r[n]);
	int lcnt=0,rcnt=0,ins=n;
	fo(i,1,n-1){
		if(!l[i]&&!r[i])continue;
		if(!r[i]){
			ins=i;break;
		}
		if(l[i])++lcnt;
		if(!l[i]&&lcnt)--lcnt,--ans;
	}
    
	fod(i,n-1,ins){
		if(!l[i]&&!r[i])continue;
		if(!r[i]&&rcnt)--rcnt,--ans;
		if(r[i])++rcnt;
	}
	ans-=(lcnt+rcnt)/2;
	printf("%lld",ans*L*2);
	return 0;
} 