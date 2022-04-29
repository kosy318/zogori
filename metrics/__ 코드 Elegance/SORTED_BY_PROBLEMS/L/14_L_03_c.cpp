#include <bits/stdc++.h>
#define N 15010
using namespace std;

typedef tuple<int, int, int> iii;

int day[15010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	int price[1010];
	for (int i = 1; i <= m; ++i) {
		cin >> price[i];
	}

	vector<iii> arr(n);
	int a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		arr[i] = {a, b, c};
	}

	sort(arr.begin(), arr.end());

	int j = 0;
	for (int i = 1; i < 15000; ++i) {
		while (j < n && get<0>(arr[j]) == i) {
			int next = get<1>(arr[j]);
			int num = get<2>(arr[j]);
			day[next] = max(day[next], day[i] + (next - i) * price[num]);
			j++;
		}
		day[i + 1] = max(day[i + 1], day[i]);
	}
	cout << day[15000];
}
