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
typedef pair<pair<LDB, LDB>, LDB> PT;
PT operator + (PT p1, PT p2) {
	return {{p1.F.F + p2.F.F, p1.F.S + p2.F.S}, p1.S + p2.S};
}
PT operator / (PT p1, LDB p) {
	return {{p1.F.F / p, p1.F.S /p}, p1.S / p};
}
PT buf[3];
int pp[3], t[3];
int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", xx + i, yy + i, zz + i);
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
			sum += pow(x - xx[i], 2);
			sum += pow(y - yy[i], 2);
			sum += pow(z - zz[i], 2);
		}
		printf("%.6Lf\n", sum);
	} else {
		if (n <= 2) {
			printf("%.6lf\n", 0.0);
			return 0;
		}
		LDB ans = 6e9 + 7;
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
					int x3 = y1*z2 - y2*z1;
					int y3 = z1*x2 - z2*x1;
					int z3 = x1*y2 - y1*x2;
					pair<pair<LDB, LDB>, LDB> v1 = {{0, 0}, 0};
					pair<pair<LDB, LDB>, LDB> v2 = {{0, 0}, 0};
					int n1 = 0, n2 = 0;
					for (int l = 1; l <= n; l++) {
						if (l == i || l == j || l == k) continue ;
						int val = x3*xx[l] + y3*yy[l] + z3*zz[l];
						if (val > 0) {
							v1 = v1 + (PT) {{xx[l], yy[l]}, zz[l]};
							t[l] = 3;
							n1++;
						} else {
							t[l] = 4;
							v2 = v2 + (PT) {{xx[l], yy[l]}, zz[l]};
							n2++;
						}
					}
					for (int mask = 0; mask < 8; mask++) {
						PT v3 = v1, v4 = v2;
						int n3 = n1, n4 = n2;
						for (int jj = 0; jj < 3; jj++) {
							if (mask & (1<<jj)) {
								v3 = v3 + buf[jj];
								t[pp[jj]] = 3;
								n3++;
							} else {
								v4 = v4 + buf[jj];
								t[pp[jj]] = 4;
								n4++;
							}
						}
						if (n3) v3 = v3 / n3;
						if (n4) v4 = v4 / n4;
						LDB sum = 0;
						for (int l = 1; l <= n; l++) {
							if (t[l] == 3) {
								sum += pow(v3.F.F - xx[l], 2);
								sum += pow(v3.F.S - yy[l], 2);
								sum += pow(v3.S - zz[l], 2);
							} else {
								sum += pow(v4.F.F - xx[l], 2);
								sum += pow(v4.F.S - yy[l], 2);
								sum += pow(v4.S - zz[l], 2);
							}
						}
						ans = min(ans, sum);
					}
				}
			}
		}
		printf("%.6Lf\n", ans);
	}
	return 0;
}

