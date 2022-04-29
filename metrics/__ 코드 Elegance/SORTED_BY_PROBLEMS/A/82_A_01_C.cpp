#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 123;

int n;
int a[N];

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        set<int> bs;
        for (int k = 1; k; k++) {
            if (i - 2 * k < 0)
                break;

            int x = a[i - k - k];
            int y = a[i - k];
            int diff = y - x;
            int z = y + diff;
            if (z > 0) bs.insert(z);
        }
        a[i] = 1;
        while (bs.count(a[i])) a[i]++;
    }
    cout << a[n];

    return 0;
}
