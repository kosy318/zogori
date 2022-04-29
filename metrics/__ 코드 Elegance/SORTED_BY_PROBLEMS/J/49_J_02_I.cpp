#include <cstdio>
using namespace std;

int dp[1000003];
int main() {
    int n;
    scanf("%d", &n);

    dp[3] = 0;
    int cnt = 1;
    for(int i=4; i <= n; i+=3){
        dp[i] = cnt;
        dp[i+1] = cnt+1;
        dp[i+2] = cnt+1;
        cnt += 2;
    }
    printf("%d\n", dp[n]);
    return 0;
}