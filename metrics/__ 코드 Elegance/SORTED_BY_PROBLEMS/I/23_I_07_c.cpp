#include<stdio.h>
#include<algorithm>
#define MaxN 200001
#define MAXV(A,B) ((A)>(B)?(A):(B))

using namespace std;

struct data
{
	long long s,e;
}; data d[MaxN];

int n;
bool cmp(data A,data B)
{
	return A.s < B.s;
}

int main()
{
	int i;
	long long low,high,mid,ans,point,len;
	bool isP;

	scanf("%d",&n);

	for(i=1; i<=n; i++){
		scanf("%lld%lld",&d[i].s,&len);
		d[i].e = d[i].s + len;
	}
	
	low = 1ll; high = ans = 2000000001ll;

	stable_sort(d+1,d+n+1,cmp);

	while(low <= high){
		
		mid = (low + high) / 2ll;

		point = d[1].s;
		isP = 1;


		for(i=1; i<n; i++){

			if(point + mid > d[i+1].e) { isP = 0;}
			point = MAXV(point+mid, d[i+1].s);
		}

		if(isP){
			low = mid + 1ll;
			ans = mid;
		}
		else high = mid - 1ll;
	}
	printf("%lld",ans);	


	return 0;
}

