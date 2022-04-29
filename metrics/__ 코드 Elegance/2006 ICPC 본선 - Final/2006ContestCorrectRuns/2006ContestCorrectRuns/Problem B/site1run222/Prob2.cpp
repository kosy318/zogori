#include <iostream>
using namespace std;

#define MAX 1000

char in[50][MAX+1];
int count[4];

int main()
{
	int n, max, mi, err;
	int t, l;
	scanf("%d",&n);

	for(int i=0; i<n; i++) {
		scanf("%d %d",&t,&l);
		err = 0;
		
		for(int j=0; j<t; j++) 
			scanf("%s",in[j]);

		for(int k=0; k<l; k++) {
			count[0]=count[1]=count[2]=count[3]=0;
			max = mi = 0;
			for(int a=0; a<t; a++) {
				if(in[a][k] == 'A') {
					count[0]++;
					if(count[0] >= max) {
						max = count[0];
						mi = 0;
					}
				} else if(in[a][k] == 'C') {
					count[1]++;
					if((count[1] > max) || (count[1] == max && mi>1)) {
						max = count[1];
						mi = 1;
					}
				} else if(in[a][k] == 'G') {
					count[2]++;
					if((count[2] > max) || (count[2] == max && mi>2)) {
						max = count[2];
						mi = 2;
					}
				} else if(in[a][k] == 'T' ){
					count[3]++;
					if((count[3] > max)) {
						max = count[3];
						mi = 3;
					}
				}			
				
			}

			switch(mi) {
				case 0:
					printf("%c",'A');
					err+= t - count[mi];
					break;
				case 1:
					printf("%c",'C');
					err+= t - count[mi];
					break;
				case 2:
					printf("%c",'G');
					err+= t - count[mi];
					break;
				case 3:
					printf("%c",'T');
					err+= t - count[mi];
					break;
			}
			
		//	printf("%d %d %d %d %d\n",count[0],count[1],count[2],count[3],mi);
			
		}
		printf("\n%d\n",err);
	}

	return 0;
}