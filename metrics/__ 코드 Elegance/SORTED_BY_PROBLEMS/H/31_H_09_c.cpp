#include<bits/stdc++.h>

using namespace std;

const int MAX = 2048;
struct point {
	int x, y, w;

	point(int x, int y, int w):x(x), y(y), w(w) {}

	bool operator <(const point& other) const {
		return x < other.x;
	}
};

struct item {
	long long lsum, rsum, tsum, msum;

	item() {
		lsum = rsum = tsum = msum = 0;
	}
};

item tree[MAX*2];
vector<point> v;

void update(int idx, int l, int r, int obj, int val) {
	if(l > obj || r < obj)
		return;

	item& cur = tree[idx];
	if(l == r) {
		cur.lsum = max(val, 0);
		cur.rsum = max(val, 0);
		cur.tsum = val;
		cur.msum = max(val, 0);
		return;
	}
	
	int mid = (l+r) >> 1;
	update(idx*2, l, mid, obj, val);
	update(idx*2+1, mid+1, r, obj, val);
	
	item& left = tree[idx*2];
	item& right = tree[idx*2+1];
	
	cur.lsum = max(left.lsum, left.tsum + right.lsum);
	cur.rsum = max(right.rsum, left.rsum + right.tsum);
	cur.tsum = left.tsum + right.tsum;
	cur.msum = max(max(left.msum, right.msum), left.rsum + right.lsum);
}

int main() {
	int n1;
	int px1[1000], py1[1000];
	int n2;
	int px2[1000], py2[1000];

	scanf("%d", &n1);
	vector<int> xx, yy;
	for(int i = 0; i < n1; i++) {
		scanf("%d %d", &px1[i], &py1[i]);
		xx.push_back(px1[i]);
		yy.push_back(py1[i]);
	}
	scanf("%d", &n2);
	for(int i = 0; i < n2; i++) {
		scanf("%d %d", &px2[i], &py2[i]);
		xx.push_back(px2[i]);
		yy.push_back(py2[i]);
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());

	int c1, c2;
	scanf("%d %d", &c1, &c2);
	for(int i = 0; i < n1; i++) {
		int x = lower_bound(xx.begin(), xx.end(), px1[i]) - xx.begin();
		int y = lower_bound(yy.begin(), yy.end(), py1[i]) - yy.begin();
		v.push_back(point(x, y, c1));
	}
	for(int i = 0; i < n2; i++) {
		int x = lower_bound(xx.begin(), xx.end(), px2[i]) - xx.begin();
		int y = lower_bound(yy.begin(), yy.end(), py2[i]) - yy.begin();
		v.push_back(point(x, y, -c2));
	}

	long long ret = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		if(i != 0 && v[i].x == v[i-1].x)
			continue;
		memset(tree, 0, sizeof(tree));
		for(int j = i; j < v.size(); j++) {
			update(1, 0, MAX-1, v[j].y, v[j].w);
			if(j+1 < v.size() && v[j].x == v[j+1].x)
				continue;

			ret = max(ret, tree[1].msum);
		}
	}
	printf("%lld\n", ret);
	return 0;
}
