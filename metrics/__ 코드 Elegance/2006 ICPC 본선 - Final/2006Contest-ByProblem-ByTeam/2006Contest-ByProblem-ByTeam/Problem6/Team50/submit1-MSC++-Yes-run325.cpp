#include <stdio.h>


void main() {
	int m,p,n,i,j,M,min,min2,minj,ll,sw,tot,k;
	int data[50][2];
	scanf("%d",&m);
	for (p=1; p<=m; p++) {
		scanf("%d",&n);
		for (i=1; i<=n; i++) {
			scanf("%d %d",&data[i][0],&data[i][1]);
		}
		scanf("%d",&M);
		min=210000000;
		for (j=1; j<=n; j++) {
			if (M*data[j][0]+data[j][1]<min) min=M*data[j][0]+data[j][1];
		}
		min2=210000000;
		for (j=1; j<=n; j++) {
			if ((min-data[j][1])/data[j][0]< min2) {
				min2=(min-data[j][1])/data[j][0];
				minj=j;
			}
		}
		for (j=1; j<=min2; j++) {
			ll=data[minj][0]*j+data[minj][1];
			sw=0;tot=0;
			for (k=1; k<=n; k++) {
				if ((ll-data[k][1])%data[k][0]==0) {
					tot+=(ll-data[k][1])/data[k][0];
				}
				else {
					sw=1;
					break;
				}
			}
			if (sw==0 && tot==M) {
				printf("%d\n",ll);
				break;
			}
		}
		if(j > min2)
		{
			printf("%d\n", 0);
		}
	}
}