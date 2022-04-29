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

    int ans = 2;

    while(true) {
        int cnt = 0;
        for(int i = 1; i <= n; i+= 2) {
            cnt++;
        }
        if(cnt <= 3) {
            cout << ans;
            break;
        }
        else if(cnt == 4) {
            cout << ans + 1;
            break;
        }
        n -= cnt;
        ans += 2;
    }

    return 0;
}