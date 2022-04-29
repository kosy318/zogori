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

    if(n == 3) {
        cout << 0;
        return 0;
    }
    else if(n == 4) {
        cout << 1;
        return 0;
    }

    int ans = 1;

    for(int i = 5; i <= n; i++) {
        if(i % 2 == 1) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}