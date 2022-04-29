#define MAX 1024

#include <stdio.h>
#include <stdlib.h>

int testNum, t;

char str[MAX][60];
int m, n;
int resIdx;

int cntTable[50];

void initTable()
{
	int i;
	for(i=0; i<50; i++) {
		cntTable[i]=0;
	}
}

int diffCnt(char *buf)
{
	int i, j;
	int cnt=0;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			if(str[i][j]!=buf[j]) cnt++;
		}
	}
	return cnt;
}

char getAlpha()
{
	int i;
	int maxIdx;
	char max;
	maxIdx=0;
	max=cntTable[0];
	for(i=0; i<26; i++) {
		if(max<cntTable[i]) {
			maxIdx=i;
			max=cntTable[i];
		}
   	}
	return maxIdx+'A';
}

int main()
{
	char mainStr[MAX];
	int i, tmp, j;
	scanf("%d", &testNum);
	for(t=0; t<testNum; t++) {
		scanf("%d%d", &m, &n);
		for(i=0; i<m; i++) {
			scanf("%s", str[i]);
		}
		for(i=0; i<n; i++) {
			initTable();
			for(j=0; j<m; j++) {
				cntTable[str[j][i]-'A']++;
			}
			mainStr[i]=getAlpha();
		}
		mainStr[i]='\0';
		tmp=diffCnt(mainStr);
		printf("%s\n%d\n", mainStr, tmp);
	}
	return 0;
}