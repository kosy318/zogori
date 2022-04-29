#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(X) (X).begin(), (X).end()
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define pb push_back
typedef long long LL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e6 + 7;
int xx[MXN], yy[MXN], zz[MXN];
int xx2[MXN], yy2[MXN], zz2[MXN];
typedef pair<pair<LDB, LDB>, LDB> PT;
PT operator + (PT p1, PT p2) {
	return {{p1.F.F + p2.F.F, p1.F.S + p2.F.S}, p1.S + p2.S};
}
PT operator / (PT p1, LDB p) {
	return {{p1.F.F / p, p1.F.S /p}, p1.S / p};
}
LDB mypow(LDB v, LL t) { return v*v; }
const LDB eps = 1e-11;
PT buf[3];
int pp[3], t[3];
int main(){
	srand(time(NULL));
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", xx + i, yy + i, zz + i);
		xx2[i] = xx[i]*xx[i];
		yy2[i] = yy[i]*yy[i];
		zz2[i] = zz[i]*zz[i];
		//xx[i] = rand() % 1001;
		//yy[i] = rand() % 1001;
		//zz[i] = rand() % 1001;
	}
	LL sm = 0;
	for (int i = 1; i <= n; i++)
		sm += xx2[i] + yy2[i] + zz2[i];

	if (m == 1) {
		LDB x = 0, y = 0, z = 0;
		for (int i = 1; i <= n; i++) {
			x += xx[i];
			y += yy[i];
			z += zz[i];
		}
		x /= n, y /= n, z /= n;
		LDB sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += mypow(x - xx[i], 2);
			sum += mypow(y - yy[i], 2);
			sum += mypow(z - zz[i], 2);
		}
		printf("%.6Lf\n", sum + eps);
	} else {
		if (n <= 2) {
			printf("%.6lf\n", 0.0);
			return 0;
		}
		LDB ans = 6e9 + 7;
		LDB ans2 = ans;
		/*	
		for (int i = 0; i < (1<<n); i++) {
			pair<pair<LDB, LDB>, LDB> v1 = {{0, 0}, 0};
			pair<pair<LDB, LDB>, LDB> v2 = {{0, 0}, 0};
			int n1 = 0, n2 = 0;
			for (int j = 1; j <= n; j++) {
				if (i & 1<<(j-1)) {
					v1 = v1 + (PT) {{xx[j], yy[j]}, zz[j]};
					n1++;
				} else {
					v2 = v2 + (PT) {{xx[j], yy[j]}, zz[j]};
					n2++;
				}
			}
			if (n1) v1 = v1 / n1;
			if (n2) v2 = v2 / n2;
			LDB sum = 0;
			for (int j = 1; j <= n; j++) {
				if (i & 1<<(j-1)) {
					sum += pow(v1.F.F - xx[j], 2);
					sum += pow(v1.F.S - yy[j], 2);
					sum += pow(v1.S - zz[j], 2);
				} else {
					sum += pow(v2.F.F - xx[j], 2);
					sum += pow(v2.F.S - yy[j], 2);
					sum += pow(v2.S - zz[j], 2);
				}
			}
			ans2 = min(ans2, sum);
		}
		printf("%.6Lf\n", ans2); */
		for (int i = 1; i <= n; i++) {
			pp[0] = i;
			buf[0] = (PT) {{xx[i], yy[i]}, zz[i]};
			for (int j = i + 1; j <= n; j++) { 
				pp[1] = j;
				buf[1] = (PT) {{xx[j], yy[j]}, zz[j]};
				for (int k = j + 1; k <= n; k++) {
					pp[2] = k;
					buf[2] = (PT) {{xx[k], yy[k]}, zz[k]};
					int x1 = xx[i] - xx[k];
					int y1 = yy[i] - yy[k];
					int z1 = zz[i] - zz[k];

					int x2 = xx[j] - xx[k];
					int y2 = yy[j] - yy[k];
					int z2 = zz[j] - zz[k];

					LL x3 = y1*z2 - y2*z1;
					LL y3 = z1*x2 - z2*x1;
					LL z3 = x1*y2 - y1*x2;
					pair<pair<LDB, LDB>, LDB> v1 = {{0, 0}, 0};
					pair<pair<LDB, LDB>, LDB> v2 = {{0, 0}, 0};
					pair<pair<LDB, LDB>, LDB> v5 = {{0, 0}, 0};
					pair<pair<LDB, LDB>, LDB> v6 = {{0, 0}, 0};
					int n1 = 0, n2 = 0;
					for (int l = 1; l <= n; l++) {
						if (l == i || l == j || l == k) continue ;
						LL val = x3*(xx[l] - xx[k]) + y3*(yy[l] - yy[k]) + z3*(zz[l] - zz[k]);
						if (val > 0) {
							v1 = v1 + (PT) {{xx[l], yy[l]}, zz[l]};
							v5 = v5 + (PT) {{xx2[l], yy2[l]}, zz2[l]};
							t[l] = 3;
							n1++;
						} else {
							t[l] = 4;
							v2 = v2 + (PT) {{xx[l], yy[l]}, zz[l]};
							v6 = v6 + (PT) {{xx2[l], yy2[l]}, zz2[l]};
							n2++;
						}
					}
					for (int mask = 0; mask < 8; mask++) {
						PT v3 = v1, v4 = v2, v7 = v5, v8 = v6;
						int n3 = n1, n4 = n2;
						for (int jj = 0; jj < 3; jj++) {
							if (mask & (1<<jj)) {
								v3 = v3 + buf[jj];
								v7 = v7 + (PT) {{xx2[pp[jj]], yy2[pp[jj]]}, zz2[pp[jj]]};
								n3++;
							} else {
								v4 = v4 + buf[jj];
								v8 = v8 + (PT) {{xx2[pp[jj]], yy2[pp[jj]]}, zz2[pp[jj]]};
								n4++;
							}
						}
						LDB sum = sm;
						if (n3) sum -= (v3.F.F*v3.F.F + v3.F.S*v3.F.S + v3.S*v3.S) / n3;
						if (n4) sum -= (v4.F.F*v4.F.F + v4.F.S*v4.F.S + v4.S*v4.S) / n4;
						ans = min(ans, sum);
					}
				}
			}
		}
		printf("%.6Lf\n", ans + eps);
	}
	return 0;
}

