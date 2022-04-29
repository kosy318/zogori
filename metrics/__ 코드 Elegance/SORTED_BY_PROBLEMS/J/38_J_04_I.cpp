#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[1000001];
    dp[3] = 0;
    int prev = 3;
    int next = 6;
    for(int i = 4; i <= n; i++) {
        if(i == next) {
            dp[i] = dp[prev] + 2;
            prev = next;
            next *= 2;
        }
        else if(i == prev + 1 || i == prev + 2)
            dp[i] = dp[prev] + 1;
        else
            dp[i] = dp[prev] + 2;
    }

    cout << dp[n] << endl;

    return 0;
}