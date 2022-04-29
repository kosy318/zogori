#include <iostream>
#include <cstring>
using namespace std;

int dp[1001], nop[1001], N;

int find(){
    dp[0]=1;
    dp[1]=1;

    for(int i=2; i<=N; i++){
        for(int k=1; i-2*k>=0; k++){
            nop[dp[i-k]*2-dp[i-2*k]]=1;
        }

        for(int j=1; j<=1000; j++){
            if(!nop[j]){
                dp[i]=j;
                break;
            }
        }

        memset(nop, 0, sizeof(nop));
    }

    return dp[N];
}

int main(){
    cin>>N;

    cout<<find()<<'\n';

    return 0;
}
