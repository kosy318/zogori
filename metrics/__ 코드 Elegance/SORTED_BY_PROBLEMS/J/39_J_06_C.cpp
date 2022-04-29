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

	int a = n/3 + n%3;
	auto good = [&](int x) {
		return (x&(-x)) == x;
	};
	while(!good(a+1)) ++a;

	cout << (calc(a) + calc((n-a+1)/2)) << endl;

	return 0;
}
