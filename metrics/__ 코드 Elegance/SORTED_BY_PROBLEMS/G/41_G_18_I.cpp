#include <bits/stdc++.h>
#define L long long

using namespace std;

L coln,n;
L x[100010],c[100010];
L dp[100010];

map<L,L>invcr;

L tr[400040];

void init(L now,L S,L E){
	tr[now]=2e9;
	if(S==E) return ;
	L mid=(S+E)/2;
	init(now*2,S,mid);
	init(now*2+1,mid+1,E);
}

void update(L now,L S,L E,L loc,L val){
	if(S>loc||E<loc) return;
	if(S==E)
	{
		tr[now]=min(tr[now],val);
		return;
	}
	L mid=(S+E)/2;
	update(now*2,S,mid,loc,val);
	update(now*2+1,mid+1,E,loc,val);
	tr[now]=min(tr[now*2],tr[now*2+1]);
}

L get(L now,L S,L E,L s,L e){
	if(S>e||E<s) return 2e9;
	if(s<=S&&E<=e) return tr[now];
	L mid=(S+E)/2;
	L ret=2e9;
	ret=min(ret,get(now*2,S,mid,s,e));
	ret=min(ret,get(now*2+1,mid+1,E,s,e));
	return ret;
}
int main()
{
	scanf("%lld %lld",&coln,&n);
	init(1,1,n);
	L i,j;
	x[0]=-2e9;
	for(i=1;i<=n;i++)
	{
		dp[i]=2e9;
		scanf("%lld",&x[i]);
		invcr[x[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	L beflef=0;
	L lef,rig;
	for(i=1;i<=n;)
	{
		for(j=i;j<=n&&c[i]==c[j];j++)
		{
			if(beflef==0)
			{
				dp[j]=1;
				update(1,1,n,j,dp[j]);
				continue;
			}
			lef=x[beflef],rig=x[i-1];
			rig=min(rig,2*x[i]-x[j]);
			lef=max(lef,2*x[i-1]-x[j]);
			lef=lower_bound(x+1,x+n+1,lef)-x;
			rig=upper_bound(x+1,x+n+1,rig)-x-1;
			
			lef=max(lef,beflef);
			rig=min(rig,i-1);
			
			//printf("%lld %lld %lld\n",j,lef,rig);
			
			if(lef<=rig) dp[j]=min(dp[j],get(1,1,n,lef,rig)+1);
			dp[j]=min(dp[j],get(1,1,n,i,j-1)+1);
			update(1,1,n,j,dp[j]);
		}
		beflef=i;
		i=j;
	}
	/*for(i=1;i<=n;i++)
	{
		printf("%lld ",dp[i]);
	}
	puts("");*/
	printf("%lld",dp[n]);
}
