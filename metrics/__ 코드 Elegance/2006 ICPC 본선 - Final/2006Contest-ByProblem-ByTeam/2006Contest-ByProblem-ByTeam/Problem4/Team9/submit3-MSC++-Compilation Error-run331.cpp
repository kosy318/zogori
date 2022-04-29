#include<stdio.h>
#include<algorithm>
#include<queue>
#define SIZE 1001

using namespace std;

int n,m;
int adj[SIZE][SIZE];

pair<int,int> want[2];

bool Process(int start,int end,int n1,int n2)
{
	if(start==end) return true;

	int check[SIZE];
	fill(check,check+n,0);

	check[n1]=1; check[n2]=1;

	queue<int> q;

	q.push(start);
	check[start]=1;

	while(!q.empty())
	{
		int cur=q.front();
		if(cur==end) return true;

		for(int i=0;i<n;i++)
		{
			if(check[i]) continue;

			if(adj[cur][i])
			{
				check[i]=1;
				if(i==end) return true;
f
				q.push(i);
			}
		}
		q.pop();
	}
	return false;;
}
int main()
{
//	freopen("input.txt","r",stdin);

	int tn;
	scanf("%d",&tn);

	while(tn--)
	{
		scanf("%d %d",&n,&m);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				adj[i][j]=0;
			}
		}
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);

			a--; b--;

			adj[a][b]=adj[b][a]=1;
		}
		for(int i=0;i<2;i++)
		{
			scanf("%d %d",&want[i].first,&want[i].second);
			want[i].first--; want[i].second--;
		}

		int f;
		scanf("%d",&f);
		for(int i=0;i<f;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			a--; b--;

			adj[a][b]=adj[b][a]=0;
		}

		if(!adj[want[0].first][want[0].second] || !adj[want[1].first][want[1].second])
		{
			printf("NO\n"); continue;
		}
		adj[want[0].first][want[0].second] = adj[want[0].second][want[0].first] = 0;
		adj[want[1].first][want[1].second] = adj[want[1].second][want[1].first] = 0;

		bool flag1 = Process(want[0].first,want[1].first,want[0].second,want[1].second);
		bool flag2 = Process(want[0].second,want[1].second,want[0].first,want[1].first);

		if(flag1 && flag2)
		{
			printf("YES\n"); continue;
		}

		flag1 = Process(want[0].first,want[1].second,want[0].second,want[1].first);
		flag2 = Process(want[0].second,want[1].first,want[0].first,want[1].second);

		if(flag1 && flag2)
		{
			printf("YES\n"); continue;
		}

		printf("NO\n");
	}

	return 0;
}