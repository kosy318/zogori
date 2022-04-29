#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[1111];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int r = 1; r <= 1000; r ++) {
            bool flag = false;
            for (int k = 1; i-k-k >= 0; k++) {
                if (r == dp[i-k]*2-dp[i-k-k]) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                dp[i] = r;
                break;
            }
        }

    }


    cout << dp[n] << '\n';

    return 0;
}