#include <stdio.h>


typedef struct time{
	int hh, mm, ss;
}time;
int main()
{
	char start[9], end[9];
	time s_t, e_t;
	int test, cnt, i, j, loop;

	scanf("%d", &test);

	while(test) {
		scanf("%s", start);
		scanf("%s", end);

		
		s_t.hh = (start[0]-'0')*10 + (start[1]-'0');
		s_t.mm = (start[3]-'0')*10 + (start[4]-'0');
		s_t.ss = (start[6]-'0')*10 + (start[7]-'0');

		e_t.hh = (end[0]-'0')*10 + (end[1]-'0');
		e_t.mm = (end[3]-'0')*10 + (end[4]-'0');
		e_t.ss = (end[6]-'0')*10 + (end[7]-'0');
		
		
		if(s_t.hh > e_t.hh) e_t.hh += 24;
		
		cnt = 0, loop = 1;
		
		if((s_t.hh == e_t.hh)&&(s_t.mm == e_t.mm)) {
			for(s_t.ss; s_t.ss <= e_t.ss; s_t.ss++) {
				if((((s_t.hh%10 + s_t.hh/10) + (s_t.mm%10 + s_t.mm/10) + (s_t.ss%10 + s_t.ss/10))%3) == 0) {
					cnt++;
				}
			}
		} else {
			for(s_t.ss; s_t.ss <= 59; s_t.ss++) {
				if((((s_t.hh%10 + s_t.hh/10) + (s_t.mm%10 + s_t.mm/10) + (s_t.ss%10 + s_t.ss/10))%3) == 0) {
					cnt++;
				}
			}
			if(s_t.mm == 59) {
				s_t.mm = 0;
				s_t.hh++;
			} else {
				s_t.mm++;
			}

			if(s_t.hh == e_t.hh) {
				for(s_t.mm; s_t.mm<e_t.mm; s_t.mm++) {
					cnt += 20;
				}
				for(s_t.ss = 0; s_t.ss <= e_t.ss; s_t.ss++) {
					if((((s_t.hh%10 + s_t.hh/10) + (s_t.mm%10 + s_t.mm/10) + (s_t.ss%10 + s_t.ss/10))%3) == 0) {
						cnt++;
					}
				}
			} else {
				for(s_t.mm; s_t.mm<=59; s_t.mm++) {
						cnt += 20;
				}
				s_t.hh++;
				
				for(s_t.hh; s_t.hh<e_t.hh; s_t.hh++) {
					for(s_t.mm = 0; s_t.mm<=59; s_t.mm++) {
						cnt += 20;
					}
				}
				for(s_t.mm=0; s_t.mm<e_t.mm; s_t.mm++) {
					cnt += 20;
				}
				for(s_t.ss = 0; s_t.ss <= e_t.ss; s_t.ss++) {
					if((((s_t.hh%10 + s_t.hh/10) + (s_t.mm%10 + s_t.mm/10) + (s_t.ss%10 + s_t.ss/10))%3) == 0) {
						cnt++;
					}
				}
			}
		}
		printf("%d\n", cnt);

		test--;
	}
	return 0;
}