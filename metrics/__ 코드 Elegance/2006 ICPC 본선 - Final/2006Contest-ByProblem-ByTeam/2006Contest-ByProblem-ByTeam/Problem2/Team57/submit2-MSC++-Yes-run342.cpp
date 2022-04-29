#include <stdio.h>

int T, m, n;
char aaa[55][1004], dap[55][1004]; 
int ap[200];
int maxchar;
int total[55];

void solve(int x)
{
	int i, j, max,sum = 0;

	total[x] = 0;
	for( j=0 ; j<n ; j++){
		sum = 0;
		max= 0;
		for( i=0; i<200 ; i++ ){
			ap[i] = 0;
		}
		for( i=0 ; i<m ; i++ ){
		ap[(int)aaa[i][j]]++;
		//printf("%d\n",aaa[i][j]);
		if( max == (int)ap[aaa[i][j]] && maxchar > aaa[i][j] ){
			max=ap[(int)aaa[i][j]]; sum=m-max; maxchar = aaa[i][j];
		}
		else if( max < (int)ap[aaa[i][j]] ){ max=ap[(int)aaa[i][j]]; sum=m-max; maxchar = aaa[i][j]; }
		}
		dap[x][j] = maxchar;
		total[x] = total[x]+sum;
		
	}
}

void main()
{
	int i, j;
	scanf("%d",&T);

	for( i=0 ; i<T ; i++ ){
		scanf("%d%d",&m,&n);
		for( j=0 ; j<m ; j++ ){
			scanf("%s",aaa[j]);
		}
		solve(i);

	}
	for( i=0 ; i<T ; i++ ){
		printf("%s\n%d\n",dap[i],total[i]);
	}


}