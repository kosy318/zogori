#include <cstdio>
#include <cstdlib>
#include <algorithm>

int cur, n, k, pos[6000];

int solve();
int go();
bool con(int i, int j);

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", &pos[i]);
		int ans = solve();
		printf("%d\n", ans);
	}
}

int solve() {
	std::sort(pos, pos + n);
	int ret = -1;
	cur = 0;
	while (cur < n) {
		int t = go();
		//printf("ret = %d\n", t);
		if (t > ret)
			ret = t;
		if (t != 1) {
			--cur;
			if (cur < 0)
				cur = 0;
		}
	}
	return ret;
}

int go() {
	//printf("go(), cur = %d\n", cur);
	int ret = 1;
	++cur;
	if (cur == n)
		return ret;
	if (con(pos[cur - 1], pos[cur]))
		++ret;
	else
		return ret;
	while (true) {
		++cur;
		if (cur == n)
			return ret;
		if (con(pos[cur - 2], pos[cur]))
			++ret;
		else
			return ret;
	}
	return -1;
}

bool con(int i, int j) {
	return abs(i - j) <= k;
}
