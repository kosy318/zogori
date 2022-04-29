#include <bits/stdc++.h>
using namespace std;

int main() {
	int p[25];
	p[0] = 1;
	for (int i = 1; i < 25; ++i) p[i] = p[i - 1] * 2;
	for (int i = 0; i < 25; ++i) p[i]--;

	int node[50];
	for (int i = 1; i < 50; ++i) {
		if (i & 1) {
			int low = (i - 1) / 2;
			int high = (i + 1) / 2;
			node[i] = 1 + p[high] + p[low] * 2;
		}
		else {
			int low = i / 2;
			node[i] = 1 + p[low] * 3;
		}
	}
	node[0] = 1;

	int n;
	cin >> n;
	n -= 2;
	cout << lower_bound(node, node + 50, n) - node;
}
