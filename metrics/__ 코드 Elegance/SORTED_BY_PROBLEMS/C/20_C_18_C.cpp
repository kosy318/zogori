#include<bits/stdc++.h>
using namespace std;
int n;
int su[100005][2];
unordered_map<long long, int> mp;

int p[100005], pp = 0;
int maxpp = -1, mx2 = -1;
bool do_test(int x1, int x2, int y1, int y2){
	//printf("%d %d %d %d\n", x1, x2, y1, y2);
	if(pp >= n){
		return true;
	}
	int nx1 = (x1+(n-1))%n, nx2 = (x2+1)%n, ny1 = (y1 + (n-1)) % n, ny2 = (y2 + 1) % n;
	if(su[nx1][1] == su[ny1][0] && su[nx2][1] == su[ny2][0]){
		p[pp++] = su[nx1][1];
		p[pp++] = su[nx2][1];
		if(pp > maxpp){
			maxpp = pp;
			mx2 = nx2;
		}
		if(do_test(nx1, nx2, ny1, ny2)) return true;
		pp-=2;
	}else if(su[nx1][1] == su[ny2][0] && su[nx2][1] == su[ny1][0]){
		p[pp++] = su[nx1][1];
		p[pp++] = su[nx2][1];
		if(pp > maxpp){
			maxpp = pp;
			mx2 = nx2;
		}
		if(do_test(nx1, nx2, ny1, ny2)) return true;
		pp-=2;
	}else if(su[nx1][1] == su[ny1][0]){
		p[pp++] = su[nx1][1];
		if(pp > maxpp){
			maxpp = pp;
			mx2 = x2;
		}
		if(do_test(nx1, x2, ny1, y2)) return true;
		pp--;
	}else if(su[nx2][1] == su[ny1][0]){
		p[pp++] = su[nx2][1];
		if(pp > maxpp){
			maxpp = pp;
			mx2 = nx2;
		}
		if(do_test(x1, nx2, ny1, y2)) return true;
		pp--;
	}else if(su[nx1][1] == su[ny2][0]){
		p[pp++] = su[nx1][1];
		if(pp > maxpp){
			maxpp = pp;
			mx2 = x2;
		}
		if(do_test(nx1, x2, y1, ny2)) return true;
		pp--;
	}else if(su[nx2][1] == su[ny2][0]){
		p[pp++] = su[nx2][1];
		if(pp > maxpp){
			maxpp = pp;
			mx2 = nx2;
		}
		if(do_test(x1, nx2, y1, ny2)) return true;
		pp--;
	}
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &su[i][0]);
		su[i][0]--;
	}
	for(int i=0;i<n;i++){
		scanf("%d", &su[i][1]);
		su[i][1]--;
	}
	for(int i=0;i<n;i++){
		int v1 = max({su[i][0], su[(i+1)%n][0], su[(i+2)%n][0]});
		int v3 = min({su[i][0], su[(i+1)%n][0], su[(i+2)%n][0]});
		int v2 = (su[i][0] + su[(i+1)%n][0] + su[(i+2)%n][0]) - v1 - v3;
		long long h = 0;
		h = (h * 100000) + v1;
		h = (h * 100000) + v2;
		h = (h * 100000) + v3;
		mp[h] = i;
	}
	for(int i=0;i<n;){
		//printf("%d\n", i);
		int v1 = max({su[i][1], su[(i+1)%n][1], su[(i+2)%n][1]});
		int v3 = min({su[i][1], su[(i+1)%n][1], su[(i+2)%n][1]});
		int v2 = (su[i][1] + su[(i+1)%n][1] + su[(i+2)%n][1]) - v1 - v3;
		long long h = 0;
		h = (h * 100000) + v1;
		h = (h * 100000) + v2;
		h = (h * 100000) + v3;
		if(mp.find(h) != mp.end()){
			int x = mp[h];
			while(su[x][0] != su[(i+1)%n][1]){
				x = (x+1) % n;
			}
			pp = 0;
			p[pp++] = su[x][0];
			maxpp = 0, mx2 = 0;
			if(do_test((i+1)%n, (i+1)%n, x, x)){
				for(int j=0;j<n;j++){
					printf("%d ", p[j]+1); 
				}
				printf("\n");
				return 0;
			}else{
				if(mx2 < i) break;
				if(mx2 == i) i++;
				else i = mx2;
			}
		}else{
			i++;
		}
	}
	printf("-1\n");
}
