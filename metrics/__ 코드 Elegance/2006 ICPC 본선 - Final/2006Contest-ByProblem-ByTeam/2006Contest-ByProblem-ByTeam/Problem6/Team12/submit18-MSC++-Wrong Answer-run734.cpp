#include <stdio.h>

void main(){
	int num,  i, j, number, sum, temp, k;
	long int low, high;
	long int value[4000]={0};
    
	scanf("%d", &num);
	for(i=0; i<num; i++){
		for(j=0; j<4000; j++){
			value[j]=0;
		}
		scanf("%d", &number);

		for(j=0; j<number*2; j++){
			scanf("%d",&value[j]);
		}
		scanf("%d", &sum);
		low=0;
		for(j=0; j<number*2; j=j+2){
			temp=1;
			for(k=0; k<number*2; k=k+2){
				if(j!=k){
					temp=temp*value[k];
				}
			}
			low=low+temp;
		}

		high=sum;

		for(j=0; j<number*2; j=j+2){
			high=high*value[j];
		}

		for(j=1; j<number*2; j=j+2){
			temp=value[j];
			for(k=0; k<number*2; k=k+2){
				if(k!=j-1){
					temp=temp*value[k];
				}
			}
			high=high+temp;
		}
		if(low==0 || high==0){
			printf("0\n");
		}
		for(j=0; j<high; j++){
			if(low*j==high){
				break;
			}
		}
		if(j!=high){
			printf("%d\n", high/low);
		}
		else{
			printf("0\n");
		}		
	}
}
