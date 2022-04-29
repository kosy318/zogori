#include <stdio.h>

char arr[50][1000];
char arr2[1000];

int main(void){
	int i, j, k;
	int test_case;
	int max, count, count_sum;
	int data_cnt, data_length;
	int temp, index;
	 char dummy;
	
	int cnt[26];

	scanf("%d",&test_case);

	for(i=0; i < test_case; i++){

		count = 0; 
				
		for(j = 0; j < 26; j++)
			cnt[j] = 0;
		
		scanf("%d %d", &data_cnt, &data_length);
		scanf("%c", &dummy);

		for(j = 0; j < data_cnt; j++){
			for(k = 0; k < data_length; k++){
				scanf("%c",&arr[j][k]);
			}
			scanf("%c",&dummy);
		}

		count = 0;



		for(j = 0; j < data_length; j++){
		
			for(k = 0; k < 26; k++)
				cnt[k] = 0;

			for(k = 0; k < data_cnt; k++){
				temp = arr[k][j]-65;
				cnt[temp]++;
			}
			
			max = 0;
			
			for(k = 0; k < 26; k++)
				if (max < cnt[k]){
					max = cnt[k];	arr2[j] = k +65;
				}

			count = count + (data_cnt - max);
		}

		for(j = 0; j < data_length; j++)
			printf("%c", arr2[j]);
		printf("\n%d\n", count);



				
	}



		
	return 0;
}