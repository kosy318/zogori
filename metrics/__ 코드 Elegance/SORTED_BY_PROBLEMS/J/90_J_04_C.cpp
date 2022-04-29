#include <iostream>

int dp[1000001];

int main() {
    int N;
    std::cin >> N;
    dp[4] = 1;
    for(int i=5; i<=N; i++){
        dp[i] = dp[(i+1)/2]+2;
    }
    std::cout << dp[N];
    return 0;
}