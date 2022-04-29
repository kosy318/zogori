#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
struct P
{
	int a,b;
};

bool operator<(P lhs,P rhs)
{
	return lhs.a>rhs.a?true:false;
}
void main(){

	int i,j,k,t,n,M,res[10000],sum,idx,flag,flag2;
	P G[20];
	cin>>t;
	while(t--)
	{
		cin >> n;
		for(i=0;i<n;i++)
		{
			cin >> G[i].a >> G[i].b;
		}
		cin >> M;
		sort(G,G+n);
		for(idx=0,i=1;i<M;i++)
		{
			if(((G[1].a*i+G[1].b)%G[0].a)==(G[0].b%G[0].a))
			{
				res[idx++]=G[1].a*i+G[1].b;
			}
		}
		j=0;
		for(k=0;k<idx;k++)
		{
			sum=(res[k]-G[0].b)/G[0].a+(res[k]-G[1].b)/G[1].a; i=2; flag=flag2=0;
			while(i<n)
			{
				if((res[k]-G[i].b)%G[i].a==0) sum+=(res[k]-G[i].b)/G[i].a,i++;
				else {flag=1; break;}
			}
			if(!flag)
			{
				if(sum==M) {flag2=1; break;}
			}
		}
		if(flag2) cout << res[k] << endl;
		else cout << "0" << endl;
	}
}