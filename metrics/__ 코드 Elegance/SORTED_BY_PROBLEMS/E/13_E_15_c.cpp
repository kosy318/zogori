#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int n, D[4010], C[4010][4010], T[4010], MM[4010], Res[4010], Ans[4010];
vector<int>G[4010];
struct AA{
	int b, e;
	bool operator <(const AA &p)const{
		return b<p.b;
	}
}w[2010];
int X[4010], CX;
int st[4010], top, O[4010];
void Put(int a){
	st[++top] = a;
	if(top>1){
		int b = a+1, e = CX, r = CX+1, mid;
		while(b<=e) {
			mid = (b + e) >> 1;
			if (D[st[top - 1]] + C[st[top - 1] + 1][mid] >= D[a] + C[a + 1][mid]) {
				r = mid;
				e = mid - 1;
			}
			else b = mid + 1;
		}
		O[top] = mid;
	}
}
void Do(){
	int i;
	top = 0;
	for(i=1;i<=CX;i++){
		for(auto &x: G[i]) {
			Put(x);
			while (top > 2 && O[top] > O[top - 1]) {
				top -= 2;
				Put(x);
			}
		}
		while(top>1 && D[st[top]]+C[st[top]+1][i] <= D[st[top-1]]+C[st[top-1]+1][i])top--;

		T[i] = D[st[top]]+C[st[top]+1][i];
	}
}
int main() {
	int i, j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&w[i].b,&w[i].e);
		X[++CX]= w[i].b;
		X[++CX] = w[i].e;
	}
	sort(X+1,X+CX+1);
	for(i=1;i<=n;i++){
		w[i].b = lower_bound(X+1,X+CX+1,w[i].b)-X;
		w[i].e = lower_bound(X+1,X+CX+1,w[i].e)-X;
		C[1][w[i].e]++;
		C[w[i].b+1][w[i].e]--;
		C[1][CX+1]--;
		C[w[i].b+1][CX+1]++;
		//printf("%d %d\n",w[i].b,w[i].e);
		//printf("%d %d %d\n",w[i].b,w[i].e,CX);
	}
	for(i=1;i<=CX;i++)for(j=1;j<=CX;j++)C[i][j]+=C[i][j-1];
	for(i=1;i<=CX;i++)for(j=1;j<=CX;j++)C[i][j]+=C[i-1][j];
	for(i=0;i<CX;i++){
		for(j=1;j<=CX;j++){
			if(C[i+1][j])break;
		}
		//printf("%d %d\n",j,i);
		G[j].push_back(i);
	}
	//for(i=1;i<=CX;i++)for(j=1;j<=CX;j++)if(!C[i][j])C[i][j]=-5e8;
	//for(i=1;i<=CX;i++)for(j=1;j<=CX;j++)printf("%d %d %d\n",i,j,C[i][j]);
	for(i=1;i<=CX;i++)D[i]=-1e9;
	for(i=1;i<=n;i++){
		Do();
		for(j=0;j<=CX;j++)D[j]=T[j];
		for(j=0;j<=CX;j++){
			if(D[j]==0)D[j]=-1e9;
		//printf("%d ",D[j]);
		}
		//puts("");
		MM[i] = D[CX];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j<=i && i<=MM[j])Ans[i] = j;
		}
	}
	for(i=n;i>=1;i--)printf("%d ",Ans[i]);
}