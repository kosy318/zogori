#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m;
ll tree[270100];
ll arr[100100];
ll col[100100];
ll blk[100100];
ll S[100100], E[100100];
ll D[100100];
const int key = 131072;
void upd(int idx, ll val) {
	idx += key;
	while(idx) {
		tree[idx] = min(tree[idx],val);
		idx/=2;
	}
}

ll getv(int s, int e) {
	s+=key;e+=key;
	ll res = 5e9;
	while(s<=e) {
		if (s&1) res = min(res,tree[s]);
		if (~e&1) res = min(res,tree[e]);
		s= (s+1)/2;
		e = (e-1)/2;
	}
	return res;
}

int main(){
	scanf("%d%d",&m,&n);
	memset(tree,0x3f,sizeof(tree));
	for (int i=1;i<=n;i++) {
		scanf("%lld",&arr[i]);
	}
	for (int i=1;i<=n;i++) {
		scanf("%lld",&col[i]);
	}
	col[0] = m+1;
	col[n+1] = m+2;
	arr[0] = -4e9;
	arr[n+1] = 4e9;
	n += 2;
	m+=2;
	int p = 0, cp = 0;
	for (int i=0;i<n;i++) {
		if (i==n-1||col[i]!=col[i+1]) {
			for (;p<=i;p++) blk[p] = cp;
			cp++;
		}
	}
	for (int i=0;i<cp;i++) {
		S[i] = 4e9;
		E[i] = -4e9;
	}
	for (int i=0;i<n;i++) {
		S[blk[i]] = min(S[blk[i]],1LL*i);
		E[blk[i]] = max(E[blk[i]],1LL*i);
	}
	D[0] = 1;
	upd(0,1);
	for (int i=1;i<n;i++) {
		ll mini = max(arr[S[blk[i]-1]],2*arr[E[blk[i]-1]]-arr[i]);
		ll maxi = min(arr[E[blk[i]-1]],2*arr[S[blk[i]]]-arr[i]);
		int tm = lower_bound(arr,arr+n,mini)-arr, tM = upper_bound(arr,arr+n,maxi)-arr-1;
		D[i] = 4e9;
		if (tm<=tM) {
			D[i] = min(D[i],getv(tm,tM)+1);
		}
		if (S[blk[i]]<=i-1) {
			D[i] = min(D[i], getv(S[blk[i]], i - 1) + 1);
		}
		upd(i,D[i]);
	}
	printf("%lld\n",D[n-1]-2);

	return 0;
}