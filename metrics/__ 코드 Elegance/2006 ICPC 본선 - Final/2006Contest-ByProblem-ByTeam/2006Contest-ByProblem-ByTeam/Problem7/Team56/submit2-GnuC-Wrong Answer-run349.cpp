#include <stdio.h>
#include <algorithm>
using namespace std;

struct point
{
	int x,y,d,pos;
};

point A[1002];
int B[1002][2];

bool cmp(const point A,const point B)
{
	if(A.x != B.x)
		return A.x < B.x;
	return A.y < B.y;
}
bool cmp2(const point A,const point B)
{
	if(A.y != B.y)
		return A.y < B.y;
	return A.x < B.x;
}

int main()
{
	int cas,n,i,j,e;
	scanf("%d",&cas);
	for(;cas > 0;cas--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			A[i].pos = i;
			scanf("%d %d %d",&A[i].x,&A[i].y,&A[i].d);
		}
		sort(A,A+n,cmp);
		e = 0;
		for(i = 0;i < n;i++)
		{
			if(A[i].d != 0)
				for(j = 0;j < n;j++)
				{
					if(A[i].d == 0) break;
					if(A[j].d != 0 && i != j && (A[i].d > 1 || A[j].d > 1))
					{
						B[e][0] = A[i].pos;
						B[e++][1] = A[j].pos;
						A[i].d--;
						A[j].d--;
					}
				}
		}
		sort(A,A+n,cmp2);
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(i!=j && A[i].d == 1 && A[j].d == 1)
				{
					B[e][0] = A[i].pos;
					B[e++][1] = A[j].pos;
					A[i].d--;
					A[j].d--;
				}
			}
		}
		for(i = 0;i < e;i++)
			printf("%d %d\n",B[i][0]+1,B[i][1]+1);
	}
	return 0;
}

