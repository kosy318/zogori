#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
long long lcs(long long a, long long b)
{
	long long g;
	g = gcd(a, b);
	return a * b / g;
}
int main()
{
	int t;
	long long a[30], b[30];
	int n, m, x, c;
	int i;
	long long lc, temp;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}

		temp = lc = 1;
		for (i = 1; i < n; i++) {
			temp = lcs(lc, a[i]);
			lc = temp;
		}

		c = 0;
		x = lc;
		for(i = 1; i < n; i++) { 
			x += lc*a[0] / a[i];
			c += lc * (b[0] - b[i]) / a[i];
		}
		cin >> m;
		if (x == 0 || (m*lc-c) % x) {
			cout << "0" << endl;
			continue;
		}
		x = (m*lc-c) / x;
		cout << a[0]*x + b[0] << endl;
	}
	return 0;
}