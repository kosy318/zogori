#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int p[150];
int dp[10050];
pair<pair<int, int>, pair<int,int>> arr[10050];

int main(){
    int M,N;
    scanf("%d%d", &M, &N);
    for(int i = 0; i < M; i++){
        scanf("%d", p+i);
    }
    for(int i = 0; i < N; i++){
        int s, e, t;
        scanf("%d%d%d", &s, &e, &t);
        arr[i] = {{e, s}, {(e-s)*p[t-1], i}};
    }
    sort(arr, arr+N);
    for(auto e : arr){
        int mmax = 0;
        int fi = e.first.second;
        int se = e.first.first;
        int val = e.second.first;
        int idx = e.second.second;
        for(auto f : arr){
            if(f.first.first > fi) break;
            if(mmax < dp[f.second.second]) mmax = dp[f.second.second];
        }
        dp[idx] = val+mmax;
    }
    int mmax = 0;
    for(int i = 0; i < N; i++){
        if(mmax < dp[i]) mmax = dp[i];
    }
    printf("%d\n", mmax);
    return 0;
}
