#include <stdio.h>
#include<vector>
#include<tuple>
#include <algorithm>

const int MAX = 15000;

/*
2 5
2
3
2 5 1
4 5 2
4 6 1
7 11 2
6 10 1
 */

int price[101];
int dp[15001];
std::vector<std::pair<std::pair<int, int> , int> > task;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &price[i]);
    }
    for (int i = 0; i < M; ++i) {
        int s,e,type;
        scanf("%d %d %d",&s, &e, &type);
        task.push_back({{s,e},type});
/*        for(int j=0; j<=MAX; j++){
            printf("%d %d\n", j, dp[j]);
        }
        printf("-------------------"
               "\n"); // */
    }
    std::sort(task.begin(), task.end(), [](std::pair<std::pair<int, int>, int> &a, std::pair<std::pair<int, int>, int> &b){
       return a.first.second < b.first.second;
    });
    for(auto& i : task){
        int s = i.first.first, e = i.first.second, type = i.second;
        int temp = (e-s)*price[type-1];
        int max = 0;
        for(int j=0; j<=s; j++) max = std::max(max, dp[j]);
        for(int j=e; j<=MAX; j++){
            dp[j] = std::max(dp[j] ,max+temp);
        }

    }
    printf("%d", dp[MAX]);
    return 0;
}