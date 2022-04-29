#include <iostream>
#include <cstring>
using namespace std;

int dp[1000001], N;

int find(){
    dp[3]=0;
    dp[4]=1;

    for(int i=5; i<=N; i++){
        dp[i]=dp[i-2]+dp[i-1];
    }

    return dp[N];
}

int main(){
    cin>>N;

    cout<<find()<<'\n';

    return 0;
}
