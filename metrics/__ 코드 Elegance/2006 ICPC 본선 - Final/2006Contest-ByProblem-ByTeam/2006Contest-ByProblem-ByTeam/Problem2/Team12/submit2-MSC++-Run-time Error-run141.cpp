#include<stdio.h>
#include<stdlib.h>

void main(){
	int num, i, j, k, max, refer, differ;
	int low, col;
	int count[4];
	char mid[4]={'A', 'C', 'G', 'T'};
	char **value;
	char *result;
	scanf("%d", &num);
	for(i=0; i<num; i++){
		scanf("%d %d", &low, &col);
		value=(char**)malloc(low*sizeof(char*));
		result=(char*)malloc(col*sizeof(char));
		for(j=0; j<low; j++){
			value[j]=(char*)malloc(col*sizeof(char));
			scanf("%s", value[j]);
		}
		
		for(j=0; j<col; j++){
			for(k=0;k<4; k++){
				count[k]=0;
			}
			for(k=0; k<low; k++){
				if(value[k][j]=='A'){
					count[0]++;
				}
				else if(value[k][j]=='C'){
					count[1]++;
				}
				else if(value[k][j]=='G'){
					count[2]++;
				}
				else{
					count[3]++;
				}
			}
			max=count[0]; 
			refer=0;
			for(k=1; k<4; k++){
				if(max<count[k]){
					max=count[k];
					refer=k;
				}
			}
			if(refer==0){
				result[j]='A';
			}
			else if(refer==1){
				result[j]='C';
			}
			else if(refer==2){
				result[j]='G';
			}
			else if(refer==3){
				result[j]='T';
			}
		}
		differ=0;
		for(j=0; j<col; j++){
			printf("%c", result[j]);
		}

		for(j=0; j<col; j++){
			for(k=0; k<low; k++){
				if(value[k][j]!=result[j]){
					differ++;
				}
			}
		}
		printf("\n%d\n", differ);
	}
}
		
		