#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n;
pair<int, int> seg[maxn];

bool check(int x)
{
  long long cur = seg[1].first;
  for (int i = 2; i <= n; i++) {
    cur = cur + (long long)x;
    if (cur < seg[i].first) {
      cur = seg[i].first;
    } else if (cur > seg[i].second) {
      return false;
    }
  }
  return true;
}

int main()
{
  cin.tie(0);ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, len;
    cin >> x >> len;
    seg[i] = make_pair(x, x + len);
  }
  sort(seg + 1, seg + n + 1);
  int l = 0;
  int r = 2e9 + 5;
  int ret = -1;
  while (r >= l) {
    int mid = ((long long)l + r) >> 1;
    if (check(mid)) {
      ret = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ret << '\n';
  return 0;
}
