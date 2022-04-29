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

    if (n == 3) return cout << 0, 0;
    if (n & 1) n++;

    int arr[1000001]{0, 0, 0, 0, 1};
    for (int i = 6; i <= n; i += 2) {
        arr[i] = arr[i / 2] += 2;
        arr[i - 1] = arr[i];
    }

    cout << arr[n];

    return 0;
}