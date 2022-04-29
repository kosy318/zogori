#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int DP(int n) {
	int &ret = dp[n];
	if(ret!=-1) return ret;

	if(n<=2) return ret=0;
	else if(n==3) return ret=1;

	return ret = max(DP((n+1)/2), DP((n+1)/2 + (n+1)%2)) + 1;
}

int main() {
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));

	int v = (n+3)/3, t = (n+3)%3;

	int arr[3] = {0,};
	for(int i=0;i<3;i++) {
		int ad = 0;
		if(t) {
			ad  = 1;
			t--;
		}
		arr[i] = DP(v + ad);
	}
	printf("%d\n",arr[0] + arr[1]);

	return 0;
}
