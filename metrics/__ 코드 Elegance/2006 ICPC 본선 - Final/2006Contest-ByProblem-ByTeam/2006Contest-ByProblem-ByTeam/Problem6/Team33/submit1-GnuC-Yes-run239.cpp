#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

#define For(i,s,t) for(int i=(s); i<(t); i++)
#define fori(n) For(i,0,n)
#define forj(n) For(j,0,n)
#define fork(n) For(k,0,n)


const int maxN=1000;
int sum;
int a[maxN],b[maxN],x[maxN];

int main() {
	int ca,t,n,m;
	for(scanf("%d",&ca);ca;ca--) {
		scanf("%d",&n);
		fori(n) scanf("%d %d",&a[i],&b[i]);
		scanf("%d",&sum);
		int g2, ok2=0;
		for(int s=0; s<=sum; s++) {
			int g=s*a[0]+b[0];
			int ok=1;
			int sum2=s;
			For(i,1,n) {
				x[i]=(g-b[i]);
				if(x[i]<0 || x[i]%a[i]) {
					ok=0;
					break;
				}
				x[i]/=a[i];
				sum2+=x[i];
			}
			if(ok) ok=(sum==sum2);
			if(ok) { g2=g; ok2=ok; break; }
		}
		printf("%d\n",ok2? g2: 0);
	}
}

