#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using pii = pair<int, int>;

const int N = 2005;

int n, mx, x[2*N], s[2*N][2*N], ans[N], d[N][2*N];
pii a[N];

int cost(int x, int y){
	return s[y][y] - s[x-1][y] - s[y][x-1] + s[x-1][x-1];
}

void f(int i, int s, int e, int os, int oe){
	if(s > e) return;
	int m = (s+e)/2, om = -1;
	d[i][m] = -1e9;
	for(int j = os; j <= min(oe, m-1); j++){
		if(!cost(j+1, m)) continue;
		//printf("%d : %d -> %d (%d+%d)\n", i, j, m, d[i-1][j], cost(j+1, m));
		int cd = d[i-1][j] + cost(j+1, m);
		if(cd > 0 && cd > d[i][m]){
			om = j;
			d[i][m] = cd;
		}
	}
	if(om == -1) om = os;
	f(i, s, m-1, os, om);
	f(i, m+1, e, om, oe);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		x[2*i-1] = a[i].x;
		x[2*i] = a[i].y;
	}
	sort(a + 1, a + n + 1, [](pii p, pii q){ return p.y == q.y ? p.x > q.x : p.y < q.y; });
	int lst = -2e9;
	for(int i = 1; i <= n; i++){
		if(lst < a[i].x){
			mx++;
			lst = a[i].y;
		}
	}
	sort(x + 1, x + 2*n + 1);
	for(int i = 1; i <= n; i++){
		int cx = int(lower_bound(x + 1, x + 2*n + 1, a[i].x) - x);
		int cy = int(lower_bound(x + 1, x + 2*n + 1, a[i].y) - x);
		s[cx][cy]++;
	}
	for(int i = 1; i <= 2*n; i++) for(int j = 1; j <= 2*n; j++){
		s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
	}

	for(int i=1; i<=2*n; ++i) d[0][i] = -2e9;
	for(int j=1; j<=n; ++j) {
		d[j][0] = -2e9;
		for(int i=1; i<=2*n; ++i) {
			d[j][i] = -2e9;
			for(int k=0; k<i; ++k) {
				if(cost(k+1, i))
					d[j][i] = max(d[j][i], d[j-1][k]+cost(k+1, i));
			}
			//printf("d[%d][%d]=%d\n", i, j, d[i][j]);
		}
	}

	for(int i = 1; i <= n; i++){
//		printf("use %d->d %d\n", i, d[2*n][i]);
		for(int j = 1; j <= d[i][2*n]; j++) ans[n-j] = i;
	}
	for(int i = n-1, j = 1; j <= mx; j++, i--) ans[i] = j;
	for(int i = 0; i <= n-1; i++) printf("%d ", ans[i]);
	puts("");
	return 0;
}
