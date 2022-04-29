#include <bits/stdc++.h>
using namespace std;


int dp[1000001];
int go(int o){
    if (o == 3) return 0;
    if (o == 4) return 1;

    int t = o / 2;
    if (o % 2) t++;

    return dp[o] = go(t) + 2;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d" ,&n);
    printf("%d", go(n));
}