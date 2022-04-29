#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct segtree {
	int pre[5010], suf[5010], maxi[5010], sum[5010];
	void pu(int i) {
		pre[i] = max(pre[i*2],sum[i*2]+pre[i*2+1]);
		suf[i] = max(suf[i*2+1],sum[i*2+1]+suf[i*2]);
		sum[i] = sum[i*2]+sum[i*2+1];
		maxi[i] = max({maxi[i*2],maxi[i*2+1],suf[i*2]+pre[i*2+1]});
	}
	void init(int s, int e, int idx) {
		if (s==e) {
			pre[idx] = suf[idx] = sum[idx] = maxi[idx] = 0;
			return;
		}
		int m = (s+e)/2;
		init(s,m,idx*2);
		init(m+1,e,idx*2+1);
		pu(idx);
	}
	void upd(int loc, int val, int s, int e, int idx) {
		if (s==e) {
			sum[idx] += val;
			pre[idx] = max(sum[idx],0);
			suf[idx] = max(sum[idx],0);
			maxi[idx] = max(sum[idx],0);
			return;
		}
		int m = (s+e)/2;
		if (loc<=m) upd(loc,val,s,m,idx*2);
		else upd(loc,val,m+1,e,idx*2+1);
		pu(idx);
	}
} st;

struct dot {
	int first, second, col;
};

int n1, n2, n, cv[2];
dot arr[2010];

int main() {
	scanf("%d",&n1);
	vector<int> comx, comy;
	for (int i=0;i<n1;i++) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
		comx.push_back(arr[i].first);
		comy.push_back(arr[i].second);
		arr[i].col = 0;
	}
	scanf("%d",&n2);
	for (int i=n1;i<n1+n2;i++) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
		comx.push_back(arr[i].first);
		comy.push_back(arr[i].second);
		arr[i].col = 1;
	}
	n = n1+n2;
	for (int i=0;i<2;i++) scanf("%d",&cv[i]);

	cv[1]=-cv[1];
	sort(comx.begin(),comx.end());
	comx.erase(unique(comx.begin(),comx.end()),comx.end());
	sort(comy.begin(),comy.end());
	comy.erase(unique(comy.begin(),comy.end()),comy.end());
	for (int i=0;i<n;i++) {
		arr[i].first= lower_bound(comx.begin(),comx.end(),arr[i].first)-comx.begin();
		arr[i].second = lower_bound(comy.begin(),comy.end(),arr[i].second)-comy.begin();
	}
	sort(arr,arr+n,[](dot &A, dot &B){
		return A.first<B.first||(A.first==B.first&&A.second<B.second);
	});
	int ans = 0;
	for (int i=0;i<n;i++) {
		st.init(0,(int)comy.size()-1,1);
		int p = i;
		for (int j=i;j<n;j++) {
			if (j==n-1||arr[j].first!=arr[j+1].first) {
				for (;p<=j;p++) {
					//printf("upd %d, %d\n",arr[p].second,cv[arr[p].col]);
					st.upd(arr[p].second,cv[arr[p].col],0,(int)comy.size()-1,1);
				}
				//printf("%d ~ %d : %d\n",i,j,st.maxi[1]);
				ans = max(ans,st.maxi[1]);
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}