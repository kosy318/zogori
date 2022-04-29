#include <stdio.h>
#include <stdlib.h>

int testNum, t;
int N;
int M;

int resTable[21][10002];

int cntTable[101003];

typedef struct _cal {
	int a;
	int b;
}calType;

calType cals[21];

void initRes()
{
	int i, j;
	for(i=0; i<21; i++) {
		for(j=0; j<10002; j++) {
			resTable[i][j]=0;
		}
	}
	for(i=0; i<101003; i++) {
		cntTable[i]=0;
	}
}


void showResTable()
{
	int i, j;
	for(i=0; i<N; i++) {
		for(j=0; j<M; j++) {
			printf("%d ", resTable[i][j]);
		}
		printf("\n");
	}
}

int getIdx(int num, int target)
{
	int i;
	for(i=0; i<=M; i++) {
		if(resTable[num][i]==target) return i;
	}
	return -1;
}

int main()
{
	int i, j, max;
	int sum, flag;
	int ret;
	int maxCnt, maxIdx;
	scanf("%d", &testNum);
	for(t=0; t<testNum; t++) {
		initRes();
		max=0;
		sum=0;
		flag=0;
		scanf("%d", &N);
		for(i=0; i<N; i++) {
			scanf("%d%d", &cals[i].a, &cals[i].b);
		}
		scanf("%d", &M);
		for(i=0; i<N; i++) {
			for(j=0; j<=M; j++) {
				resTable[i][j]=cals[i].a*j+cals[i].b;
				if(max<resTable[i][j]) max=resTable[i][j];
				cntTable[resTable[i][j]]++;
			}
		}
		for(i=0; i<=max; i++) {
			sum=0;
			if(cntTable[i]==N) {
				for(j=0; j<N; j++) {
					ret=getIdx(j, i);
					if(ret==-1) break;
					sum+=ret;
				}
				if(sum==M) {
					printf("%d\n", i);
					flag=1;
					break;
				}
			}
		}
		if(flag==0) printf("%d\n", 0);
//		showResTable();
	}
	return 0;
}
