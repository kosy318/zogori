#include <stdio.h>
#include <stdlib.h>

int testNum, t;

int N, K;

int tree[5002];
int state[5002];

void sortTree()
{
	int i, j;
	int min, minIdx;

	for(i=0; i<N; i++) {
		min=tree[i];
		minIdx=i;
		for(j=i+1; j<N; j++) {
			if(min>tree[j]) {
				min=tree[j];
				minIdx=j;
			}
		}
		tree[minIdx]=tree[i];
		tree[i]=min;
	}
}

int main()
{
	int i, j;
	int cnt, res;
	scanf("%d", &testNum);
	for(t=0; t<testNum; t++) {
		scanf("%d%d", &N, &K);
		for(i=0; i<N; i++) {
			scanf("%d", &tree[i]);
		}
		sortTree();
		for(i=0; i<N; i++) {
			if(i==0 || i==N-1 || !(tree[i]+K>=tree[i+1] && tree[i-1]+K>=tree[i] && tree[i-1]+K>=tree[i+1])) {
				state[i]=1;
			}
			else state[i]=0;
		}
		res=1;
		cnt=1;
		for(i=1; i<N; i++) {
			if(state[i]==1) {
				if(tree[i-1]+K>tree[i]) cnt++;
				if(res<cnt) res=cnt;
				cnt=1;
			}
			else {
				cnt++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}