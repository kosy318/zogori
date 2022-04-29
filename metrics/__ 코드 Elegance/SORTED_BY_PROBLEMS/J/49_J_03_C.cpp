#include <cstdio>
using namespace std;

int dp[4000003];
int main() {
    int n;
    scanf("%d", &n);

    dp[3] = 0;
    int cnt = 1;
    int i = 4;
    int edge = 1;
    int side = 3;
    while(i <= 2*n){
        for(int j=i; j< i+edge; j++) {
            dp[j] = cnt;
        }
        for(int j=i+edge; j< i+side; j++){
            dp[j] = cnt+1;
        }
        cnt += 2;
        i += side;
        edge *= 2;
        side *= 2;
    }
    printf("%d\n", dp[n]);
    return 0;
}