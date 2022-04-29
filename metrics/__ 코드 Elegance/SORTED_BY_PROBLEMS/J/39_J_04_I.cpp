#include <bits/stdc++.h>
using namespace std;

int n;

int calc(int x) {
	if(!x) return 0;
	for(int i=0; ; ++i) {
		if((1ll << i) > x)
			return i;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	n -= 3;

	int a = n/3, b = n/3, c = n/3;
	if(n%3) ++a;
	if(n%3==2) ++b;

	cout << (calc(a) + calc(b)) << endl;

	return 0;
}
