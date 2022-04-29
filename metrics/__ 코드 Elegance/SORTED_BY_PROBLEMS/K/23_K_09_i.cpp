#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxN 1001

struct data
{
	double r,g,b;
}; data d[MaxN];

int n,k,nA,nB;
bool group[MaxN];

int main()
{
	int i,t;
	srand(time(0));
	double R=0,G=0,B=0,ans=0,RA=0,GA=0,BA=0,RB=0,GB=0,BB=0,prevAns;
	
	scanf("%d%d",&n,&k);
	
	for(i=1; i<=n; i++) scanf("%lf%lf%lf",&d[i].r,&d[i].g,&d[i].b);

	for(i=1; i<=n; i++){
		R += d[i].r; G += d[i].g; B += d[i].b;
	}
	R /= (double)n;  G /= (double)n;  B /= (double)n;
	for(i=1; i<=n; i++){
		ans += ((R-d[i].r)*(R-d[i].r) + (G-d[i].g)*(G-d[i].g) + (B-d[i].b)*(B-d[i].b));
	}

	if(k == 1) printf("%lf\n",ans);

	if(k == 2){
		
		prevAns = ans;
		nA = n; nB = 0;
		for(int cc=0; cc<=100000; cc++){
			t = rand() % n + 1;
			
			group[t] = 1-group[t];
			
			for(i=1; i<=n; i++){
				if(group[i] == 0) {RA += d[i].r; GA += d[i].g; BA += d[i].b;}
				if(group[i] == 1) {RB += d[i].r; RB += d[i].b; BB += d[i].b;}
			}
			RA /= nA; GA/=nA; BA/=nA;
			RB/=nB; GB/=nB; BB/=nB;

			ans = 0;

			for(i=1; i<=n; i++){
				if(group[i] == 0) ans += ((RA-d[i].r)*(RA-d[i].r) + (GA-d[i].g)*(GA-d[i].g) + (BA-d[i].b)*(BA-d[i].b));
				if(group[i] == 1) ans += ((RB-d[i].r)*(RB-d[i].r) + (GB-d[i].g)*(GB-d[i].g) + (BB-d[i].b)*(BB-d[i].b));
			}
			if(prevAns > ans){
				prevAns = ans;
				continue;
			}
			else break;
		}
		printf("%lf\n",ans);
	}
}
