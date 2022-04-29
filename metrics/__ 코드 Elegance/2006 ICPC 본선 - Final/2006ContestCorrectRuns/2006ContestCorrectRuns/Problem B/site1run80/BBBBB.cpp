#include <stdio.h>
#include <string.h>

int n, len, T, min;
char data[51][1001];
char outcome[1001];

int main()
{
	int i, j, k, asdf;
	int A, C, G, Ta;
	scanf("%d",&Ta);
	for(asdf=0;asdf<Ta;asdf++)
	{
		scanf("%d %d",&n,&len);
		for(i=0;i<n;i++)
		{
			scanf("%s ",data[i]);
		}
		for(k=0;k<len;k++)
		{
			A = 0;		C = 0;		G = 0;		T = 0;
			for(i=0;i<n;i++)
			{
				if( data[i][k] == 'A' )
				{
					A++;
				}
				if( data[i][k] == 'C' )
				{
					C++;
				}
				if( data[i][k] == 'G' )
				{
					G++;
				}
				if( data[i][k] == 'T' )
				{
					T++;
				}
				if( A >= C && A >=  G && A >=  T )
				{
					outcome[k] = 'A';
				}
				else if( C >=  A && C >=  G && C >=  T )
				{
					outcome[k] = 'C';
				}
				else if( G >=  A && G >=  C && G >=  T )
				{
					outcome[k] = 'G';
				}
				else if( T >=  A && T >=  C && T >=  G )
				{
					outcome[k] = 'T';
				}
			}
		}
		min = 0;
		for(i=0;i<n;i++)
		{
			for(k=0;k<len;k++)
			{
				if( outcome[k] != data[i][k] )
				{
					min++;
				}
			}
		}
		for(k=0;k<len;k++)
		{
			printf("%c",outcome[k]);
		}
		printf("\n");
		printf("%d\n",min);
	}

}