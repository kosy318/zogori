#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

typedef struct ele{
	int n, i, depth, up, cut;
}ele;


int gr[1024];
int v, e;
int info[1024];
vector<int> l[1024];
stack<ele> st;
int vis[1024];

int dfs( int w ){
	ele now, tmp;
	int &n = now.n,
		&i = now.i,
		&depth = now.depth,
		&up = now.up,
		&cut = now.cut;

	int re;
	while( !st.empty() ) st.pop();

    tmp.n = tmp.up = w;
	tmp.i = -1;
	tmp.depth = 1;
	tmp.cut = 0;

    re = -1;
	st.push(tmp);
	
	while( !st.empty() ){
next:
		now = st.top();
		st.pop();

		if ( re != -1 ){
			if( vis[up] > vis[re] ) now.up = re;
			if( vis[n] <= vis[re] ) cut++;
		}

		for( i++ ; i < l[n].size() ; i++ ){
			if( vis[l[n][i] ] ){
				if( vis[l[n][i]] < vis[up] )
					up = l[n][i];
				continue;
			}

			vis[l[n][i]] = depth+1;

			st.push(now);

			tmp.i = -1;
			tmp.n = tmp.up = l[n][i];
			tmp.depth = depth + 1;
			tmp.cut = 0;
			re = -1;
			st.push(tmp);

			goto next;

		}

		info[n] = cut;
		re = up;
	}
	return 0;
}


int AP(){
	int i, re;
	for( i = 0 ; i < v ; i++ ) vis[i] = 0;
	for( i = re = 0 ; i < v ; i++ ){
		if( vis[i] ) continue;
		vis[i] = 1;
		dfs(i);
		re++;
		info[i]--;
	}
	return re;
}

int tmp[1024][1024];

int a1, a2, b1, b2;

void visit( int k ) {
	gr[k] = 1;
	for( int i = 0 ; i < l[k].size() ; i++ ){
		if( gr[ l[k][i] ] ) continue;
		visit(l[k][i]);
	}
	return;
}

int main(){
	int tn;
	int i, j;
	int a, b;

	scanf("%d", &tn);
	while(tn--){
		scanf("%d%d", &v, &e);

		memset( tmp, 0, sizeof(tmp) );

		for( i = 0 ; i < e ; i++ ){
			scanf("%d%d", &a, &b);
			a--; b--;
			tmp[a][b] = 1;
			tmp[b][a] = 1;
		}

		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
		a1--;
		a2--;
		b1--;
		b2--;
		
		scanf("%d", &i);
		while( i-- ){
			scanf("%d%d", &a, &b);
			a--; b--;
			tmp[a][b] = tmp[b][a] = 0;
		}
	
		for( i = 0 ; i < v ; i++ ) l[i].clear();

		for( i = 0 ; i < v;  i++ )
			for( j = 0 ; j < v ; j++ )
				if( tmp[i][j] ) l[i].push_back(j);

		AP();
		
		for( i = 0 ; i < v ; i++ ){
			if( !info[i] ) continue;
			for( j = 0 ; j < l[i].size() ; j++ ){
				memset(gr, 0, sizeof(gr) );
				gr[i] = 1;
				visit( l[i][j] );

				if( gr[a1] && gr[a2] && gr[b1] && gr[b2] ) break;
			}
			if( j == l[i].size() ) goto no;
			;
		}

		printf("YES\n");

		continue;
no:
		printf("NO\n");

	}

}

/*

3
6 6
1 2
2 3
1 3
3 4
1 5
5 6
1 2
3 4
0


3
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6
5 6
3 5
2 4
1
6 5
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6 
5 6
2 3
3 5
1
4 2
5 4
1 2
2 3
3 4
4 5
1 2
4 5
2 
2 3
3 4

100
6 7
1 2
2 3
3 1
3 4
4 5
3 5
5 6
5 6
5 6
0

*/