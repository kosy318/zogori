#include <stdio.h>

int A[33], B[33], N, M;

int main(void){

	int test, tt, maxb;

	int hap, flag;

	int i, j;

	scanf("%d", &test);

	for(tt= 1 ; tt <= test ; tt ++){

		maxb = 1;

		scanf("%d", &N);
		for(i=1;i<=N;i++){
			scanf("%d %d", &A[i], &B[i]);
			if(maxb < B[i]){
				maxb = B[i];
			}
		}
		scanf("%d", &M);

		for(i=maxb;;i++){

			hap = 0;
			flag = 1;

			for(j=1;j<=N;j++){
				hap += ( i - B[j]) / A[j];
				if( ( i - B[j] ) % A[ j] != 0){
					flag   = 0;
				}
			}
			if(flag && hap == M){
				printf("%d\n", i);
				break;
			}
			if(hap > M){
				printf("0\n");
				break;
			}
		}
	}

	return 0;

}