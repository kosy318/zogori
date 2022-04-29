#include <bits/stdc++.h>
using namespace std;

int arr[1010];

int main() {
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= 1000; ++i) {
		int cnt[1000] = {};
		for (int k = 1; i - 2 * k >= 0; ++k) {
			int now = 2 * arr[i - k] - arr[i - 2 * k];
			if (now >= 1) cnt[now]++;
		}
		int j = 1;
		while (1) {
			if (cnt[j] == 0) {
				arr[i] = j;
				break;
			}
			j++;
		}
	}

	int n;
	cin >> n;
	cout << arr[n];
}
