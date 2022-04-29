#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
vector<int>E[N_], L[N_];
int n, C[N_], chk[N_], Leaf[N_];
long long Dis[N_];
vector<int>TP;
void DFS1(int a, int pp, long long d){
	C[a]=1;
	TP.push_back(a);
	Dis[a] = d;
	for(int i=0;i<E[a].size();i++){
		int x = E[a][i];
		if(x==pp || chk[x])continue;
		DFS1(x,a,d+L[a][i]);
		C[a]+=C[x];
	}
}
int get_mid(int a, int pp, int c){
	for(auto &x: E[a]){
		if(x==pp||chk[x])continue;
		if(C[x]>c)return get_mid(x,a,c);
	}
	return a;
}
long long res;
void Do(int a){
	TP.clear();
	DFS1(a,0,0);
	if(C[a]==1)return;
	int m = get_mid(a,0,C[a]/2);
	chk[m] = 1;
	for(auto &x : E[m]) {
		if (chk[x])continue;
		Do(x);
	}
	long long ss = 0;
	//printf("%d\n",m);
	long long aa = 0;
	int sc = 0;
	for(int i=0;i<E[m].size();i++){
		int x = E[m][i];
		if(chk[x])continue;
		TP.clear();
		DFS1(x, m, L[m][i]);
		long long ts = 0;
		long long bb = 0;
		int cc = 0;
		for(auto &t : TP){
			if(Leaf[t]) {
				cc++;
				if(Leaf[m])res += Dis[t] * Dis[t];
				bb += Dis[t]*Dis[t];
				//printf("%d %lld\n",t,Dis[t]);
				ts += Dis[t];
			}
		}
		res -= bb*cc;
		aa += bb;
		sc+=cc;
		res += ss*ts*2;
		ss+=ts;
	}
	res += aa*sc;
	chk[m] = 0;
}
int main(){
	int i, a, b, c;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(c);
		L[b].push_back(c);
	}
	for(i=1;i<=n;i++){
		if(E[i].size()==1)Leaf[i] = 1;
	}
	Do(1);
	printf("%d\n",res);
}