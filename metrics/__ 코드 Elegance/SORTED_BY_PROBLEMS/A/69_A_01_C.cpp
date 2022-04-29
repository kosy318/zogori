#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;

int n;
int A[maxn];

set<int> no;

int main()
{
  cin >> n;
  A[0] = A[1] = 1;
  for (int i = 2; i <= n; i++) {
    no.clear();
    for (int k = 1; k <= i; k++) {
      if (i - 2 * k < 0) break;
      int x = A[i - 2 * k];
      int y = A[i - k];
      no.insert(y + (y - x));
    }
    int cur = 1;
    while (no.count(cur)) {
      cur ++;
    }
    A[i] = cur;
  }
  cout << A[n] << endl;
  return 0;
}
