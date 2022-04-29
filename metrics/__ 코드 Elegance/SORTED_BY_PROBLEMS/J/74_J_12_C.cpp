#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a[4] = 1;
    a[5] = 2;

    for(int i = 6; i <= n; i++) {
        if (i % 2 == 0) {
            a[i] = a[i / 2] + 2;
        }
        else {
            a[i] = a[(i / 2 + 1)] + 2;
        }
    }

    cout << a[n];

    return 0;
}