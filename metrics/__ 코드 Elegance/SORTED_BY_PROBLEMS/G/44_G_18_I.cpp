#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 123;

int n, m, a[N], dp[N], x[N], l[N], r[N];

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

        if (l[i] == 1) {
            dp[i] = 1;
        } else {
            int first = l[l[i] - 1], last = l[i] - 1;
            int pos = -1;
            while(first <= last) {
                int mid = (first + last) / 2;
                if (x[i] - x[l[i]] <= x[l[i]] - x[mid] && x[l[i] - 1] - x[mid] <= x[i] - x[l[i] - 1]) {
                    pos = mid;
                    last = mid - 1;
                } else first = mid + 1;
            }

            dp[i] = dp[pos] + 1;
            if (i > l[i]) dp[i] = min(dp[l[i]] + 1, dp[i]);
        }

        if (r[i] == n) answer = min(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}
