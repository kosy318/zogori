#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int n, m = 1000;
int w[1010][52];
#define pii pair<int,int>
vector<pii>V;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		int x, c = 0;
		while(1){
			scanf("%d",&x);
			if(!x)break;
			w[x][i]=1;
			c++;
			V.push_back({i,c});
		}
	}
	printf("%d\n",V.size());
	for(auto &t : V){
		printf("%d %d\n",t.first,t.second);
	}
}