#include<stdio.h>
#include<queue>

std::priority_queue<int> pq;

int main() {
    int N;
    scanf("%d", &N);
    int dp[1001] = {1, 1, };
    for (int (i) = 2; (i) <= N; ++(i)) {
        bool check[1001] = {0, };
        for(int k=1; k*2<=i; k++){
            int temp = dp[i-k] - dp[i-2*k];
            if(dp[i-k]+temp>0) check[dp[i-k] + temp] = 1;
/*            if(a[i-k]-a[i-2*k] == now){
                now++;
                while(!pq.empty() && pq.top() == now){
                    now++;
                    pq.pop();
                }
            }
            else if(temp>now){
                pq.push_back(temp);
            }
            // */
        }
        int now = 1;
        while(check[now]) now++;
        dp[i] = now;
//        printf("%d : %d\n", i, dp[i]);
    }
    printf("%d", dp[N]);
    return 0;
}