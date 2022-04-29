#include<bits/stdc++.h>
using namespace std;

struct p{
	int x, y, z;
};

bool cmpy(p &p1, p &p2){
	return p1.y < p2.y;
}
bool cmpx(p &p1, p &p2){
	return p1.x < p2.x;
}

vector<p> ps;
int pos, neg;

struct node{
	node *l, *r;
	int s, e, m;
	int mn, mx, df, lazy;
	node(int s, int e){
		this->s = s; this->e = e; this->m = (this->s + this->e) / 2;
		this->mn = this->mx = this->df = this->lazy = 0;
		if(s < e){
			this->l = new node(this->s, this->m);
			this->r = new node(this->m+1, this->e);
		}
	}
	void upd(int s, int e, int v){
		if(this->s == s && this->e == e){
			this->lazy += v;
			this->mn += v;
			this->mx += v;
			return;
		}
		if(this->lazy != 0){
			this->l->lazy += this->lazy; this->r->lazy += this->lazy;
			this->l->mn += this->lazy; this->r->mn += this->lazy;
			this->l->mx += this->lazy; this->r->mx += this->lazy;
			this->lazy = 0;
		}
		if(e <= this->m){
			this->l->upd(s, e, v);
		}else if(s > this->m){
			this->r->upd(s, e, v);
		}else{
			this->l->upd(s, this->m, v);
			this->r->upd(this->m+1, e, v);
		}
		this->mn = min(this->l->mn, this->r->mn);
		this->mx = max(this->l->mx, this->r->mx);
		this->df = max({this->l->df, this->r->df, (this->r->mx - this->l->mn)});
	}
};

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int aa, bb;
		scanf("%d%d", &aa, &bb);
		ps.push_back({aa, bb, 1});
	}
	int m;
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int aa, bb;
		scanf("%d%d", &aa, &bb);
		ps.push_back({aa, bb, -1});
	}
	scanf("%d%d", &pos, &neg);
	sort(ps.begin(), ps.end(), cmpy);
	for(int i=0;i<n+m;i++){
		ps[i].y = i;
	}
	sort(ps.begin(), ps.end(), cmpx);
	int ss = 0, ee = -1;
	int dir = 1;
	node *root = new node(0, (n+m-1));
	int ans = 0;
	/*
	for(int i=0;i<n+m;i++){
		printf("%d %d %d\n", ps[i].x, ps[i].y, ps[i].z);
	}
	*/
	while(ss < (n+m)){
		if(dir > 0){
			if(ee == n+m-1){
				if(ps[ss].z > 0) root->upd(ps[ss].y, (n+m-1), -pos);
				else root->upd(ps[ss].y, (n+m-1), neg);
				ss++;
				dir = -1;
			}else{
				ee++;
				if(ps[ee].z > 0) root->upd(ps[ee].y, (n+m-1), pos);
				else root->upd(ps[ee].y, (n+m-1), -neg);
			}
		}else{
			if(ee == ss){
				if(ps[ss].z > 0) root->upd(ps[ss].y, (n+m-1), -pos);
				else root->upd(ps[ss].y, (n+m-1), neg);
				ss++;
				dir = 1;
			}else{
				if(ps[ee].z > 0) root->upd(ps[ee].y, (n+m-1), -pos);
				else root->upd(ps[ee].y, (n+m-1), neg);
				ee--;
			}
		}
		ans = max(ans, max(root->mx, root->df));
		// printf("%d %d %d %d %d\n", ss, ee, root->df, root->mn, root->mx);
	}
	printf("%d\n", ans);
}
/*
-1 0 1
0 1 -1
2 2 -1
4 3 1
0 0 0 5 5
0 1 0 3 5
0 2 0 1 5
0 3 5 1 6
1 3 5 -4 1
1 2 0 -4 0
1 1 0 -2 0
2 1 0 0 0
2 2 0 -2 0
2 3 5 -2 3
3 3 5 0 5
4 3 0 0 0
* 
*
0 5 1
1 4 -1
3 3 1
6 1 -1
7 2 -1
8 0 1
0 0 3 4 7
0 1 3 2 5
0 2 4 4 8
0 3 4 2 6
0 4 4 0 4
0 5 4 3 7
1 5 3 3 7
1 4 3 0 4
1 3 3 2 5
1 2 3 4 7
1 1 0 2 4
2 1 0 4 4
2 2 3 4 7
2 3 3 2 5
2 4 3 0 4
2 5 3 3 7
3 5 0 3 7
3 4 0 0 4
3 3 0 2 4
4 3 0 4 4
4 4 0 2 4
4 5 0 5 7
5 5 0 7 7
6 5 0 4 4
* */
