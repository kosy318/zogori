#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    fastio;
    int n;
    cin >> n;

    int A[1001]{1, 1};
    for (int i = 2; i <= n; ++i) {
        int arr[1001]{};
        for (int j = 1; i - 2 * j >= 0; ++j) {
            int val = 2 * A[i - j] - A[i - 2 * j];
            if (val >= 0) arr[val] = 1;
        }

        for (int j = 1; j <= 1000; ++j) {
            if (arr[j] == 0) {
                A[i] = j;
                break;
            }
        }
    }

    cout << A[n];

    return 0;
}