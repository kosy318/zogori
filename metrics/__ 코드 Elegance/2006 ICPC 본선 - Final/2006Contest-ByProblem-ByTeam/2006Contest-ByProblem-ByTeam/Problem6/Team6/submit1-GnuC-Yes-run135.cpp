#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b; b = c; c = a % b;
	}
	return b;
}

int n;
int a[100], b[100];
int A, B, m;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		A = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a[i], &b[i]);
			int gg = gcd(A, a[i]);
			A = A * a[i] / gg;
		}
		scanf("%d", &m);
		B = -1;
		for (int i = 0; i < A; i++) {
			bool sw = true;
			for (int j = 0; j < n; j++) {
				if (((i - b[j]) % a[j]) != 0) sw = false;
			}
			if (sw) {
				B = i;
				break;
			}
		}
		bool ispos = false;
		for (int i = B; ; i += A) {
			int xsum = 0;
			for (int j = 0; j < n; j++) {
				xsum += (i - b[j]) / a[j];
			}
			if (xsum == m) {
				ispos = true;
				printf("%d\n", i);
			}
			if (xsum > m) break;
		}
		if (!ispos) printf("0\n");
	}
}
