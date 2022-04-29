#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;  cin >> N;

    if (N == 3)
        cout << 0 << endl;
    else if (N == 4) {
        cout << 1 << endl;
    }
    else if (N == 5) {
        cout << 2 << endl;
    }
    else if (N == 6) {
        cout << 2 << endl;
    }
    else {
        int cur = 6;
        int res = 2;

        while (cur < N) {
            cur *= 2;
            res += 2;
        }
        cur /= 2;
        res -= 2;

        if (N <= cur + 2) {
            cout << res+1 << '\n';
        }
        else
            cout << res+2 << '\n';
    }

    return 0;
}