#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;  cin >> N;

    if (N == 3)
        cout << 0 << endl;
    else {
        int res = (N-1) /3;
        res *= 2;
        if ((N-1)%3 == 0) {
            res --;
        }

        cout << res << '\n';

    }

    return 0;
}