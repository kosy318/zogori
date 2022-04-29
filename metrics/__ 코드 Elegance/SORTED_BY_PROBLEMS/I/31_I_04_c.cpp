#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lli = long long;
using pii = pair<lli,lli>;

pii arr[100000];
int n;

bool check(long long l) {
	long long prev = -l;
	for(int i=0;i<n;i++) {
		long long cur = max(arr[i].fi, prev + l);
		if(cur > arr[i].se) return false;
		prev = cur;
	}
	return true;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld%lld",&arr[i].fi,&arr[i].se);
	for(int i=0;i<n;i++) arr[i].se += arr[i].fi;
	
	sort(arr,arr+n);

	long long lo=1,up=3000000001;
	while(up-lo>1) {
		long long md = (lo+up)>>1;
		if(check(md)) lo = md;
		else up = md;
	}
	printf("%lld\n",lo);
	
	return 0;
}
