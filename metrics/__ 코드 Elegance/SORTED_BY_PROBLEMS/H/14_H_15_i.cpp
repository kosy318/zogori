#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> arr1, arr2;
int board[2010][2010];
int c1, c2;

int cal(int lx, int hx, int ly, int hy) {
	return board[hx][hy] - board[hx][ly - 1] - board[lx - 1][hy] + board[lx - 1][ly - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	srand(time(NULL));

	map<int, int> rx;
	map<int, int> ry;

	int n1, n2;
	cin >> n1;
	
	int x, y;
	arr1.resize(n1);
	set<int> cntx, cnty;
	for (int i = 0; i < n1; ++i) {
		cin >> x >> y;
		arr1[i] = {x, y};
		rx[x] = 0;
		ry[y] = 0;
		cntx.insert(x);
		cnty.insert(y);
	}
	vector<int> xx, yy;
	for (int u: cntx) xx.push_back(u);
	for (int u: cnty) yy.push_back(u);

	cin >> n2;
	arr2.resize(n2);
	for (int i = 0; i < n1; ++i) {
		cin >> x >> y;
		arr2[i] = {x, y};
		rx[x] = 0;
		ry[y] = 0;
	}

	int cnt = 1;
	for (auto it = rx.begin(); it != rx.end(); ++it) it->second = cnt++;
	cnt = 1;
	for (auto it = ry.begin(); it != ry.end(); ++it) it->second = cnt++;

	cin >> c1 >> c2;

	for (ii u: arr1) {
		board[rx[u.first]][ry[u.second]] += c1;
	}
	for (ii u: arr2) {
		board[rx[u.first]][ry[u.second]] -= c2;
	}

	for (int i = 1; i < 2010; ++i) {
		for (int j = 1; j < 2010; ++j) {
			board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];
		}
	}


	int ans = -1;
	for (int rep = 0; rep < 5000000; ++rep) {
		int lx = rx[xx[rand() % cntx.size() + 1]];
		int hx = rx[xx[rand() % cntx.size() + 1]];
		int ly = ry[yy[rand() % cnty.size() + 1]];
		int hy = ry[yy[rand() % cnty.size() + 1]];
		if (lx > hx) swap(lx, hx);
		if (ly > hy) swap(ly, hy);
		ans = max(ans, cal(lx, hx, ly, hy));
	}
	cout << ans;
}
