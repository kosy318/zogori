#include <stdio.h>
#include <algorithm>
using namespace std;

int pp[100000];

int main()
{
	int t;
	scanf("%d", &t);
	int i;
	for (i=0; i<t; i++)
	{
		int n, kk;
		scanf("%d %d", &n, &kk);
		int j, k;
		for (j=0; j<n; j++)
			scanf("%d", &pp[j]);
		sort(pp, pp+n);
		int res = 1;
		for (j=0; j<n; j++)
			for (k=j+1; k<n; k++)
			{
				if ( pp[k]-pp[k-1]>kk ) break;
				if ( k>j+1 ) if ( pp[k]-pp[k-2]>kk ) break;
				if ( res < k-j+1 ) res = k-j+1;
			}
		printf("%d\n", res);
	}
}