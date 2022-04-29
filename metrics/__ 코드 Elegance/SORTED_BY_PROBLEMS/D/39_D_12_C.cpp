#include <bits/stdc++.h>
using namespace std;

const int N = 55, K = 1005;
int n, p[N], pp[N], c[N];
vector<int> v[N];
queue<int> q[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		while(1){
			int x;
			scanf("%d", &x);
			if(!x){
				v[i].push_back(K);
				break;
			}
			v[i].push_back(x);
		}
	}
	for(int i = 1; i < n; i++) for(int j : v[i]) q[i].push(j);
	iota(p + 1, p + n + 1, 1);
	while(1){
		pair<int, int> mn = make_pair(K, 0);
		for(int i = 1; i < n; i++) mn = min(mn, make_pair(q[i].front(), i));
		if(mn.first == K) break;
		q[mn.second].pop();
		swap(p[mn.second], p[mn.second + 1]);
	}
	int inv = 0;
	for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) if(p[i] > p[j]) inv++;
	for(int i = 1; i <= n; i++) pp[p[i]] = i;
	//for(int i = 1; i <= n; i++) printf("%d ", pp[i]); puts("");
	for(int i = 1; i < n; i++){
		while(!q[i].empty()) q[i].pop();
		for(int j : v[i]) q[i].push(j);
	}
	printf("%d\n", inv);
	while(1){
		pair<int, int> mn = make_pair(K, 0);
		for(int i = 1; i < n; i++) mn = min(mn, make_pair(q[i].front(), i));
		if(mn.first == K) break;
		q[mn.second].pop();
		c[mn.second]++;
		if(pp[mn.second] > pp[mn.second + 1]){
			printf("%d %d\n", mn.second, c[mn.second]);
			swap(pp[mn.second], pp[mn.second + 1]);
		}
	}
}
