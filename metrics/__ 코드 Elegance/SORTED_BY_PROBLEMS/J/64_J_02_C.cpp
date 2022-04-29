#include<bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n; cin >> n;
    n -= 2;
    if (n == 1) return cout << 0 << endl, 0;
    if (n == 2) return cout << 1 << endl, 0;
    V<> a{4};
    int d = 6;
    while (true) {
        if (a.back() > n) break;
        a.push_back(a.back() + d);
        d *= 2;
    }
    int res = 1e9;
    for (int i = 0; i < (int) a.size(); ++i) {
        if (n <= a[i]) {
            res = min(res, 2 * (i + 1));
        }
        if (i) {
            int d = a[i] - a[i - 1];
            if (n <= a[i - 1] + d / 3) {
                res = min(res, 2 * i + 1);
            }
        }
    }
    cout << res << endl;
}