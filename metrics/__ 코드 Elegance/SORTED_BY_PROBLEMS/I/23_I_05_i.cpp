#include<stdio.h>
#include<algorithm>
#define M 100001
#define MAXV(A,B) ((A)>(B)?(A):(B))

using namespace std;

struct data
{
	int s,e;
}; data d[M];

int n;
bool cmp(data A,data B)
{
	return A.s < B.s;
}

int main()
{
	int i,low,high,mid,ans,point,len;
	bool isP;

	scanf("%d",&n);
	for(i=1; i<=n; i++){
		scanf("%d%d",&d[i].s,&len);
		d[i].e = d[i].s + len;
	}
	
	low = 1; high = ans = 1000000001;

	stable_sort(d+1,d+n+1,cmp);

	while(low <= high){
		
		mid = (low + high) / 2;
		
		point = d[1].s;
		isP = 1;


		for(i=1; i<n; i++){

			if(point + mid > d[i+1].e) { isP = 0;}
			point = MAXV(point+mid, d[i+1].s);
		}

		if(isP){
			low = mid + 1;
			ans = mid;
		}
		else high = mid - 1;
	}
	
	printf("%d\n",ans);

	return 0;
}
