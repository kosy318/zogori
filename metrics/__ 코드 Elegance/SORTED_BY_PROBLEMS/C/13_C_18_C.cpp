#include<bits/stdc++.h>

#define Fi first
#define Se second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define pb push_back
#define szz(x) (int)(x).size()

int N, A[100010], B[100010];
int chk[100010];
int nxtA[100010], preA[100010];
int nxtB[100010], preB[100010];

void Do(int x) {
	//printf("%d\n", x);
	for(int i=1;i<=N;i++) {
		int j = i % N + 1;
		nxtA[A[i]] = A[j];
		preA[A[j]] = A[i];
		nxtB[B[i]] = B[j];
		preB[B[j]] = B[i];
	}
	int la = x, lb = x;
	int ra = la, rb = lb;
	vector <int> w;
	w.pb(x);
	while(nxtA[ra] != la) {
		int p1 = nxtA[ra];
		int p2 = preA[la];
		int q1 = nxtB[rb];
		int q2 = preB[lb];
		if(p1 == q1) ra = p1, rb = q1, w.pb(p1);
		else if(p1 == q2) ra = p1, lb = q2, w.pb(p1);
		else if(p2 == q1) la = p2, rb = q1, w.pb(p2);
		else if(p2 == q2) la = p2, lb = q2, w.pb(p2);
		else {
			for(int a=-1;a<0;a--) A[a] -= nxtA[a];
		}
	}
	for(int e : w) printf("%d ", e); puts("");
}

vector <int> Go(int nxt[], int l, int r) {
	vector <int> res;
	for(int x=l;x!=r;x=nxt[x]) res.pb(x);
	res.pb(r);
	return res;
}

void make(int nxt[], int pre[], int a, int b, int c, int d, int e) {
	nxt[a] = b; nxt[b] = c; nxt[c] = d; nxt[d] = e;
	pre[b] = a; pre[c] = b; pre[d] = c; pre[e] = d;
}

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", A + i);
	for(int i=1;i<=N;i++) scanf("%d", B + i);
	for(int i=1;i<=N;i++) {
		int j = i % N + 1;
		nxtA[A[i]] = A[j];
		preA[A[j]] = A[i];
		nxtB[B[i]] = B[j];
		preB[B[j]] = B[i];
	}
	for(int i=1;i<=N;i++) {
		if(chk[i]) continue;
		int la = i, lb = i;
		int ra = la, rb = lb;
		vector <int> w;
		w.pb(i);
		while(nxtA[ra] != la) {
			int p1 = nxtA[ra];
			int p2 = preA[la];
			int q1 = nxtB[rb];
			int q2 = preB[lb];
			if(p1 == q1) ra = p1, rb = q1, w.pb(p1);
			else if(p1 == q2) ra = p1, lb = q2, w.pb(p1);
			else if(p2 == q1) la = p2, rb = q1, w.pb(p2);
			else if(p2 == q2) la = p2, lb = q2, w.pb(p2);
			else break;
		}
		if(nxtA[ra] == la) {
			Do(i);
			return 0;
		}

		for(int e : w) chk[e] = 1;

		if(szz(w) > 3) {
			vector <int> va = Go(nxtA, la, ra);
			vector <int> vb = Go(nxtB, lb, rb);
			int cmd = 0;
			if(va == vb) cmd = 1;
			else {
				reverse(vb.begin(), vb.end());
				if(va == vb) cmd = 2;
			}
			vector <int> nva, nvb;
			int x1 = va[0], x2 = va[1], x3 = va[2];
			nva.pb(x1); nva.pb(x2); nva.pb(x3);
			if(cmd == 0) {
				nvb.pb(x2); nvb.pb(x1); nvb.pb(x3);
			}
			else if(cmd == 1) {
				nvb.pb(x1); nvb.pb(x2); nvb.pb(x3);
			}
			else {
				nvb.pb(x3); nvb.pb(x2); nvb.pb(x1);
			}
			int p1 = nxtA[ra], p2 = preA[la];
			int q1 = nxtB[rb], q2 = preB[lb];
			make(nxtA, preA, p2, nva[0], nva[1], nva[2], p1);
			make(nxtB, preB, q2, nvb[0], nvb[1], nvb[2], q1);
		}
	}
	puts("-1");

	return 0;
}