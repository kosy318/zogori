#include<stdio.h>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>

std::vector<std::pair<int, int> > v[2];
int dp[1001][1001];
int plus, minus;
int Ans;

void func(int left, int right){
    if(left > right) return;
    if(dp[left][right] != -2e9) return;
    std::priority_queue<std::pair<int, int> > pq;
    for(int i=left; i<=right; i++) pq.push({v[0][i].second, plus});
    int now = 0;
    while(v[1][now] < v[0][left]) now++;
    while(now < v[1].size() && v[1][now] <= v[0][right]){
        pq.push({v[1][now].second, -minus});
        now++;
    }
    int ans=0, temp=0;
    while(!pq.empty()){
//        printf("%d %d //", pq.top().first, pq.top().second);
        auto now = pq.top(); pq.pop();
        temp = std::max(0, temp+now.second);
        ans = std::max(ans, temp);
//        printf("%d %d : %d %d\n", left, right, temp, ans);
    }
    dp[left][right] = ans;
    if(Ans < ans) Ans = ans;
    for(int i=left; i<=right; i++){
        func(left, i);
        func(i, right);
    }
}

int main() {
    int N[2];
    for(int i=0; i<2; i++){
        scanf("%d", &N[i]);
        for(int j=0; j<N[i]; j++){
            int x,y;
            scanf("%d %d", &x, &y);
            v[i].push_back({x,y});
        }
    }
    scanf("%d %d", &plus, &minus);
    for(int i=0; i<=N[0]; i++){
        for(int j=0; j<=N[0]; j++){
            dp[i][j] = -2e9;
        }
    }
    std::sort(v[0].begin(), v[0].end());
    func(0, N[0]-1);
    printf("%d", Ans);
    return 0;
}