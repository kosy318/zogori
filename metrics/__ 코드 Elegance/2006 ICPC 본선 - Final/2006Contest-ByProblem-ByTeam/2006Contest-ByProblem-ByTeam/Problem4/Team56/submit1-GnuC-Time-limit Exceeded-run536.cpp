#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

bool A[1002][1002],B[1002];
vector<int> vec[1001];

int n,m,a,b,c,d;
bool flag;

void DFS(int a,int b,int c,int d)
{
	int i,temp;
	if(flag) return;
	if(b == a && A[c][d] == false)
	{
		flag = true;
		return;
	}
	for(i = 0;i < vec[b].size();i++)
	{
		temp = vec[b][i];
		if(B[temp] && A[b][temp])
		{
			B[temp] = false;
			A[b][temp] = false;
			A[temp][b] = false;
			DFS(a,temp,c,d);
			B[temp] = true;
			A[b][temp] = true;
			A[temp][b] = true;
		}
	}
}

int main()
{
	int cas,i,x,y,l;
	scanf("%d",&cas);
	for(;cas > 0;cas--)
	{
		memset(A,false,sizeof(A));
		scanf("%d %d",&n,&m);
		for(i = 1;i <= n;i++) vec[i].clear();
		for(i = 0;i < m;i++)
		{
			scanf("%d %d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
			A[x][y] = true;
			A[y][x] = true;
		}
		scanf("%d %d",&a,&b);
		scanf("%d %d",&c,&d);
		memset(B,true,sizeof(B));
		scanf("%d",&l);
		for(i = 0;i < l;i++)
		{
			scanf("%d %d",&x,&y);
			A[x][y] = false;
			A[y][x] = false;
		}
		flag = false;
		A[a][b] = false;
		A[b][a] = false;
//		B[a] = false;
		B[b] = false;
		DFS(a,b,c,d);
		if(!flag)
		{
			A[a][b] = true;
			A[b][a] = true;
			B[a] = true;
			B[b] = true;
			A[c][d] = false;
			A[d][c] = false;
//			B[c] = false;
			B[d] = false;
			DFS(c,d,a,b);
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
