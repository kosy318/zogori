#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 15000
using namespace std;

class cls{
public:
    int start, end, cost;
    int value;
};

bool operator < (cls a, cls b){
    return a.end < b.end;
}

int m,n;
vector<cls> vec;
int arr[101] = {0};
int dp[15000];
int total[SIZE] = {0};


void input(){
    scanf("%d %d ", &m, &n);
    for(int i = 1; i<=m; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i<n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        cls temp;
        temp.start = a;
        temp.end = b;
        temp.cost = c;
        temp.value = (b-a) * arr[c];
        vec.push_back(temp);
    }
}


void solve(){
    sort(vec.begin(), vec.end());

    int cur = 0;
    for(int i = 1; i<=SIZE; i++){
        dp[i] = dp[i - 1];

        while(vec[cur].end == i)
        {
            dp[i] = max(dp[i], vec[cur].value + dp[vec[cur].start]);
            cur++;
        }
    }

    cout << dp[SIZE];
}

int main(void){
    input();
    solve();
}