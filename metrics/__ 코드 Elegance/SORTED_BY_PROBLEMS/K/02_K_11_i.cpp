#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int) x.size()
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()

struct P {
	ll x, y, z;
};

P operator + (P a, P b) {
	return {a.x + b.x, a.y + b.y, a.z + b.z};
}
P operator - (P a, P b) {
	return {a.x - b.x, a.y - b.y, a.z - b.z};
}
ll operator * (P a, P b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
P operator / (P a, P b) {
	P res;
	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;	
	return res;
}




int N;
int K;

P p[10010];
int used[100100];
int g[100100];
double solve(int ii, int jj, int kk) {
	int idx[3] = {ii, jj, kk};
	P p1 = p[ii], p2 = p[jj], p3 = p[kk];

	P pp = (p2 - p1) / (p3 - p1);

	for (int i = 1; i <= N; i++) {
		if ( used[i] ) continue;
		ll t = pp * p[i];
		if ( t > 0 ) g[i] = 1;
		else g[i] = -1;
	}

	double res = 1e27;	

	for (int m = 0; m < (1<<3); m++ ) {
		for (int k = 0; k < 3; k++) {
			if ( m & (1<<k) ) g[idx[k]] = 1;
			else g[idx[k]] = -1;			
		}
		P sum1 = {0,0,0}, sum2 = {0,0,0}, sq = {0,0,0};
		// calc
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= N; i++) {
			sq.x += p[i].x * p[i].x;
			sq.y += p[i].y * p[i].y;
			sq.z += p[i].z * p[i].z;
			if ( g[i] == 1 ) sum1 = sum1 + p[i], cnt1++;
			else sum2 = sum2 + p[i], cnt2++;
		}
		
		double t = sq.x + sq.y + sq.z;
		if ( cnt1 != 0 ) t -= (double) 1.0 * ( sum1.x * sum1.x + sum1.y * sum1.y + sum1.z * sum1.z ) / (cnt1);
		if ( cnt2 != 0 ) t -= (double) 1.0 * ( sum2.x * sum2.x + sum2.y * sum2.y + sum2.z * sum2.z ) / (cnt2);
//		t -= (double) 1.0 * ( sum1.x * sum1.x + sum1.y * sum1.y + sum1.z * sum1.z ) / (cnt1);
//		t -= (double) 1.0 * ( sum2.x * sum2.x + sum2.y * sum2.y + sum2.z * sum2.z ) / (cnt2);
		res = min(res, t);
//		printf("%d %d %f %f\n", cnt1, cnt2, t, res);
	}
	return res;

}

int main () {
	scanf("%d%d",&N,&K);
	repp(i,N) {
		ll x,y,z; scanf("%lld%lld%lld",&x,&y,&z);
		p[i].x = x; p[i].y = y; p[i].z = z;
	}
	
	if ( K == 1 ) {
		double ans = 0.0;
		P sum = {0, 0, 0};
		P sq = {0, 0, 0};
		for (int i = 1; i <= N; i++) {
			sum = sum + p[i];
			sq.x += p[i].x * p[i].x;
			sq.y += p[i].y * p[i].y;
			sq.z += p[i].z * p[i].z;
		}
		ans += sq.x + sq.y + sq.z;
		
		double t = sum.x * sum.x + sum.y * sum.y + sum.z * sum.z;
		ans -= t / (1.0 * N) ;

		printf("%.6f\n" ,ans);
	}
	else {
		if ( N <= 2 ) {
			printf("%.6f\n", 0.0);
			return 0;
		}
		double ans = 1e27;
		for (int i = 1; i <= N; i++) {
			used[i] = 1;
			for (int j = i + 1; j <= N; j++) {
				used[j] = 1;
				for (int k = j + 1; k <= N; k++) {
					used[k] = 1;
					ans = min(ans, solve(i, j, k));
					used[k] = 0;
				}
				used[j] = 0;
			}
			used[i] = 0;
		}
		printf("%.6f\n", ans);
	}
	return 0;
}
