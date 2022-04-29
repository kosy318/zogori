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

    vector<int> ans;

    n -= 2;

    for(int i = 1; i <= n; i++) {
        int x = max(i - 1, n - i);
        ans.push_back(x);
    }

    sort(ans.begin(), ans.end());
    cout << ans[0];

    return 0;
}