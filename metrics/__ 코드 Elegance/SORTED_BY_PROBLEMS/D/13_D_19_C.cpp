#include<bits/stdc++.h>

#define Fi first
#define Se second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define pb push_back
#define szz(x) (int)(x).size()

struct tup {
	int d, i, j;
};

int n;
vector<int> d[52];
vector<tup> ord;
int arr[52];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a;
		while(1) {
			scanf("%d",&a);
			if (a==0) break;
			d[i].push_back(a);
			ord.push_back({a,i,(int)d[i].size()-1});
		}
	}
	sort(ord.begin(),ord.end(),[](tup &A, tup &B){return A.d<B.d;});
	iota(arr,arr+n,0);
	for (int i=(int)ord.size()-1;i>=0;i--) {
		swap(arr[ord[i].i],arr[ord[i].i+1]);
	}
	vector<pii> ans;
	for (tup &t : ord) {
		if (arr[t.i]>arr[t.i+1]) {
			ans.push_back({t.i,t.j});
			swap(arr[t.i],arr[t.i+1]);
		}
	}
	printf("%d\n",ans.size());
	for (pii &v : ans) {
		printf("%d %d\n",v.first+1,v.second+1);
	}

	return 0;
}