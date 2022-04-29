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
        int f = 0;
        for (int j = 1; i - 2 * j >= 0; ++j) {
            if (A[i - j] == 1 && A[i - 2 * j] == 1) f |= 1;
            if (A[i - j] == 2 && A[i - 2 * j] == 2) f |= 2;
            if (A[i - j] == 4 && A[i - 2 * j] == 4) f |= 4;
        }

        if (~f & 1) A[i] = 1;
        else if (~f & 2) A[i] = 2;
        else A[i] = 4;
    }

    cout << A[n];

    return 0;
}