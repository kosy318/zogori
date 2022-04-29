#include <stdio.h>

int N;
char aaa[1000][3][15];
int dap[1000];

void solve(int t)
{
	int sum = 0;
	if( (int)aaa[t][0][0] > (int)aaa[t][1][0] ){
		sum = 24*3600 + 1 +((int)aaa[t][1][0]*10+(int)aaa[t][1][1])*3600+((int)aaa[t][1][3]*10+(int)aaa[t][1][4])*60+((int)aaa[t][1][6]*10+(int)aaa[t][1][7])
			-(((int)aaa[t][0][0]*10+(int)aaa[t][0][1])*3600+((int)aaa[t][0][3]*10+(int)aaa[t][0][4])*60+((int)aaa[t][0][6]*10+(int)aaa[t][0][7]));
	} else{
		sum = 1 + ((int)aaa[t][1][0]*10+(int)aaa[t][1][1])*3600+((int)aaa[t][1][3]*10+(int)aaa[t][1][4])*60+((int)aaa[t][1][6]*10+(int)aaa[t][1][7])
			-(((int)aaa[t][0][0]*10+(int)aaa[t][0][1])*3600+((int)aaa[t][0][3]*10+(int)aaa[t][0][4])*60+((int)aaa[t][0][6]*10+(int)aaa[t][0][7]));

	}
	if( sum % 3 == 2 ){ sum = sum+1; }
	sum = (int)sum/3;
	dap[t] = sum;
	
}

int main()
{
	int i, j;

	scanf("%d",&N);

	for( i=0 ; i<N ; i++ ){
		scanf("%s%s",aaa[i][0],aaa[i][1]);
		solve(i);
	}
	
	for( i=0 ; i<N ; i++ ){
		printf("%d\n",dap[i]);
	}
	
	return 0;


}