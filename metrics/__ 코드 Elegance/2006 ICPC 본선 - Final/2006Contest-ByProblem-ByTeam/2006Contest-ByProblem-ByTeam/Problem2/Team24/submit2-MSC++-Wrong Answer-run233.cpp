#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	int t,m,n;
	scanf ("%d",&t);
	int arr[4][1003];
	for (int i=0;i<t;++i)
	{
		scanf ("%d %d", &m,&n);
		memset (arr,0,sizeof(int)*4*1003);
		for (int j=0;j<m;++j)
		{
			char str[1004];
			scanf ("%s",str);

			for (int k=0;k<n;++k)
			{
				if (str[k]=='T')
				{
					++arr[0][k];
				}
				else if (str[k]=='G')
				{
					++arr[1][k];
				}
				else if (str[k]=='C')
				{
					++arr[2][k];
				}
				else if (str[k]=='A')
				{
					++arr[3][k];
				}
			}
		}
		int result=0;
		char re[1003];
		memset (re,0,sizeof(char)*1003);
		for (j=0;j<n;++j)
		{
			int index=0;
			int max=arr[0][j];
			for (int k=1;k<4;++k)
			{
				if (arr[k][j] > max)
				{
					index = k;
					max= arr[k][j];
				}
			}
			if (index == 0)
				re[j]='T';
			else if (index == 1)
				re[j]='G';
			else if (index == 2)
				re[j]='C';
			else if (index == 3)
				re[j]='A';
			for (k=0;k<4;++k)
			{
				if (k!=index)
				{
					result += arr[k][j];
				}
			}
		}
		printf ("%s\n%d\n",re,result);
	}
}