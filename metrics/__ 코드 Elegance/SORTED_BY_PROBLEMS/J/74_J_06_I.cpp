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

    n -= 2;

    int ans = 1;

    if(n % 2 == 1) {
        cout << (n / 2 + 1) - 1;
    }
    else {
        for(int i = 1; i <= n / 2; i++) {
            if(i % 2 == 0) {
                ans++;
            }
        }
        cout << ans;
    }

    return 0;
}