#define MAX 1005

#include <stdio.h>
#include <stdlib.h>

int testNum, t;

int cityNum, roadNum, tollNum;

int graph[MAX][MAX];
int state[MAX];
int color[MAX];
int cutVertex[MAX];

int curTime;

typedef struct _edge {
	int x, y;
} edgeType;

edgeType need1, need2;
int isNeed1, isNeed2;

int stackPos;

edgeType edgeStack[MAX*MAX+5];
int discoverTime[MAX];
int time;

void push(int x, int y)
{
	edgeType tmp;
	tmp.x=x;
	tmp.y=y;
	edgeStack[stackPos++]=tmp;
}

edgeType pop()
{
	stackPos--;
	return edgeStack[stackPos];
}

void initGraph()
{
	int i, j;
	for(i=0; i<MAX; i++) {
		state[i]=0;
		cutVertex[i]=0;
		discoverTime[i]=0;
		color[i]=0;
		for(j=0; j<MAX; j++) {
			graph[i][j]=0;
		}
	}
}

void showStack()
{
	int i;
	printf("bicomp==\n");
	for(i=0; i<stackPos; i++) {
		printf("%d %d\n", edgeStack[i].x, edgeStack[i].y);
	}
	printf("bicomp end==\n");
}


int DFS(int v)
{
	int i;
	int back, curBack, discover;
	state[v]=1;
	discover=curTime;
	discoverTime[v]=curTime;
	curTime++;
	curBack=v;
	
	for(i=1; i<=cityNum; i++) {
		if(graph[v][i]==1 && state[i]==0) {
			printf("DFS %d->%d\n", v, i);
			push(v, i);
			back=DFS(i);
			if(discover<=back) {
				showStack();
				if((need1.x==v && need1.y==i) || (need1.x==i && need1.y==v)) {
					isNeed1=1;
				}
				if((need2.x==v && need2.y==i) || (need2.x==i && need2.y==v)) {
					isNeed2=1;
				}
			}
			if(curBack>back) {
				curBack=back;
			}
		}
		else if(graph[v][i]==1 && state[i]==1) {
			back=discoverTime[i];
			if(curBack>back) curBack=back;
		}
	}
	state[v]=2;	//end
	return curBack;
}


int bicompDFS(int v, int *color, int p)
{
	int i, w;
	int back, wBack;
	edgeType tmp;
	color[v]=1;
	time++;
	discoverTime[v]=time;
	back=discoverTime[v];
	for(w=1; w<=cityNum; w++) {
		if(graph[v][w] && color[w]==0) {
			push(v, w);
			wBack=bicompDFS(w, color, v);

			if(wBack>=discoverTime[v]) {
				//bicomp
				isNeed1=0;
				isNeed2=0;
//				printf("start bicomp==%d %d==\n", v, w);
				while(1) {
					tmp=pop();
//					printf("%d %d\n", tmp.x, tmp.y);
					if((need1.x==tmp.x && need1.y==tmp.y) || (need1.x==tmp.y && need1.y==tmp.x)) {
						isNeed1=1;
					}
					if((need2.x==tmp.x && need2.y==tmp.y) || (need2.x==tmp.y && need2.y==tmp.x)) {
						isNeed2=1;
					}
					if((tmp.x==v && tmp.y==w) || tmp.y==v && tmp.x==w ) break;
				}
//				printf("end bicomp\n");
			}
			back=(back<wBack ? back : wBack);
		}
		else if(graph[v][w] && color[w]==1 && w!=p) {
			push(v, w);
			back=(back<discoverTime[w] ? back : discoverTime[w]);
		}
	}
	time++;
	color[v]=2;
	return back;
}

int main()
{
	int i, j;
	int tmpX, tmpY;
	scanf("%d", &testNum);
	for(t=0; t<testNum; t++) {
		scanf("%d%d", &cityNum, &roadNum);
		initGraph();
		curTime=1;
		time=0;
		isNeed1=0;
		isNeed2=0;
		for(i=0; i<roadNum; i++) {
			scanf("%d%d", &tmpX, &tmpY);
			graph[tmpX][tmpY]=1;
			graph[tmpY][tmpX]=1;
		}
		scanf("%d%d", &need1.x, &need1.y);
		scanf("%d%d", &need2.x, &need2.y);
		scanf("%d", &tollNum);
		for(i=0; i<tollNum; i++) {
			scanf("%d%d", &tmpX, &tmpY);
			graph[tmpX][tmpY]=0;
			graph[tmpY][tmpX]=0;
		}

		//input end
		for(i=1; i<=cityNum; i++) {
			if(color[i]==0) bicompDFS(i, color, -1);
		}
		if(isNeed1 && isNeed2) printf("YES\n");
		else printf("NO\n");


	}
	return 0;
}