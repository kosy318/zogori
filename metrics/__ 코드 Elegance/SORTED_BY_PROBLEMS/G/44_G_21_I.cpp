#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 123;

int n, m, a[N], dp[N], x[N], l[N], r[N];

bool good(int j, int i) {
    return abs(x[l[i]] - x[i]) <= abs(x[l[i]] - x[j]) && abs(x[j] - x[r[j]]) <= abs(x[i] - x[r[j]]);
}

int main() {

    scanf("%d%d", &m, &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        l[i] = i;
        if (i > 1 && a[i - 1] == a[i]) l[i] = l[i - 1];
    }
    for (int i = n;i > 0;i--) {
        r[i] = i;
        if (i < n && a[i + 1] == a[i]) r[i] = r[i + 1];
    }

    int answer = N + 1;
    for (int i = 1;i <= n;i++) {

        dp[i] = N + 1;
        if (l[i] == 1) {
            dp[i] = 1;
        } else {
            int first = l[l[i] - 1], last = l[i] - 1;
            int pos = -1;
            while(first <= last) {
                int mid = (first + last) / 2;
                if (good(mid, i)) {
                    pos = mid;
                    last = mid - 1;
                } else first = mid + 1;
            }

            dp[i] = min(dp[i - 1] + 1, dp[i]);
            if (pos != -1) dp[i] = min(dp[i], dp[pos] + 1);
            if (i > l[i]) dp[i] = min(dp[l[i]] + 1, dp[i]);

            //cout << "i : " << i << " dp: " << dp[i] << " " << pos << endl;
        }

        if (r[i] == n) answer = min(answer, dp[i]);

        assert(dp[i] >= dp[i - 1]);
    }

//    for (int i = 1;i <= n;i++) cout << dp[i] << " "; cout << endl;

    cout << answer << endl;

    return 0;
}
