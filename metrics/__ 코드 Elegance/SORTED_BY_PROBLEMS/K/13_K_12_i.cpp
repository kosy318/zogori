#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define szz(x) (int)(x).size()
#define ll long long
#define rep(i, n) for(int i=0;i<(n);i++)

struct point {
	int x, y, z;
	ll operator*(const point &a)const {
		return (ll)x * a.x + (ll)y * a.y + (ll)z * a.z;
	}
	point operator/(const point &a)const {
		return {y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x};
	}
	point operator-(const point &a)const {
		return {x-a.x, y-a.y, z-a.z};
	}
};

point P[110];

double Get(vector <int> &a) {
	if(szz(a) <= 1) return 0;
	double sx = 0, sy = 0, sz = 0;
	double sx2 = 0, sy2 = 0, sz2 = 0;
	for(int e : a) {
		sx2 += P[e].x * P[e].x, sy2 += P[e].y * P[e].y, sz2 += P[e].z * P[e].z;
		sx += P[e].x, sy += P[e].y, sz += P[e].z;
	}
	int m = szz(a);
	return sx2 + sy2 + sz2 - (sx * sx + sy * sy + sz * sz) / m;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		P[i] = {x, y, z};
	}
	vector <int> w;
	for(int i=1;i<=n;i++) w.pb(i);
	double ans = Get(w);
	if(k > 1) {
		if(n == 2) {
			ans = 0;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<i;j++) for(int a=1;a<j;a++) {
			point Q = (P[j] - P[i]) / (P[k] - P[i]);
			double sum[2] = {};
			double sx[2] = {}, sy[2] = {}, sz[2] = {};
			int cnt[2] = {};
			for(int b=1;b<=n;b++) {
				ll v = Q * (P[b] - P[i]);
				int cmd = 0;
				if(v == 0) continue;
				if(v > 0) cmd = 1;
				sum[cmd] += P[b].x * P[b].x + P[b].y * P[b].y + P[b].z * P[b].z;
				sx[cmd] += P[b].x;
				sy[cmd] += P[b].y;
				sz[cmd] += P[b].z;
				cnt[cmd] += 1;
			}
			for(int bt=0;bt<8;bt++) {
				double sum2[2] = {};
				double sx2[2], sy2[2], sz2[2];
				int cnt2[2] = {};
				rep(g, 2) sum2[g] = sum[g], sx2[g] = sx[g], sy2[g] = sy[g], sz2[g] = sz[g], cnt2[g] = cnt[g];
				int t1 = (bt & 1);
				sum2[t1] += P[i].x * P[i].x + P[i].y * P[i].y + P[i].z * P[i].z;
				sx2[t1] += P[i].x; sy2[t1] += P[i].y; sz2[t1] += P[i].z;
				cnt2[t1]++;
				t1 = (bt >> 1) & 1;
				sum2[t1] += P[j].x * P[j].x + P[j].y * P[j].y + P[j].z * P[j].z;
				sx2[t1] += P[j].x; sy2[t1] += P[j].y; sz2[t1] += P[j].z;
				cnt2[t1]++;
				t1 = (bt >> 2) & 1;
				sum2[t1] += P[a].x * P[a].x + P[a].y * P[a].y + P[a].z * P[a].z;
				sx2[t1] += P[a].x; sy2[t1] += P[a].y; sz2[t1] += P[a].z;
				cnt2[t1]++;
				double val = 0;
				rep(g, 2) {
					if(cnt2[g]) val += sum2[g] - (sx2[g] * sx2[g] + sy2[g] * sy2[g] + sz2[g] * sz2[g]) / cnt2[g];
				}
				ans = min(ans, val);
			}
		}
	}
	printf("%.6f\n", ans);
	return 0;
}