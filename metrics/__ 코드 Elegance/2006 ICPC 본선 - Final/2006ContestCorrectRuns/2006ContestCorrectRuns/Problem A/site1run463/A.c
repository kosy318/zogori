#include<stdio.h>
#include<math.h>

#define mid 0

int main() {

	unsigned long int start, end;
	int i;
	int T;
	int time;
	int num;
	int hour, min, sec;
	char sh1, sh2, sm1, sm2, ss1, ss2;
	char eh1, eh2, em1, em2, es1, es2;
	char colon, blank;

	scanf("%d%c", &T, &blank);
	for(i=0; i<T; i++) {
		num=0;
		scanf("%c%c%c%c%c%c%c%c%c", &sh1, &sh2, &colon, &sm1, &sm2, &colon, &ss1, &ss2, &blank);
		scanf("%c%c%c%c%c%c%c%c%c", &eh1, &eh2, &colon, &em1, &em2, &colon, &es1, &es2, &blank);

//		printf("%uld %uld %uld %uld %uld %uld\n", (sh1-'0')*10*10*10*10*10, (sh2-'0')*10*10*10*10, (sm1-'0')*10*10*10, (sm2-'0')*10*10, (ss1-'0')*10, (ss1-'0')*1);
		start = (sh1-'0')*10*10*10*10*10 + (sh2-'0')*10*10*10*10 + (sm1-'0')*10*10*10 + (sm2-'0')*10*10 + (ss1-'0')*10 + (ss2-'0')*1;
		end   = (eh1-'0')*10*10*10*10*10 + (eh2-'0')*10*10*10*10 + (em1-'0')*10*10*10 + (em2-'0')*10*10 + (es1-'0')*10 + (es2-'0')*1;

		if(end >= start) {
			for(time=start; time<=end; time++) {
				sec = time%100;
				min = ((time-sec)/100)%100;
				hour = ((time-min*100-sec)/100)%100;

				if(0<=sec && sec<=59 && 0<=min && min<=59 && 0<=hour && hour<=23) {
					if(time%3==0)
							num++;
				}
			}
		} 
		else {
			for(time=start; time<=235959; time++) {
				sec = time%100;
				min = ((time-sec)/100)%100;
				hour = ((time-min*100-sec)/100)%100;

				if(0<=sec && sec<=59 && 0<=min && min<=59 && 0<=hour && hour<=23) {
					if(time%3==0)
							num++;
				}
			}
			for(time=mid; time<=end; time++) {
				sec = time%100;
				min = ((time-sec)/100)%100;
				hour = ((time-min*100-sec)/100)%100;

				if(0<=sec && sec<=59 && 0<=min && min<=59 && 0<=hour && hour<=23) {
					if(time%3==0)
							num++;
				}
			}
		} 
		
		printf("%d\n", num);
	}
	return 0;
}