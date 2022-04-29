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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n % 2 == 1) {
        cout << (n - 2) - ((n - 2) / 2 + 1);
    }
    else {
        cout << (n - 2) - (n - 2) / 2;
    }

    return 0;
}