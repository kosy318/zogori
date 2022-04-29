#include<stdio.h>
#include<algorithm>
#include<vector>

#define INF 999999999
#define MaxN 20001
#define MAXV(A,B) ((A)>(B)?(A):(B))

using namespace std;

int n,m,price[MaxN],CorToInd[MaxN],ind,dp[MaxN];
vector<int> cor;

struct data
{
	int s,e,cost;
}; data d[MaxN];


bool cmp(data A,data B)
{
	return A.e < B.e;
}


int main()
{

	int i,C,type,k,j,ans;

	scanf("%d%d",&n,&m);

	for(i=1; i<=n; i++) scanf("%d",&price[i]);
	
	for(i=1; i<=m; i++){
		scanf("%d%d%d",&d[i].s,&d[i].e,&type);
		d[i].cost = price[type] * (d[i].e - d[i].s);
	}

	stable_sort(d+1,d+m+1,cmp);
	
	dp[1] = d[1].cost;
	ans = dp[1];

	for(i=2; i<=m; i++){

		dp[i] = d[i].cost;

		for(j=1; j<i; j++){
			if(d[j].e <= d[i].s) dp[i] = MAXV(dp[i], dp[j] + d[i].cost);
			
		}
		ans = MAXV(ans,dp[i]);
	}
	
	printf("%d\n",ans);
	return 0;
}
