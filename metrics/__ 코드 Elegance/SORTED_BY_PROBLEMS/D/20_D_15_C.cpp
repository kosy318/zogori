#include<bits/stdc++.h>
using namespace std;

struct lad{
	int x, y, z;
	bool operator < (const lad &dod) const{
		return y < dod.y;
	}
};

vector<lad> v;
vector<int> ok;
int seq[55];
map<int, int> mp;
int bye[100][100];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		for(int j=1;;j++){
			int x; scanf("%d", &x);
			if(x == 0) break;
			v.push_back({i, x, j});
			ok.push_back(1);
		}
	}
	sort(v.begin(), v.end());
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			bye[i][j] = -1;
		}
	}
	int m = (int)v.size();
	for(int i=0;i<n;i++){
		seq[i] = i;
	}
	int dap = m;
	for(int i=0;i<m;i++){
		int tmp = seq[v[i].x-1];
		seq[v[i].x-1] = seq[v[i].x];
		seq[v[i].x] = tmp;
		/*
		//printf("%d %d %d %d\n", v[i].x, v[i].y, seq[v[i].x], seq[v[i].x-1]);
		if(bye[seq[v[i].x-1]][seq[v[i].x]] > -1){
			ok[bye[seq[v[i].x-1]][seq[v[i].x]]] = 0;
			ok[i] = 0;
			bye[seq[v[i].x-1]][seq[v[i].x]] = -1;
			bye[seq[v[i].x]][seq[v[i].x-1]] = -1;
			dap -= 2;
		}else{
			bye[seq[v[i].x-1]][seq[v[i].x]] = i;
			bye[seq[v[i].x]][seq[v[i].x-1]] = i;
		}
		*/
	}
	for(int i=0;i<n;i++){
		mp[seq[i]] = i;
		seq[i] = i;
	}
	for(int i=0;i<m;i++){
		if(mp[seq[v[i].x-1]] > mp[seq[v[i].x]]){
			int tmp = seq[v[i].x-1];
			seq[v[i].x-1] = seq[v[i].x];
			seq[v[i].x] = tmp;			
		}else{
			ok[i] = 0;
			dap--;
		}
	}
	printf("%d\n", dap);
	for(int i=0;i<m;i++){
		if(ok[i]){
			printf("%d %d\n", v[i].x, v[i].z);
		}
	}
}
