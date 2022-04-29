#include<bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n; cin >> n;
    V<> a(n + 1);
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int x = 1;
        while (true) {
            bool ok = true;
            for (int k = 1; 2 * k <= i; ++k) {
                if (x - a[i - k] == a[i - k] - a[i - 2 * k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                a[i] = x;
                break;
            }
            ++x;
        }
    }
    cout << a[n] << '\n';
}