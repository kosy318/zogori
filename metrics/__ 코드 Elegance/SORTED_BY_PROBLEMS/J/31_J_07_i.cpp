#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1111111];
int ddp[111];
int ans;

int f(int x)
{
	if(x==2) return -1;
	if(dp[x] != -1) return dp[x];
	if(x<=3) return dp[x] = 0;

	int xx = (x+1)/2;
	int xy = x+1 - xx;

	return dp[x] = max(f(xx) , f(xy))+1;
}


int main()
{
	scanf("%d",&n);


	if(n == 3)
	{
		printf("0");
		return 0;
	}
	if(n == 4)
	{
		printf("1");
		return 0;
	}
	if(n == 5)
	{
		printf("2");
		return 0;
	}
	if(n == 6)
	{
		printf("2");
		return 0;
	}


	memset(dp,-1,sizeof(dp));
	memset(ddp,-1,sizeof(ddp));

	ans = 1000000000;

	for(int i = 3; i <= n ; i++)
	{
		ddp[f(i)] = i;	
	}

	for(int i = 0 ; i <= 100 ; i++)
	{
		if(ddp[i] == -1)
			continue;
		for(int j =0 ; j <= 100 ; j++)
		{
			if(ddp[j] == -1)
				continue;
			int k = n+3 - ddp[i] - ddp[j];
			if(k < 0) k = 2;
			int val = f(ddp[i]) + f(ddp[j]) + 3;
			val = max(val, f(ddp[i])+f(k) + 2);
			val = max(val, f(ddp[j])+f(k) + 2);
			ans = min(val,ans);
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
