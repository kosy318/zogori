#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[1000001];
    dp[3] = 0;
    dp[4] = 1;
    dp[5] = 2;
    int prev = 3;
    int next = 6;
    int padding = 1;
    for(int i = 6; i <= n; i++) {
        if(i == next) {
            dp[i] = dp[prev] + 2;
            prev = next;
            next *= 2;
            padding *= 2;
        }
        else if(i - prev <= padding)
            dp[i] = dp[prev] + 1;
        else
            dp[i] = dp[prev] + 2;
    }

    cout << dp[n] << endl;

    return 0;
}