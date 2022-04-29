#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

bool A[1002][1002],B[1002][2];
vector<int> vec[1001];

int n,m,a,b,c,d;
int count;
bool flag;

void DFS(int a,int b,int c,int d,int pos)
{
	int i,temp;
//	if(count > 100000) return;
	if(flag) return;
	if(b == a && A[c][d] == false)
	{
		flag = true;
		return;
	}
	if(A[c][d] == false) pos = 1;
	else pos = 0;
	for(i = 0;i < vec[b].size();i++)
	{
		temp = vec[b][i];
		if(B[temp][pos] && A[b][temp])
		{
			B[temp][pos] = false;
			A[b][temp] = false;
			A[temp][b] = false;
			DFS(a,temp,c,d,pos);
//			B[temp] = true;
//			A[b][temp] = true;
//			A[temp][b] = true;
		}
	}
//	count++;
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
		B[b][0] = false;
		B[b][1] = false;
		B[a][0] = false;
		count = 0;
		DFS(a,b,c,d,0);
/*		if(!flag)
		{
			A[a][b] = true;
			A[b][a] = true;
			B[a] = true;
			B[b] = true;
			A[c][d] = false;
			A[d][c] = false;
//			B[c] = false;
			B[d] = false;
			count = 0;
			DFS(c,d,a,b);
		}*/
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
