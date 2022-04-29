// proc.cpp.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define maxn 51000
#define maxint 999999999

int xmax[maxn],xmin[maxn],ymax[maxn],ymin[maxn];

void fixmin(int &a,int b){if (b<a)a=b;}
void fixmax(int &a,int b){if (b>a)a=b;}

int w,h,n,x,y;
long long int ans;

inline void make(int* minp,int* maxp,int n,int w){
	int i;
	long long int back[maxn],forward[maxn];
	memset(back,0,sizeof(back));
	memset(forward,0,sizeof(forward));
	int nowmin,nowmax;
	long long int now;
	nowmin=maxint;nowmax=-maxint;
	now=maxint;
	now*=100;
	for (i=1;i<=n;i++){
		if (minp[i]<nowmin)nowmin=minp[i];
		if (maxp[i]>nowmax)nowmax=maxp[i];
		if (nowmin<=nowmax){
			forward[i]=forward[i-1]+nowmax-nowmin+1;
		}
	}
	nowmin=maxint;nowmax=-maxint;
	for (i=n;i;i--){
		if (minp[i]<nowmin)nowmin=minp[i];
		if (maxp[i]>nowmax)nowmax=maxp[i];
		if (nowmin<=nowmax){
			back[i]=back[i+1]+nowmax-nowmin+1;
		}
	}
	for (i=1;i<=n;i++){
		if (w+forward[i-1]+back[i+1]<now)now=w+forward[i-1]+back[i+1];
	}
	if (now<ans)ans=now;
}

int main(){
	//freopen("a.txt","r",stdin);
	int ii,i;
	scanf("%d",&ii);
	while(ii--){
		scanf("%d %d",&w,&h);
		ans=w;ans*=h;
		for (i=1;i<=w;i++){
			ymax[i]=-1;ymin[i]=maxint;
		}
		for (i=1;i<=h;i++){
			xmax[i]=-1;xmin[i]=maxint;
		}
		scanf("%d",&n);
		for (i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            fixmin(xmin[y],x);
			fixmax(xmax[y],x+1);
			fixmin(ymin[x],y);
			fixmax(ymax[x],y+1);
			fixmin(xmin[y+1],x);
			fixmax(xmax[y+1],x+1);
			fixmin(ymin[x+1],y);
			fixmax(ymax[x+1],y+1);
		}
		make(xmin,xmax,h,w);
		make(ymin,ymax,w,h);
		printf("%I64d\n",ans);
	}
	return 0;
}
