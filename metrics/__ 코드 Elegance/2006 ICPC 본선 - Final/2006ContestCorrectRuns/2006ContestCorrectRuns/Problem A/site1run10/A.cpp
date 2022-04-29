#include <stdio.h>

int Time[ 244444 ];

int main(void){

	int i, j, k, t;

	for(i=0;i<=23;i++){
		for(j=0;j<=59;j++){
			for(k=0;k<=59;k++){
				t = i * 10000 + j * 100 + k;
				if(t % 3 == 0){
					Time[t] = 1;
				}
			}
		}
	}

	for(i=1;i<=235959;i++){
		Time [i] += Time[i-1];
	}

	int T;

	char T1[20], T2[20];
	int t1, t2;

	scanf("%d", &T);

	for(i=1;i<=T;i++){
		scanf("%s", T1);
		scanf("%s", T2);
		for(j=0;j<=7;j++){
			T1[j] -= '0';
			T2[j] -= '0';
		}
		t1 = T1[0]*100000 + T1[1]*10000 + T1[3]*1000 + T1[4] * 100 + T1[6] *10 + T1[7];
		t2 = T2[0]*100000 + T2[1]*10000 + T2[3]*1000 + T2[4] * 100 + T2[6] *10 + T2[7];

		if(t2 < t1){
			if(t1 - t2 == 1){
				printf("%d\n", Time[235959]);
			}
			else{
				printf("%d\n", Time[235959] - ( Time[t1-1] - Time[t2] ));
			}
		}
		else if(t1 == 0){
			printf("%d\n", Time[ t2]);
		}
		else{
			printf("%d\n", Time[t2] - Time[t1 - 1]) ;
		}

	}

	return 0;

}