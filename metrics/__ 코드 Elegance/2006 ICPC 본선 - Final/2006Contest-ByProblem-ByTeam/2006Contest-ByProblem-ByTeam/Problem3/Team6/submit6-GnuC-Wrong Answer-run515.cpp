#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
public:
	int x, y;

	bool operator < (const Point &a) const {
		return y < a.y;
	}
};

int T, n, m, k, plus;
Point P[1005];
int so[1005];

int mi[10000], ma[10000];
int mit[32768], mat[32768];

int solve(void)
{
	unsigned int area;
	unsigned int nowy,backy,maxx,minx;
	unsigned int ret;
	bool ddd = false;

	sort(P, P + k);
	int ypos;

	for(int qq = 0; qq < k * 2; qq++) {
		if (qq % 2 == 0) ypos = P[qq / 2].y;
		else ypos = P[qq / 2].y - 1;
		if (ypos < 0) continue;
		area=n;
		backy=max(0,P[0].y-1);minx=P[0].x-1;maxx=P[0].x+1;
		if(backy>ypos) backy=ypos;
		for(int i=0;i<k;i++)
		{
			if(P[i].y>ypos) break;
			nowy=max(P[i].y-1,0);
			area+=(nowy-backy)*(maxx-minx);
			backy=nowy;
			maxx>?=min(P[i].x+1,n);
			minx<?=max(P[i].x-1,0);
		}
		nowy=ypos;
		area+=(nowy-backy)*(maxx-minx);

		backy=min(m,P[k-1].y+1);minx=P[k-1].x-1;maxx=P[k-1].x+1;
		if(backy<ypos+1) backy=ypos+1;
		for(int i=k-1;i>=0;i--)
		{
			if(P[i].y<ypos+1) break;
			nowy=min(P[i].y+1,m);
			area+=(backy-nowy)*(maxx-minx);
			backy=nowy;
			maxx>?=min(P[i].x+1,n);
			minx<?=max(P[i].x-1,0);
		}
		nowy=ypos+1;
		area+=(backy-nowy)*(maxx-minx);

	
		if(!ddd || ret>area) ret=area;
		ddd = true;
	}
	return ret;
}

int main() {
	unsigned int mincost;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		scanf("%d", &k);
		plus = 50001;
		for (int i = 0; i < k; i++) {
			int tx, ty;
			Point temp;
			scanf("%d %d", &tx, &ty);
			P[i].x = tx;
			P[i].y = ty;
		}
		mincost=solve();
		for (int i = 0; i < k; i++) {
			int tmp;
			tmp=P[i].x;P[i].x=P[i].y;P[i].y=tmp;
		}
		swap(n,m);
		mincost<?=solve();
		printf("%u\n",mincost);
	}
}
