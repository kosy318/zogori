#include <iostream>
#include <cstring>
using namespace std;

long long dp[1000001], N;

long long Max(long long x, long long y){
    return x>y?x:y;
}

long long find(){
    dp[3]=0;
    dp[4]=1;
    dp[5]=1;

    for(int i=6; i<=N; i++){
        for(int j=3; i-j>=2; j++){
            dp[i]=Max(dp[i], dp[j]+dp[i-j+2]);
        }
    }

    return dp[N];
}

int main(){
    cin>>N;

    cout<<find()<<'\n';

    return 0;
}
