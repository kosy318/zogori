#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 123;

map<int, int> dp;

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[3] = 0;

    int l = 1, r = 2;
    int from = 4;
    int val = 1;
    while (from <= n) {
        for (int i = from; i < from + l; i++)
            dp[i] = val;
        val++;
        from += l;
        if (from > n)
            break;
        for (int i = from; i < from + r; i++)
            dp[i] = val;
        val++;
        from += r;
        l += l;
        r += r;
    }
    cout << dp[n];

    return 0;
}
