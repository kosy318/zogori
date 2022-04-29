#include <bits/stdc++.h>
using namespace std;

int X[10010];

int main() {
	X[0] = 1;
	X[1] = 2;
	int t = 3;
	for(int i=2;i<=100;i+=2) {
		X[i] = X[i-2] + t;
		t = t * 2;
	}
	t = 4;
	for(int i=3;i<=100;i+=2) {
		X[i] = X[i-2] + t;
		t = t * 2;
	}
	int n; scanf("%d", &n);
	int d = 0;
	for(;X[d]<n-2;d++);
	printf("%d\n", d);
    return 0;
}