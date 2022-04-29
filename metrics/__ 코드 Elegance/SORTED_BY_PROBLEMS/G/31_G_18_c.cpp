#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

pii arr[100001];
int n,m,gn,gl[100001],gr[100001],g[100001];

struct seg_tr{
	const static int MAX = 1<<17;
	int tr[MAX<<1];
	void init() {
		for(int i=1;i<MAX+MAX;i++) tr[i] = MAX;
	}
	void upd(int cur,int s,int f,int l,int r,int val) {
		if(f<l || s>r) ;
		else if(l<=s && f<=r) tr[cur] = min(tr[cur], val);
		else {
			int nx=cur<<1,md=(s+f)>>1;
			upd(nx,s,md,l,r,val);
			upd(nx+1,md+1,f,l,r,val);
		}
	}
	void upd(int l,int r,int val) {
		if(l>r) return;
		upd(1,0,MAX-1,l,r,val);
	}
	int get(int cur,int s,int f,int l,int r) {
		if(f<l || s>r) return MAX;
		else if(l<=s && f<=r) return tr[cur];
		else {
			int nx=cur<<1,md=(s+f)>>1;
			return min({tr[cur], get(nx,s,md,l,r), get(nx+1,md+1,f,l,r) });
		}
	}
	int get(int l,int r) {
		if(l>r) return MAX;
		return get(1,0,MAX-1,l,r);
	}
}st;

int main() {
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].fi);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].se);

	for(int i=0;i<n;i++) {
		if(i==0 || arr[i].se != arr[i-1].se) {
			gl[++gn] = arr[i].fi;
		}
		gr[gn] =  i;
		g[i] = gn;
	}

	const int INF = 1e9;
	int ans = n;
	st.init();
	for(int i=0;i<n;i++) {
		if(g[i] == 1) st.upd(i,i,0);
		else break;
	}
	for(int i=0,j=0;i<n;i=j) {
		for(j=i;j<n && arr[i].se == arr[j].se; j++) {
			int val = st.get(j, j) + 1;
			if(g[j] == gn) {
				ans = min(ans, val);
			} else {
				int ni = lower_bound(arr, arr+n, 
				pii(arr[j].fi + min(INF, 2*(gl[g[j]+1] - arr[j].fi)) + 1, 0)) - arr;
				int nj = lower_bound(arr, arr+n, 
				pii(arr[j].fi + min(INF, 2*(arr[gr[g[j]]].fi - arr[j].fi)), 0)) - arr;

				ni = min(ni, gr[g[j]+1]+1);
				st.upd(nj, ni - 1, val);
				st.upd(j+1, gr[g[j]], val);
			}
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
