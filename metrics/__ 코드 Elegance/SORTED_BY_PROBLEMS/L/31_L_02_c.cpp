#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct seg_tr{
	const static int MAX  =1<<14;

	lli tr[MAX<<1];

	void upd(int cur,lli val) {
		cur+=MAX;
		while(cur) {
			tr[cur] = max(tr[cur],val);
			cur>>=1;
		}
	}
	lli get(int l,int r) {
		l+=MAX;r+=MAX;
		lli ret=0;
		while(l<=r) {
			ret = max({ret, tr[l], tr[r]});
			if(l&1) l++;
			if(!(r&1)) r--;
			l>>=1;
			r>>=1;
		}
		return ret;
	}
}st;

int n,m;
struct td{
	int s,e,t;
	bool operator<(const td &rhs)const {
		return e<rhs.e;
	}
	void read() {
		scanf("%d%d%d",&s,&e,&t);
	}
}arr[10000];
int val[10001];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",val+i);
	for(int i=0;i<m;i++) {
		arr[i].read();
	}
	sort(arr,arr+m);
	lli ans=0;
	for(int i=0;i<m;i++) {
		lli v= st.get(0,arr[i].s) + 1ll*(arr[i].e-arr[i].s) * val[arr[i].t];
		st.upd(arr[i].e, v);
		ans = max(ans,v);
	}
	printf("%lld\n",ans);
	return 0;
}
	
