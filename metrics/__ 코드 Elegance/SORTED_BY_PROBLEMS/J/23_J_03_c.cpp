#include<stdio.h>
#define MaxN 1000001

int d[MaxN];

int main()
{
	int i,n;
	scanf("%d",&n);

	d[3] = 0; d[4] = 1;
	
	for(i=5; i<=n; i++){
		if(i%2 == 0) d[i] = d[i/2] + 2;
		else d[i] = d[(i+1)/2] + 2;
	}

	printf("%d",d[n]);
	return 0;
}
