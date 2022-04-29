#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a[0] = 1;
    a[1] = 1;

    for(int i = 2; i <= 1000; i++) {
        a[i] = 1;

        while(true) {
            bool c = false;
            for(int k = 1; 2 * k <= i; k++) {
                if(a[i] - a[i - k] == a[i - k] - a[i - 2 * k]) {
                    c = true;
                    break;
                }
            }
            if(!c) {
                break;
            }
            a[i]++;
        }
    }

    cout << a[n] << '\n';
    return 0;
}