#include <bits/stdc++.h>
#define ll long long
#define orta ((bas+son)>>1)
#define inf 1000000000
#define pb push_back
#define sz(x) ((int)x.size())
#define N 100005
#define ii pair<int,int>
#define st first
#define nd second
using namespace std;

int n,k;
int x[N],c[N],l[N],dp[N];
int s[N<<2];

int get(int node,int bas,int son,int x,int y) {

	if(x>y) return inf;
	
	if(bas>=x && son<=y) return s[node];
	
	if(bas>y || son<x) return inf;
	
	return min(get(node<<1,bas,orta,x,y),get(node<<1|1,orta+1,son,x,y));
	
}

void up(int node,int bas,int son,int x,int y) {

	if(bas>x  || son<x) return ;
	if(bas==x && son==x) {
		
		s[node]=y;
		
		return ;
		
	}
	
	up(node<<1,bas,orta,x,y);
	up(node<<1|1,orta+1,son,x,y);
	
	s[node]=min(s[node<<1],s[node<<1|1]);

}

int main() {
	
	for(int i=0;i<N*4;i++) s[i]=inf;
	
	scanf("%d %d",&k,&n);
	
	for(int i=1;i<=n;i++) {
		
		scanf("%d",&x[i]);
		
	}
	
	for(int i=1;i<=n;i++) {
		
		scanf("%d",&c[i]);
		
	}
	
	for(int i=1;i<=n;i++) {
		
		if(c[i]==c[i-1]) l[i]=l[i-1];
		else l[i]=i;
		
	}
	
	for(int i=1;i<=n;i++) {
		
		dp[i]=i;
		
		// same
		
		if(l[i]!=i) {
			
			dp[i]=min(dp[i],get(1,1,n,l[i],i-1)+1);
			
		}
		
		if(l[i]==1) {
			
			dp[i]=1;
			up(1,1,n,i,dp[i]);
			continue ;
		
		}
		
		// diff
		
		int nxt=l[i]-1;
		int nxx=l[nxt];
		int r=x[i]-x[nxt];

		int pos=lower_bound(x+nxx,x+nxt+1,x[nxt]-r)-x;
		
		dp[i]=min(dp[i],get(1,1,n,pos,nxt)+1);
		
		up(1,1,n,i,dp[i]);
		
	}
	
	int ans=dp[n];
	
	for(int i=n-1;i>=1;i--) {
		
		if(c[i]!=c[i+1]) break ;
		
		ans=min(ans,dp[i]);
		
	}
	
	printf("%d",ans);

}
