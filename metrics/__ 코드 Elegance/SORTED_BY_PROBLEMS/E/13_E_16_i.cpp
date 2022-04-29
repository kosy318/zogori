#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll ccw(pll a, pll b, pll c) {
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
pll operator - (const pll &A, const pll &B) {
	return {B.x-A.x,B.y-A.y};
}

const pll Z = {0,0};

struct quad {
	int i, j, k, l;
	ll geti() {
		vector<ll> vec;
		vec.push_back(i);
		vec.push_back(j);
		vec.push_back(k);
		vec.push_back(l);
		rotate(vec.begin(),min_element(vec.begin(),vec.end()),vec.end());
		ll res = 0;
		for (int i=0;i<4;i++) {
			res = res*1001+vec[i];
		}
		return res;
	}
};

int n;
pll arr[1010];
int ord[1010];
int loc[1010];
vector<quad> minc;

void massert(bool t) {
	if (!t) {
		while(true);
	}
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%lld%lld",&arr[i].first,&arr[i].second);
	}
	sort(arr,arr+n);
	vector<pii> vec;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) vec.push_back({i,j});
	}
	sort(vec.begin(),vec.end(),[](pii &A, pii &B){
		return ccw(Z,arr[A.y]-arr[A.x],arr[B.y]-arr[B.x])>0;
	});
	iota(ord,ord+n,0);
	iota(loc,loc+n,0);
	ll mina = 9e18;
	ll ans = 0;
	for (pii &v : vec) {
		int i = v.first, j = v.second;
		massert(loc[i]+1==loc[j]);
		int k[2] = {-1,-1}, l[2] = {-1,-1};
		if (loc[i]>0) {
			k[0] = ord[loc[i]-1];
		}
		if (loc[i]>1) {
			k[1] = ord[loc[i]-2];
		}
		if (loc[j]<n-1) {
			l[0] = ord[loc[j]+1];
		}
		if (loc[j]<n-2) {
			l[1] = ord[loc[j]+2];
		}
		for (int a =0;a<2;a++) {
			for (int b=0;b<2;b++) {
				if (k[a]>=0&&l[b]>=0) {
					//printf("%d, %d < %d > %d\n",i,j,k[a],l[b]);
					minc.push_back({i,k[a],j,l[b]});
					mina = min(mina,abs(ccw(arr[i],arr[j],arr[k[a]]))+abs(ccw(arr[i],arr[j],arr[l[b]])));
				}
			}
		}
		ans += loc[i]*(n-1-loc[j]);
		swap(ord[loc[i]],ord[loc[j]]);
		swap(loc[i],loc[j]);
	}
	sort(minc.begin(),minc.end(),[](quad &A, quad &B) {
		return A.geti()<B.geti();
	});
	//printf("%lld!!!\n",mina);
	minc.erase(unique(minc.begin(),minc.end(),[](quad &A, quad &B){return A.geti()==B.geti();}),minc.end());
	for (quad &q : minc) {
		//printf("%d, %d, %d, %d : \n",q.i,q.j,q.k,q.l);
		ll area = abs(ccw(arr[q.i],arr[q.j],arr[q.k])+ccw(arr[q.i],arr[q.k],arr[q.l]));
		//printf("%lld!\n",area);
		if (area==mina) ans+=2;
	}
	printf("%lld\n",ans);

	return 0;
}