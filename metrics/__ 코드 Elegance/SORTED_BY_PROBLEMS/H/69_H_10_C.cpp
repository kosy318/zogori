#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 4005;

struct point
{
  int x;
  int y;
  int xid;
  int yid;
  int w;
};

set<int> xpool;
set<int> ypool;

int n;
int m;

int c1;
int c2;

point p[maxn];

int lx;
int ly;
int _x[maxn];
int _y[maxn];

vector<int> pts[maxn];

struct node
{
  int lmax;
  int rmax;
  int sum;
  int ans;
};

node T[maxn << 3];

void combine(int x)
{
  int l = x << 1;
  int r = x << 1 | 1;
  T[x].lmax = max(T[l].lmax, T[l].sum + T[r].lmax);
  T[x].lmax = max(0, T[x].lmax);
  T[x].rmax = max(T[r].rmax, T[r].sum + T[l].rmax);
  T[x].rmax = max(0, T[x].rmax);
  T[x].sum = T[l].sum + T[r].sum;
  T[x].ans = max(T[l].ans, T[r].ans);
  T[x].ans = max(T[x].ans, T[l].rmax + T[r].lmax);
  T[x].ans = max(0, T[x].ans);
}

void build(int x, int l, int r, int val)
{
  if (l == r) {
    T[x].sum = val;
    T[x].ans = T[x].lmax = T[x].rmax = max(0, val);
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid, val);
  build(x << 1 | 1, mid + 1, r, val);
  combine(x);
}

void add(int x, int l, int r, int x0, int val)
{
  if (l == r) {
    T[x].sum += val;
    T[x].ans = T[x].lmax = T[x].rmax = max(0, T[x].sum);
    return;
  }
  int mid = (l + r) >> 1;
  if (x0 <= mid) add(x << 1, l, mid, x0, val);
  else add(x << 1 | 1, mid + 1, r, x0, val);
  combine(x);
}

int getid_x(int x)
{
  return lower_bound(_x + 1, _x + lx + 1, x) - _x;
}

int getid_y(int y)
{
  return lower_bound(_y + 1, _y + ly + 1, y) - _y;
}

int main()
{
  cin.tie(0);ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
    xpool.insert(p[i].x);
    ypool.insert(p[i].y);
  }
  cin >> m;
  for (int i = n + 1; i <= n + m; i++) {
    cin >> p[i].x >> p[i].y;
    xpool.insert(p[i].x);
    ypool.insert(p[i].y);
  }
  cin >> c1 >> c2;

  for (int i = 1; i <= n; i++) {
    p[i].w = c1;
  }
  for (int i = n + 1; i <= n + m; i++) {
    p[i].w = -c2;
  }

  for (auto i = xpool.begin(); i != xpool.end(); i++) {
    _x[++lx] = *i;
  }
  for (auto i = ypool.begin(); i != ypool.end(); i++) {
    _y[++ly] = *i;
  }

  for (int i = 1; i <= n + m; i++) {
    p[i].xid = getid_x(p[i].x);
    p[i].yid = getid_y(p[i].y);
    pts[p[i].xid].push_back(i);
  }

  bool flag = false;
  int ans = 0;

  for (int i = 1; i <= lx; i++) {
    build(1, 1, ly, 0);
    for (int j = i; j <= lx; j++) {
      for (int k = 0; k < pts[j].size(); k++) {
	int id = pts[j][k];
	int yid = p[id].yid;
	int weight = p[id].w;
	add(1, 1, ly, yid, weight);
      }
      if (!flag) {
	ans = T[1].ans;
	flag = true;
      } else {
	ans = max(ans, T[1].ans);
      }
    }
  }

  cout << ans << '\n';
  
  return 0;
}
