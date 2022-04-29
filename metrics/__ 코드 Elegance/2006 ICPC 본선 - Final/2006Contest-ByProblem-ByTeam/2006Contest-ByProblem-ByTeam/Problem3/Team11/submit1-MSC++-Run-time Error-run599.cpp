// wc.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>

int a[50001][3];
int b[50001][3];
int c[50001][500001];
int maxline1;
int maxline2;
int maxlinevalue;
int max1,max2;

void input(int c1,int c2)
{
	int i;
	if (c[c1][c2]==1) return;
	c[c1][c2]=1;
	if (a[c1][0]>c2)
	{
		a[c1][0]=c2;
		a[c1][2]=a[c1][1]-c2+1;
		if (c2<a[c1][1])
		{
			for (i=c2+1;i<a[c1][1];i++)
			{
				input(c1,i);
			}
		}
	}
	if (a[c1][1]<c2)
	{
		a[c1][1]=c2;
		a[c1][2]=c2-a[c1][0]+1;
		if (c2>a[c1][0])
		{
			for (i=a[c1][0]+1;i<c2;i++)
			{
				input(c1,i);
			}
		}
	}
	if (maxlinevalue<a[c1][2])
	{
		//printf("a1 %d %d\n",c1,c2);
		maxlinevalue=a[c1][2];
		maxline1=1;
		maxline2=c1;
		//printf("a1 %d %d %d\n",c1,c2,maxlinevalue);
	}

	if (b[c2][0]>c1)
	{
		b[c2][0]=c1;
		b[c2][2]=b[c2][1]-c1+1;
		if (c1<b[c2][1])
		{
			for (i=c1+1;i<b[c2][1];i++)
			{
				input(i,c2);
			}
		}
	}
	if (a[c2][1]<c1)
	{
		b[c2][1]=c1;
		b[c2][2]=c1-b[c2][0]+1;
		if (c1>b[c2][0])
		{
			for (i=b[c2][0]+1;i<c1;i++)
			{
				input(i,c2);
			}
		}
	}
	if (maxlinevalue<b[c2][2])
	{		
		maxlinevalue=b[c2][2];
		maxline1=2;
		maxline2=c2;
	}

}

int main()
{

	int i,j,k,n,m,j1,j2,sum;

	
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&max1,&max2);
		scanf("%d",&m);
		for (j=0;j<max1;j++)
		{
			a[j][0]=max1;
			a[j][1]=0;
			a[j][3]=0;
			for (k=0;k<max2;k++)
			{
				c[j][k]=0;
			}
		}
		for (j=0;j<max2;j++)
		{
			b[j][0]=max2;
			b[j][1]=0;
			b[j][3]=0;
		}
		maxlinevalue=0;
		sum=0;
		for (j=0;j<m;j++)
		{
			scanf("%d %d",&j1,&j2);
			if (j1>0&&j2<max2)		input(j1-1,j2);
			if (j1<max1&&j2<max2)	input(j1,j2);
			if (j1>0&&j2>0)			input(j1-1,j2-1);
			if (j1<max1&&j2>0)		input(j1,j2-1);			
		}

		
		
		for(j=0;j<max1;j++)
		{
			sum+=a[j][2];
		}
		
		if (maxline1==1)
		{
			sum+=max1-a[maxline2][2];
		}
		if (maxline1==2)
		{
			sum+=max2-b[maxline2][2];
		}

		printf("%d\n",sum);
		

	}

	return 0;
}

