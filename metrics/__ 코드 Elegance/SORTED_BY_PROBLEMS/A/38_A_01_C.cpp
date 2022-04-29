#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1001];
    bool avail[1001];
    a[0] = 1;
    a[1] = 1;
    int val;
    for(int i = 2; i <= n; i++) {
        fill_n(avail, 1001, true);
        for(int k = 1; i - 2 * k >= 0; k++) {
            val = 2 * a[i - k] - a[i - 2 * k];
            if(val > 0 && val <= 1000)
                avail[val] = false;
        }

        for(int j = 1; j < 1001; j++) {
            if(avail[j]) {
                a[i] = j;
                break;
            }
        }
    }

    cout << a[n] << endl;

    return 0;
}