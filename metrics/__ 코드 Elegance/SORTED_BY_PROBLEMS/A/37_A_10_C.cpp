#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int dp[1001];

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;;j++){
            bool flag = true;
            dp[i] = j;
            for(int k=1; i-2*k >= 0; k++){
                if((dp[i] - dp[i-k]) == (dp[i-k] - dp[i-2*k])){
                    flag = false;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
    }

    printf("%d", dp[n]);

    return 0;
}