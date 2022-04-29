#include<stdio.h>

int d[10001];
int main()
{
	int i,n,k;
	bool flag;

	scanf("%d",&n);
	
	d[0] = 1; d[1] = 1;
	for(i=2; i<=n; i++){
		for(d[i]=1;; d[i]++){
			flag = 0;
			for(k=1; 2*k<=i; k++){
				if(d[i-2*k] - d[i-k] == d[i-k] - d[i]) flag = 1;
			}
			if(flag == 0) break;
		}
	}
	
	printf("%d",d[n]);
	return 0;
}
