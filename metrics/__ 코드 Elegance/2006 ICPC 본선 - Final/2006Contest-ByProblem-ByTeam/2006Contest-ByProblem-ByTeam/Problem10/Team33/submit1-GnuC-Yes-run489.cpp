// proj.cpp.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"

#include<algorithm>
using namespace std;

#define maxn 5100
#define maxint 999999999

int p[maxn];

int i,j,n,m,ans,now;

inline void make(){
	int a,b;
    ans=1;	
	a=b=-maxint;
	now=0;
	for (i=1;i<=n;i++){
		if (p[i]>b){
			if (now>ans)ans=now;
			b=p[i]+m;
			now=1;
			continue;
		}
		if (p[i]>a){
			if (now>ans)ans=now;
            a=b;
			b=p[i]+m;
			now=2;
			continue;
		}
		now++;
		a=b;b=p[i]+m;
    }
	if (now>ans)ans=now;
	printf("%d\n",ans);

}

int main(){
//	freopen("a.txt","r",stdin);
	int ii;
	scanf("%d",&ii);
	while(ii--){
		scanf("%d %d",&n,&m);
		for (i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		sort(&p[1],&p[1+n]);
		make();
	}
	return 0;
}

