#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNO 235959
int list2[240000];
int list[240000];
char buff[100], buff1[100], buff2[100];

int main(){
	int n, i, j, len, temp, temp1, temp2, cnt;
	
	memset(list, 0, sizeof(list));
	memset(list2, 0, sizeof(list2));
	
	list[0] = 1;
	list2[0] = 1;
	for(i = 1 ; i < 235960; i++){
		sprintf(buff, "%06d", i);
		if((buff[0] > '2') ||(buff[2] > '6') ||(buff[4] > '6')||((buff[0] == '2')&&(buff[1] > '3'))||(buff[2] == '6')&&(buff[3] >='0')||(buff[4] == '6')&&(buff[5] >='0')){
			list[i] = list[i-1];
			//printf("%d %d\n", i, list[i]);
		}
		else{
			/*len = strlen(buff);
			temp = 0;
			for(j = 0; j < len; j++){
				temp = temp + buff[j] -'0';
			}
			temp = temp % 3;*/
			temp = i % 3;
			if(temp == 0){
				list[i] = list[i-1] + 1;
				list2[i] = 1;
			}
			else list[i] = list[i-1];
		}
		//printf("%d %d\n", i, list[i]);
	}

	gets(buff);
	sscanf(buff, "%d", &n);
	cnt = 0;
	for(i = 0; i<n; i++){
		gets(buff);
		sscanf(buff, "%s %s", buff1, buff2);
		buff1[2] = buff1[3];
		buff1[3] = buff1[4];
		buff1[4] = buff1[6];
		buff1[5] = buff1[7];
		buff1[6] = '\0';

		buff2[2] = buff2[3];
		buff2[3] = buff2[4];
		buff2[4] = buff2[6];
		buff2[5] = buff2[7];
		buff2[6] = '\0';
	
		sscanf(buff1, "%d", &temp1);
		sscanf(buff2, "%d", &temp2);

		if(temp2 > temp1)
			printf("%d", list[temp2] - list[temp1] + list2[temp1]);
		else if(temp2 < temp1)
			printf("%d", list[MAXNO] - list[temp1] + list2[temp1] + list[temp2]);
		cnt++;
		if(cnt != n)
			printf("\n");
		

		//printf("%d %d %d\n%d %d %d\n", temp1, list[temp1], list2[temp1], temp2, list[temp2], list2[temp2]);
	}
	return 0;
}


	
		