#include <iostream>

using namespace std;
long long dp[1000001];

int main() {
    int n;
    cin >> n;
    if(n <= 5){
        cout << n - 3 << endl;
        return 0;
    }
    for(int i = 3; i <= 5; i++){
        dp[i] = i - 3;
    }

    for(int i = 6; i <= n; i++){
        dp[i] = dp[(i + 1) / 2] + 2;
    }

    cout << dp[n] << endl;


    return 0;
}