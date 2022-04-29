#include <bits/stdc++.h>
using namespace std;

int n, a[1004];
set<int> s;

int main() {
	cin >> n;
	a[0] = a[1] = 1;
	
	for (int i=2; i<=n; i++) {
		s.clear();
		for (int k=1; i-2*k>=0; k++) {
			s.insert(2*a[i-k] - a[i-2*k]);
		}
		
		int k=1;
		for (; s.count(k); k++);
		a[i] = k;
	}
	
	cout << a[n] << '\n';
}
