#include <bits/stdc++.h>

using namespace std;

int ret[2000001];

int main() {
	int n;
	scanf("%d", &n);

	ret[3] = 0;
	ret[4] = 1;

	int idx = 5;
	for(int i = 1;; i++) {
		int cnt = (1<<i);
		for(int j = 0; j < cnt; j++) {
			ret[idx] = i*2;
			idx++;
		}
		for(int j = 0; j < cnt; j++) {
			ret[idx] = i*2+1;
			idx++;
		}

		if(idx >= n)	break;
	}
	printf("%d\n", ret[n]);
	return 0;
}
