#include <stdio.h>
#include <string.h>

#define MAX 100

char input[MAX][MAX];
char output[MAX];
int chk[27];
char output2[MAX][MAX];
int output3[MAX];
int t,n,m,max,maxN;

void main()
{
	int i,j,k;
	int cnt;

	scanf("%d",&t);
	

	for( i = 0; i < t ;i++){
		scanf("%d %d", &n, &m);
		cnt = 0;
		for( j = 0; j < n; j++){
			
			scanf("%s",input[j]);
		}

		for( k = 0; k < m; k++){
			for( j = 0; j < n; j++) chk[input[j][k]-'A'+1]++;
			
			max = -1;
			maxN = 27;
			for( j = 1; j < 27; j++){
				if( max < chk[j] ){
					maxN = j;
					max = chk[j];
				}
			}
			output[k] = maxN+'A'-1;

			for( j = 1; j < 27; j++){
				if( chk[j] != 0 && j != maxN ){
					cnt = cnt + chk[j];
				}
			}

			for( j = 1; j < 27; j++) chk[j] = 0;
		}

		
		for( j = 0; j < m; j++){
			output2[i][j] = output[j]; 
		}
		output3[i] = cnt;		
	}


	for( i = 0; i < t; i++){
		printf("%s\n", output2[i]);
		printf("%d\n",output3[i]);
	}
}