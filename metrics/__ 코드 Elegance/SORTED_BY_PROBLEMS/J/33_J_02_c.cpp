#include <stdio.h>

long long dp[1000005]={0,0,0,0,1,2,2};
int n;
int main(){
	scanf("%d",&n);
	for(int i=8;i<n+2;i+=2){
		dp[i]=2+dp[i/2];	
		dp[i-1]=dp[i];
	}	
	printf("%lld\n",dp[n]);
}
