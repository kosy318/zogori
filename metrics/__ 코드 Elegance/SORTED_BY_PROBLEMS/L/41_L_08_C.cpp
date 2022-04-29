#include <bits/stdc++.h>
#define L long long

using namespace std;

L m,n;
L val[20020];
vector<pair<L,L> >v[20020];
L dp[20020];

int main()
{
	scanf("%lld %lld",&m,&n);
	L i,j;
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&val[i]);
	}
	for(i=1;i<=n;i++)
	{
		L s,e,c;
		scanf("%lld %lld %lld",&s,&e,&c);
		v[e].push_back(make_pair(s,val[c]));
	}
	for(i=1;i<=15001;i++)
	{
		dp[i]=dp[i-1];
		for(j=0;j<v[i].size();j++)
		{
			//printf("%lld %lld\n",v[i][j].first,i);
			dp[i]=max(dp[i],dp[v[i][j].first]+v[i][j].second*(i-v[i][j].first));
		}
	}
	printf("%lld",dp[15001]);
}
