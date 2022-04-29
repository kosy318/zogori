#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int SZ = 131072;

struct Seg{
	int d[2*SZ];
	int u(int x, int y){
		d[x += SZ] = y;
		for(x /= 2; x; x /= 2) d[x] = min(d[2*x], d[2*x+1]);
	}
	int g(int x, int y){
		int r = N;
		for(x += SZ, y += SZ; x <= y; x /= 2, y /= 2){
			if(x % 2 == 1) r = min(r, d[x++]);
			if(y % 2 == 0) r = min(r, d[y--]);
		}
		return r;
	}
} S;

int m, n, a[N], c[N], l[N], r[N], d[N];

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++){
		scanf("%d", c + i);
	}
	for(int i = 1, j; i <= n; i = j){
		for(j = i+1; j <= n && c[i] == c[j]; j++);
		for(int k = i; k < j; k++){
			l[k] = i;
			r[k] = j-1;
		}
	}
	for(int i = 1; i <= n; i++){
		int cbr = l[i];
		if(cbr == 1){
			d[i] = 1;
			S.u(i, d[i]);
			continue;
		}
		int pbr = l[cbr - 1];
		d[i] = S.g(cbr, i - 1) + 1;
		int A = a[r[pbr]];
		int B = a[cbr];
		int x = a[i];
		int lft = max(pbr, int(lower_bound(a + 1, a + n + 1, 2 * A - x) - a));
		int rig = min(r[pbr], int(upper_bound(a + 1, a + n + 1, 2 * B - x) - a - 1));
		d[i] = min(d[i], S.g(lft, rig) + 1);
		S.u(i, d[i]);
		// printf("%d : (%d) %d - %d\n", i, d[i], lft, rig);
	}
	printf("%d\n", S.g(l[n], n));
}
