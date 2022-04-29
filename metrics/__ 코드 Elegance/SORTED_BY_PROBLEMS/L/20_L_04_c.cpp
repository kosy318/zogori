#include<bits/stdc++.h>
using namespace std;

int p[105];
struct mine{
	int x, y, z;
	bool operator < (const mine &mm) const{
		return y < mm.y;
	}
};
mine q[10005];

const int pp=16384;
int node[pp+pp];

int gett(int ss, int ee){
	ss += pp;
	ee += pp;
	int ans = 0;
	while(ss <= ee){
		if(ss%2 == 1){
			ans = max(ans, node[ss]); ss++;
		}
		if(ee%2 == 0){
			ans = max(ans, node[ee]); ee--;
		}
		if(ss > ee) break;
		ss /= 2; ee /= 2;
	}
	return ans;
}

void sett(int x, int y){
	x += pp;
	while(x > 0){
		node[x] = max(node[x], y);
		x /= 2;
	}
}

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i=1;i<=m;i++){
		scanf("%d", &p[i]);
	}
	for(int i=0;i<n;i++){
		int aa, bb, cc;
		scanf("%d%d%d", &aa, &bb, &cc);
		q[i] = {aa, bb, cc};
	}
	sort(q, q+n);
	for(int i=0;i<n;i++){
		sett(q[i].y, gett(0, q[i].x) + (q[i].y - q[i].x) * p[q[i].z]);
	}
	printf("%d\n", gett(0, pp-1));
}
