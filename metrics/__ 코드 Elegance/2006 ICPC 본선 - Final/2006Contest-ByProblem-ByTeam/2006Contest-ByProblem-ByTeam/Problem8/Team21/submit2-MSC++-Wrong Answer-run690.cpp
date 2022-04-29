#include <stdio.h>
#include <string.h>
char x[5000];
char y[50];

int main(void){
	int test_case;
	int len_x, len_y;
	int index;
	int i, j, k , cnt, temp; 
	char dummy;

	scanf("%d", &test_case);

	for(i = 0; i < test_case; i++){
		cnt = 0;
		scanf(" %s",y);
		scanf(" %s",x);

		len_x = strlen(x); len_y = strlen(y);

		
		index = 0; temp = 0;
		for(j = 0; j < len_x; j++){
			
			if (x[j] == y[index]){
				index++;
				if (index == len_y) {
					index = 0;
					if (cnt < temp) cnt = temp;
					
					temp = 0;
				}
			}

			else if( (x[j+1] != y[index]) && ((x[j] != y[(index+1)%len_y])) ){
				index++; temp++;
				if (index == len_y) {
					index = 0;
					if (cnt < temp) cnt = temp;
					
					temp = 0;
				}
			}
			else if (x[j+1] == y[index]) temp++;
			else {
				index++; temp++;
				if (index == len_y) {
					index = 0;
					if (cnt < temp) cnt = temp;
					
					temp = 0;
				}
				j--;
			}

			if ((len_x-1 == j)&&(index !=0))
				temp = temp + (len_y-index);
		}

		if (cnt < temp) cnt = temp;

		printf("%d\n",cnt);

	}
	return 0;
}