#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int n, a[N];

bool bad(int pos) {
    for (int k = 1;2 * k <= pos;k++) {
        if (a[pos] - a[pos - k] == a[pos - k] - a[pos - 2 * k]) {
            return true;
        }
    }
    return false;
}

int main() {

    cin >> n;
    a[0] = 1;
    a[1] = 1;
    for (int i = 2;i <= n;i++) {
        a[i] = 1;
        while(bad(i)) {
            a[i]++;
        }
    }

    cout << a[n] << endl;

    return 0;
}
