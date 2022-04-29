#include <cstdio>
using namespace std;

const int SIZE = 1000001;
int dp[SIZE];

int main() {
    int n;
    scanf("%d", &n);

    dp[4] = 1;
    for(int i=5; i<SIZE; i++) {
        dp[i] = dp[i - i / 2] + 2;
    }

    printf("%d" ,dp[n]);
    return 0;
}