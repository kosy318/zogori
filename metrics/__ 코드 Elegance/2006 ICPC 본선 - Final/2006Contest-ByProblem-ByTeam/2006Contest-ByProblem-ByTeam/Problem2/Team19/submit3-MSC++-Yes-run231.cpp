#include <stdio.h>

char DNA[50][1000];
char END[1000];
int TGCA[4] = {0};

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		
		int error = 0;
		int m,n;

		scanf("%d %d",&m,&n);
		
		int i,j;
		for(i=0;i<m;i++)
			scanf("%s",DNA[i]);
		
		for(i=0;i<n;i++){
			for(j = 0; j<4;j++) TGCA[j] = 0;
			
			for(j=0;j<m;j++){
				switch(DNA[j][i]){
					case 'A':
						TGCA[0]++;
						break;
					case 'C':
						TGCA[1]++;
						break;
					case 'G':
						TGCA[2]++;
						break;
					case 'T':
						TGCA[3]++;
						break;
				}
			}

			int MAX=0;
			for(j=0;j<4;j++){
				if(TGCA[MAX] < TGCA[j]){
						MAX = j;
				}
			}
			
			for(j = 0; j < 4; j++)
			{
				if(MAX != j)
				{
					error += TGCA[j];
				}
			}

			switch(MAX){
					case 0:
						END[i] = 'A';
						break;
					case 1:
						END[i] = 'C';
						break;
					case 2:
						END[i] = 'G';
						break;
					case 3:
						END[i] = 'T';
						break;
			}
			

		}
		END[i] = '\0';
		printf("%s\n",END);
		printf("%d\n",error);
	}
	return 0;
}