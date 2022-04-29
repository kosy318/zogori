#include <bits/stdc++.h>
using namespace std;
int n, w[1010], vis[10100], Save[1010];

int main() {
	int i, j, k, d;
	scanf("%d",&n);
	for(i=1;i<=n+1;i++) {
		//for (j = 1; j <= n; j++) {
			int cnt=0;
			for(d=1;2*d<i;d++){
				int c = w[i-d]*2 -w[i-d*2];
				if(c>0){
					if(!vis[c]){
						vis[c] = 1;
						Save[++cnt] = c;
					}
				}
			}
			for(k=1;;k++){
				if(!vis[k])break;
			}
			w[i] = k;
			for(k=1;k<=cnt;k++){
				vis[Save[k]] = 0;
			}
		//}
		//printf("%d ",w[i]);
	}
	printf("%d\n",w[n+1]);
    return 0;
}