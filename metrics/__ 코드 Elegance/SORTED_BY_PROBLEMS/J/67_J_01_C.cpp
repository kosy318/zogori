#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;

int f(int x) {
    if (x == 3) return 0;
    if (x == 4) return 1;
    return 2 + f((x + 1) /2);
}

int main() {
    int n;
    cin >> n;
    cout << f(n);

    return 0;
}