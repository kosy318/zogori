#include <bits/stdc++.h>
using namespace std;

const int maxn = 20005;

struct ele
{
  int x;
  int y;
  int p;
};

int m;
int n;

int price[maxn];
vector<ele> data[maxn];

int f[maxn];
int g[maxn];

int tmax;

int main()
{
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> price[i];
  }
  for (int i = 1; i <= n; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    data[y].push_back({x, y, price[t]});
    tmax = max(tmax, y);
  }
  for (int i = 1; i <= tmax; i++) {
    f[i] = f[i - 1];
    for (int j = 0; j < data[i].size(); j++) {
      int x = data[i][j].x;
      int y = data[i][j].y;
      int p = data[i][j].p;
      f[i] = max(f[i], g[x] + (y - x) * p);
    }
    g[i] = max(f[i], g[i - 1]);
  }
  cout << g[tmax] << endl;
  return 0;
}
