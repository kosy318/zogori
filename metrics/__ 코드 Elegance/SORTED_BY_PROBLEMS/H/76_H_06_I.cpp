//
// Created by team076 on 19. 11. 9..
//

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    if (n == 3) {
        cout << 0;
        return 0;
    }
    if (n == 4) {
        cout << 1;
        return 0;
    }

    int t = 4, p = 2, ans = 1;

    while (1) {
        t += p;
        ans++;
        if (n <= t) {
            cout << ans;
            return 0;
        }
        t += p;
        ans++;
        if (n <= t) {
            cout << ans;
            return 0;
        }
        p *= 2;
    }

    return 0;
}