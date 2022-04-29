#include<stdio.h>
#include<stdlib.h>


void main(){
	int num, hour, min, sec, i, hour2, min2, sec2, j, start, end;
	char value[20];
	char temp[3];
	int count;
	scanf("%d", &num);
	gets(temp);
	for(i=0; i<num; i++){
		gets(value);
		//printf("%s", value);
		temp[0]=value[0]; temp[1]=value[1]; temp[2]='\n';
		hour=atoi(temp);
		//printf("%d ", hour);

		temp[0]=value[3]; temp[1]=value[4]; temp[2]='\n';
		min=atoi(temp);
		//printf("%d", min);

		temp[0]=value[6]; temp[1]=value[7]; temp[2]='\n';
		sec=atoi(temp);
		//printf("%d ", sec);

		temp[0]=value[9]; temp[1]=value[10]; temp[2]='\n';
		hour2=atoi(temp);

		temp[0]=value[12]; temp[1]=value[13]; temp[2]='\n';
		min2=atoi(temp);

		temp[0]=value[15]; temp[1]=value[16]; temp[2]='\n';
		sec2=atoi(temp);

		start=10000*hour+100*min+sec;
		end=10000*hour2+100*min2+sec2;
	//	printf("%d %d ", start, end);
		if(start>end){
			end+=240000;
		}

		count=0;
		for(j=start; j<=end; j++){
			if(j%100==60){
				j-=60;
				j+=100;
			}
			if(j%10000>=6000){
				j-=6000;
				j+=10000;
			}
			if(j%3==0){
				count++;
			}
		}
		printf("%d\n", count);

		

	}
}