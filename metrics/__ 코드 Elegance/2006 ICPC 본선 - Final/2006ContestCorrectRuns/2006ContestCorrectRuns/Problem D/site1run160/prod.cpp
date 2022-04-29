// prod.cpp.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define maxn 1100

int i,j,n,m,k;
int q[maxn][maxn];
bool toil[maxn][maxn];
bool checked[maxn];
int a,b,c,d;
int p[10];

void checkit(int a){
	checked[a]=1;
	int i;
	for (i=1;i<=q[a][0];i++)if (!checked[q[a][i]]&&!toil[a][q[a][i]])checkit(q[a][i]);
}



int main(){
//	freopen("a.txt","r",stdin);
	int ii;
	scanf("%d",&ii);
	while(ii--){
		scanf("%d %d",&n,&m);
		memset(toil,0,sizeof(toil));
		for (i=1;i<=n;i++)q[i][0]=0;
		while(m--){
			scanf("%d %d",&a,&b);
			q[a][0]++;
			q[a][q[a][0]]=b;
			q[b][0]++;
			q[b][q[b][0]]=a;
		}
		for (i=1;i<=4;i++)scanf("%d",&p[i]);
		scanf("%d",&m);
		while(m--){
			scanf("%d %d",&a,&b);
			toil[a][b]=1;
			toil[b][a]=1;
		}
		for (i=1;i<=n;i++){
			memset(checked,0,sizeof(checked));
			checked[i]=1;
			for (j=1;j<=4;j++)if(p[j]!=i){
				checkit(p[j]);
				break;
			}
			for (j=1;j<=4;j++)if (!checked[p[j]]){
				printf("NO\n");
				goto aaa;
			}
		}
		printf("YES\n");
				
aaa:;}
	return 0;
	
}
