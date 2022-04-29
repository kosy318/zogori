#include <bits/stdc++.h>
#define N 100005
#define ii pair<int,int>
#define st first
#define nd second
using namespace std;

int n;
ii a[N];

bool ok(int val) {

	int lp=-1000000000;
	
	for(int i=1;i<=n;i++) {
		
		int np=max(a[i].st,lp+val);
		
		if(np>a[i].st+a[i].nd) return false;
		
		lp=np;
		
	}
	
	return true;
	
}

int main() {
		
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) {
		
		int x,y;
		
		scanf("%d %d",&x,&y);
		
		a[i]={x,y};
				
	}
	
	sort(a+1,a+1+n);
	
	int bas=1,son=2000000000;
	
	while(bas<=son) {
	
		long long m=(bas+son)/2;
	
		if(ok(m)) bas=m+1;
		else son=m-1;
 		
	}
	
	printf("%d",son);
	
}
