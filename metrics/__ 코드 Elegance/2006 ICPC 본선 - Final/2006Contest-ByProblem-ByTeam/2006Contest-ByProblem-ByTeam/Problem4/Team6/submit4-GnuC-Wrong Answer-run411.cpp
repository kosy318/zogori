#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define MAXN 1000

int N;
vector <int> G[MAXN];

int sn;
int dfsno;
int check[MAXN];
int back[MAXN];
char onstack[MAXN];
int sccgroup[MAXN];
stack <int> st;
int ta[1000001], tb[1000001];
int table[1000][1000];
int sta, stb, eda, edb;

void searchc(int a) {
	check[a] = back[a] = ++dfsno;
	onstack[a] = 1;
	st.push(a);

	if (a == sta) {
		for (int i = 0; i < 1; i++) {
			int b = G[a][i];
	
			if (check[b]) {
				if (check[b] < check[a] && onstack[b] && back[a] > check[b]) 
					back[a] = check[b];
			} else {
				searchc(b);
				if (back[a] > back[b]) 
					back[a] = back[b];
			}
		}
	} else {
		for (int i = 0; i < G[a].size(); i++) {
			int b = G[a][i];
	
			if (check[b]) {
				if (check[b] < check[a] && onstack[b] && back[a] > check[b]) 
					back[a] = check[b];
			} else {
				searchc(b);
				if (back[a] > back[b]) 
					back[a] = back[b];
			}
		}
	}

	if (check[a] == back[a]) {
		int v = -1;
		while (v != a) {
			v = st.top();
			st.pop();
			onstack[v] = 0;
			sccgroup[v] = sn;
		}
		sn++;
	}
}

void scc() {
	memset(check, 0, N * sizeof(int));
	memset(back, 0, N * sizeof(int));
	memset(onstack, 0, N);
	memset(sccgroup, -1, N * sizeof(int));
	while (!st.empty()) st.pop();
	dfsno = sn = 0;

	searchc(sta);
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int m;
		scanf("%d %d", &N, &m);
		for (int i = 0; i < N; i++) 
			G[i].clear();
		memset(table, 0, sizeof(table));
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &ta[i], &tb[i]); ta[i]--; tb[i]--;
			table[ta[i]][tb[i]] = 1;
			table[tb[i]][ta[i]] = 1;
		}
		scanf("%d %d", &sta, &stb); sta--; stb--;
		scanf("%d %d", &eda, &edb); eda--; edb--;

		scanf("%d", &m);
		int tma, tmb;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &tma, &tmb); tma--; tmb--;
			table[tma][tmb] = 0;
			table[tmb][tma] = 0;
		}
		if (table[sta][stb] == 0) {
			printf("NO\n"); continue;
		}
		if (table[eda][edb] == 0) {
			printf("NO\n"); continue;
		}
		table[sta][stb] = table[stb][sta] = 0;
		table[eda][edb] = table[edb][eda] = 0;
		G[sta].push_back(stb); G[stb].push_back(sta);
		G[eda].push_back(edb); G[edb].push_back(eda);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if(table[i][j] == 1) G[i].push_back(j);
			}
		
		scc();

		bool sw = false;
		
		if (check[eda] > 1 && check[edb] > 1) {
			if (check[eda] == check[edb] + 1 && back[eda] == 1) sw = true;
			if (check[edb] == check[eda] + 1 && back[edb] == 1) sw = true;
		}
		if (sw) printf("YES\n"); else printf("NO\n");
	}
}
