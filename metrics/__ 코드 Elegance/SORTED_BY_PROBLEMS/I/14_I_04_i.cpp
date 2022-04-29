#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;

vector<ii> arr;
int n;

bool can_put(long long t) {
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	long long now = -1;
	int i = 0;
	while (1) {
		if (pq.empty() && i < n) {
			now = max(arr[i].first, now);
			pq.push(arr[i].second);
			i++;
		}
		while (i < n && arr[i].first <= now) {
			pq.push(arr[i++].second);
		}
		while (!pq.empty() && pq.top() < now) {
			return 0;
		}
		if (pq.empty()) return 1;
		pq.pop();
		now += t;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		arr[i].second += arr[i].first;
	}

	sort(arr.begin(), arr.end());

	long long low = 0, high = 1000000000;
	while (high - low != 1) {
		long long mid = (high + low) / 2;
		if (can_put(mid)) low = mid;
		else high = mid;
	}
	cout << low << '\n';
}
