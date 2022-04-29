#include <stdio.h>

int N, A[22], B[22], M;

int D[22][101111];

int main(void){
	int t, r, tt;

	int i, j;

	scanf("%d", &t);

	for(r=1;r<=t;r++){

		scanf("%d", &N);
		for(i=1;i<=N;i++){
			scanf("%d %d", &A[i], &B[i]);
		}
		scanf("%d", &M);

		for(i=1;i<N;i++){
			for(j=2;j<=N;j++){
				if(A[i] < A[j]){
					tt = A[i];
					A[i] = A[j];
					A[j] = tt;
					
					tt = B[i];
					B[i] = B[j];
					B[j] = tt;

				}
			}
		}


		for(i=1;i<=N;i++){
			for(j=1;j<=101000;j++){
				D[i][j] = -1;
			}
		}

		for(i=1;i<=N;i++){
			for(j=0;j<=M;j++){
				D[i][A[i]*j + B[i]] = j;
			}
		}


		int T = 0;


		for(i=1;i<=101000;i++){
			T = 0;
			tt = 0;
			for(j=1;j<=N;j++){
				if(D[j][i] == -1){
					tt = 1;
				}
				else{
					T += D[j][i];
				}
			}
			if(tt == 0 && T == M){
				printf("%d\n", i);
				break;
			}
			else if( T > M){
				printf("0\n");
				break;
			}
		}
		if(i== 101001){
			printf("0\n");
		}

		


	}


	return 0;
}