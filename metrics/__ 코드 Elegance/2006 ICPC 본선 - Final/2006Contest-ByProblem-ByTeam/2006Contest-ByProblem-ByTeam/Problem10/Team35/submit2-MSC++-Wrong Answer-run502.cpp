#include <stdio.h>
#include <stdlib.h>

int T, r, N, K, St[5002], Answer;


int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(void){

	int i, j;

	scanf("%d", &T);

	int go;

	int en, now;

	for(r=1;r<=T;r++){

		scanf("%d %d", &N, &K);

		for(i=1;i<=N;i++){
			scanf("%d", &St[i]);
//			St[i][1] = i;
//			Ed[i][0] = St[i][0] + K;
//			Ed[i][1] = i;
		}

		qsort(St+1, N, sizeof(St[0]), cmp);

		en = 1;

		Answer = 1;

		now =  0;


		go = 1;

		for(go = 1; go <= N; go ++){


			now ++;

			for(;;){
				if(St[ go + 1] == St[go] && go < N ){
					now ++;
					go ++;
				}
				else{
					break;
				}
			}
//			else{
				if( St[en] + K <= St[go] ){
					for(;;){
						if(St[en] + K > St[go]){
							break;
						}
						else{
							en++;
						}
					}

					if(go - en <= 1 ){
						if(Answer < now - ( 1 - go + en )){
							Answer = now-( 1 - go + en );
						}
						now = go - en;
					}

/*					for(;;){
						if(St[go+1] != St[go]){
							break;
						}
						else{
							go++;
							now++;
						}
					}

//					if( St[go+1] == St[go] ){
//						now ++;
//					}*/

				//}
			}
		}
//		go = N;
/*		for(;;){
//			IF(EN
			if( St[en] + K <= St[go] ){
				for(;;){
					if(en == N + 1){
						break;
					}
					if(St[en] + K > St[go]){
						break;
					}
					else{
						en++;
					}
				}

				if(go - en <= 1 ){
					if(Answer < now){
						Answer = now;
					}
					now = go - en;
				}
			}
			else{
				break;
					if(Answer < now){
						Answer = now;
					}
			}
		}*/
		if(Answer < now){
			Answer = now;
		}


		printf("%d\n", Answer);
	}
	return 0;
}
