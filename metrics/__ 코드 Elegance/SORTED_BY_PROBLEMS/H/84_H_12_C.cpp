#include <bits/stdc++.h>
#define ll long long
#define N 3005
#define ii pair<int,int>
#define st first
#define orta ((bas+son)>>1)
#define nd second
#define mp make_pair
#define inf 1000000000
#define pb push_back
using namespace std;

int n1,n2,ny,nx;
int c1,c2;
ii  a[N],b[N];
int ans;
map<int,int> ox,oy;
int sx[N<<2],sn[N<<2],lazy[N<<2];
vector<ii> v[N];

void doit(int node,int val) {
	
	sx[node]+=val;
	sn[node]+=val;
	lazy[node]+=val;
	
}

void push(int node) {

	doit(node<<1,lazy[node]);
	doit(node<<1|1,lazy[node]);
	
	lazy[node]=0;
	
}

int gmin(int node,int bas,int son,int l,int r) {

	if(l>r) return inf;
	
	if(bas>r || son<l) return inf;
	
	if(bas>=l && son<=r) return sn[node];
	push(node);
	
	return min(gmin(node<<1,bas,orta,l,r),gmin(node<<1|1,orta+1,son,l,r));
	
}

int gmax(int node,int bas,int son,int l,int r) {

	if(l>r) return -inf;

	if(bas>r || son<l) return -inf;
	
	if(bas>=l && son<=r) return sx[node];
	push(node);
	
	return max(gmax(node<<1,bas,orta,l,r),gmax(node<<1|1,orta+1,son,l,r));
	
}

void up(int node,int bas,int son,int l,int r,int val) {

	if(bas>r || son<l) return ;
	
	if(bas>=l && son<=r) {
		
		sx[node]+=val;
		sn[node]+=val;
		
		lazy[node]+=val;
		
		return ;
		
	}
	
	push(node);
	
	up(node<<1,bas,orta,l,r,val);
	up(node<<1|1,orta+1,son,l,r,val);
	
	sx[node]=max(sx[node<<1],sx[node<<1|1]);
	sn[node]=min(sn[node<<1],sn[node<<1|1]);
	
}

void cmp() {
	
	for(auto& x:ox) {
		
		x.nd=++nx;
		
	}
	
	for(auto& y:oy) {
		
		y.nd=++ny;
		
	}
	
	for(int i=1;i<=n1;i++) {
		
		a[i]={ox[a[i].st],oy[a[i].nd]};
		
	}

	for(int i=1;i<=n2;i++) {
		
		b[i]={ox[b[i].st],oy[b[i].nd]};
		
	}
	
}

int main() {
	
	scanf("%d",&n1);
	
	for(int i=1;i<=n1;i++) {
		
		int x,y;
		
		scanf("%d %d",&x,&y);
		
		ox[x]=1;
		oy[y]=1;
		
		a[i]={x,y};
		
	}
	
	scanf("%d",&n2);
	
	for(int i=1;i<=n2;i++) {
		
		int x,y;
		
		scanf("%d %d",&x,&y);
		
		ox[x]=1;
		oy[y]=1;
		
		b[i]={x,y};
		
	}

	cmp();	
	
	scanf("%d %d",&c1,&c2);
	
	for(int i=1;i<=n1;i++) {
		
		v[a[i].st].pb({a[i].nd,c1});
		
	}

	for(int i=1;i<=n2;i++) {
		
		v[b[i].st].pb({b[i].nd,-c2});
		
	}
	
	for(int i=1;i<=nx;i++) sort(v[i].begin(),v[i].end());
	
	for(int r1=1;r1<=nx;r1++) {
		
		for(int r2=r1;r2<=nx;r2++) {
			
			for(auto x:v[r2]) {
				
				up(1,1,ny,x.st,ny,x.nd);
				
			}
			
			int mn=0;
			int last=0;
			
			for(auto x:v[r2]) {
				
				ans=max(ans,gmax(1,1,ny,last+1,x.st)-mn);
				
				mn=min(mn,gmin(1,1,ny,last+1,x.st));
				
				last=x.st;
				
			}
			
			ans=max(ans,gmax(1,1,ny,last+1,ny)-mn);
			
		}
		
		for(int j=0;j<N<<2;j++) sx[j]=sn[j]=lazy[j]=0;
		
	}
	
	printf("%d",ans);

}
