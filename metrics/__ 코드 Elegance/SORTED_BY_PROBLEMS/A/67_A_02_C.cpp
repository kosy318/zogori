#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;

int s[1001];

int main() {
    s[0] = 1;
    s[1] = 1;
    int t;
    cin >> t;

    for (int n = 2; n <= 1000; ++n) {
        set<int> S;
        for (int i = 1; i <= 500; ++i) {
            S.insert(i);
        }
        for (int k = 1; 2 * k <= n; ++k) {
            int diff = s[n - k] - s[n - 2 * k];
            S.erase(s[n - k] + diff);
        }
        s[n] = *S.begin();
    }
    cout << s[t] << "\n";

    return 0;
}