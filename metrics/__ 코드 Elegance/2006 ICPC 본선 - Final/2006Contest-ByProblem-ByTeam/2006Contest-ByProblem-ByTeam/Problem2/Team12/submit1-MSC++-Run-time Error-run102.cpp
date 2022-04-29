#include<stdio.h>
#include<stdlib.h>

void main(){
	int num, i, j, k, max, refer, differ;
	int low, col;
	int count[4];
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
		differ=0;
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
			for(k=0; k<4; k++){
			//	printf("%d ", count[k]);
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
				printf("A");
				for(k=0; k<low; k++){
					if(value[k][j]!='A'){
						differ++;
					}
				}
			}
			else if(refer==1){
				printf("C");
				for(k=0; k<low; k++){
					if(value[k][j]!='C'){
						differ++;
					}
				}
			}
			else if(refer==2){
				printf("G");
				for(k=0; k<low; k++){
					if(value[k][j]!='G'){
						differ++;
					}
				}
			}
			else if(refer==3){
				printf("T");
				for(k=0; k<low; k++){
					if(value[k][j]!='T'){
						differ++;
					}
				}
			}
		}
		printf("\n%d\n", differ);
	}
}
		
		