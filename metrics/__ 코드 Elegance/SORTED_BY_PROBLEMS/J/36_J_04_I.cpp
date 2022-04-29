#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000001];
    arr[3] = 0;
    arr[4] = 1;
    arr[5] = 2;
    for ( int i = 6; i <= n; i++ ) {
        if ( i % 2 == 0 ) {
            arr[i] = arr[i/2] + 2;
        } else {
            arr[i] = arr[i-1] + 1;
        }
    }
    cout << arr[n] << endl;
}
