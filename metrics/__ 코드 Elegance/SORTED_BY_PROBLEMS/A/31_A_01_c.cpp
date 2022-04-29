#include <bits/stdc++.h>

using namespace std;

int a[1001];
bool cannot[1001];

int main() {
	int n;
	scanf("%d", &n);

	a[0] = a[1] = 1;
	for(int i = 2; i <= n; i++) {
		memset(cannot, 0, sizeof(cannot));
		for(int k = 1; i-2*k >= 0; k++) {
			int cur = a[i-2*k], nex = a[i-k];
			int x = nex + (nex-cur);
			if(x > 0 && x <= 1000)
				cannot[x] = true;
		}

		for(int k = 1; k <= 1000; k++)
			if(!cannot[k]) {
				a[i] = k;
				break;
			}
	}
	printf("%d\n", a[n]);
	return 0;
}
