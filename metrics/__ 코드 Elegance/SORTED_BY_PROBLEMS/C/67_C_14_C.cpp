#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int a[300100], b[300100], bidx[100100];

int v[100100];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + 2 * n] = a[i + n] = a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i + 2 * n] = b[i + n] = b[i];
        bidx[b[i]] = i;
    }

    int aleft, aright;
    int bleft, bright;
    int arr[100100];
    for (int i = 0; i < n; ++i) {
        aright = aleft = n + i;
        bright = bleft = n + bidx[a[aleft]];
        int j;
        arr[0] = a[aleft];
        if(v[arr[0]] == 1) continue;
        v[arr[0]] = 1;
        for (j = 0; j < n - 1; ++j) {
            if (a[aleft - 1] == b[bleft - 1]) {
                aleft--;
                bleft--;
                arr[j + 1] = a[aleft];
            }
            else if (a[aleft - 1] == b[bright + 1]) {
                aleft--;
                bright++;
                arr[j + 1] = a[aleft];
            }
            else if (a[aright + 1] == b[bleft - 1]) {
                aright++;
                bleft--;
                arr[j + 1] = a[aright];
            }
            else if (a[aright + 1] == b[bright + 1]) {
                aright++;
                bright++;
                arr[j + 1] = a[aright];
            }
            else {
                break;
            }
            v[arr[j + 1]] = 1;
        }
        if (j == n - 1) {
            for (int k = 0; k < n; ++k) {
                cout << arr[k] << " ";
            }
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}