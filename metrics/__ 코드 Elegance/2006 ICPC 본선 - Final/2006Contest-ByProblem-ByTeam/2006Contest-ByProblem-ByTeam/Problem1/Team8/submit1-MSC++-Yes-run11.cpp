#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testNum, t;

typedef struct _time {
	int hour;
	int min;
	int sec;
} timeType;

timeType curr, end;


int getResult()
{
	char buf[128];
	int res=0;
	int num;
	while(1) {
		sprintf(buf, "%d%d%d", curr.hour, curr.min, curr.sec);
		num=atoi(buf);
		if(num%3==0) res++;
		if(curr.hour==end.hour && curr.min==end.min && curr.sec==end.sec) break;
		curr.sec++;
		if(curr.sec==60) {
			curr.min++;
			curr.sec=0;
		}
		if(curr.min==60) {
			curr.hour++;
			curr.min=0;
		}
		if(curr.hour==24) {
			curr.hour=0;
		}
	}
	return res;
}

int main()
{
	scanf("%d", &testNum);
	for(t=0; t<testNum; t++) {
		scanf("%d%*c%d%*c%d", &curr.hour, &curr.min, &curr.sec);
		scanf("%d%*c%d%*c%d", &end.hour, &end.min, &end.sec);
//		printf("hour : %d min : %d sec : %d\n", end.hour, end.min, end.sec);
		printf("%d\n", getResult());


	}

	return 0;
}