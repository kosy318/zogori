#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    if (N == 3) {
        cout << 0 << endl;
    }
    else {
        int cur = 3;
        int b = 3;
        int res = 0;

        while (true) {
            if (b < N && N <= b+cur) {
                if (b < N && N <= b + cur/3) {
                    cout << res+1 << '\n';
                }
                else
                    cout << res+2 << '\n';
                break;
            }

            res += 2;
            b += cur;
            cur *= 2;
        }
    }

    return 0;
}