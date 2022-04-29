#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>

#define FRONT_FRONT 0
#define FRONT_BACK 1
#define BACK_FRONT 2
#define FONT_BACK 3

using namespace std;

int a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a[4] = 1;
    a[5] = 2;
    a[6] = 2;

    for(int i = 7; i <= 1000000; i++) {
        a[i] = a[i - 3] + 2;
    }

    cout << a[n];

    return 0;
}