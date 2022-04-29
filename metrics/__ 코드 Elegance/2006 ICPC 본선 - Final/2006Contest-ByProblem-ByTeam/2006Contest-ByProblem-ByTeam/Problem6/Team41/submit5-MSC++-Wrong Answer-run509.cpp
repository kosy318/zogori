#include <iostream>

using namespace std;

struct bunsu {
	int a, b;
};

bunsu plus(bunsu a, bunsu b) {
	bunsu nbunsu;
	nbunsu.a = a.a*b.b + a.b*b.a;
	nbunsu.b = a.b * b.b;
	return nbunsu;
}

bunsu multiply(bunsu a, bunsu b) {
	bunsu nbunsu;
	nbunsu.a = a.a * b.a;
	nbunsu.b = a.b * b.b;
	return nbunsu;
}


int main() {
	int T;
	cin >> T;
	for(int CNT = 0; CNT < T; CNT++) {
		int n, c;
		int a[100], b[100];
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
		cin >> c;

		bunsu m, tmp;
		m.a = c; m.b = 1;

		for(int i = 0; i < n; i++) {
			tmp.a = b[i];
			tmp.b = a[i];
			m = plus(m, tmp);
		}

		bunsu d;
		d.a = 1; d.b = a[0];
		for(int i = 1; i < n; i++) {
			tmp.a = 1;
			tmp.b = a[i];
			d = plus(d, tmp);
		}
		if((m.a % d.a) == 0) cout << m.a / d.a << endl;
		else cout << 0 << endl;

	}
	return 0;
}