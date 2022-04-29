#include <cstdio>
#include <cstring>

using namespace std;

int D[205][6005];
int dist[6005][155];
int lcs[205][205];
char st1[55];
char st2[5005];
int n,m;

int min_(int a,int b,int c) {
	if (a<=b && a<=c) return a;
	if (b<=a && b<=c) return b;
	if (c<=a && c<=b) return c;
}

int process_() {
	int i,j,k,ks;
	int a,b,c;
	int min,now;
	int ok,sol=-1;

	for (i=1;i<=m;i++) {
		
		// init
		for (j=0;j<=n;j++) lcs[j][0]=j;
		for (j=0;j<=m;j++) lcs[0][j]=j;

		for (j=1;j<=n;j++) {
			for (k=i;k<i+2*n;k++) {
				if (k>m) break;
				if (st1[j-1]==st2[k-1]) {
					a=lcs[j-1][k-1-i+1];
				} else {
					a=lcs[j-1][k-1-i+1]+1;
				}
				b=lcs[j-1][k-i+1]+1;
				c=lcs[j][k-1-i+1]+1;
				min=min_(a,b,c);
				lcs[j][k-i+1]=min;	
			}
		}
		for (j=i;j<i+2*n;j++) {
			if (j>m) break;
			dist[i][j-i+1]=lcs[n][j-i+1];
		}
	}

	for (j=0;j<=m;j++) {
		D[0][j]=j;
	}
	for (i=1;i<=2*n*2;i++) {
		ok=0;
		for (j=i;j<=m;j++) { // 5000
			ok=1; min=-1;
			ks=j-n*2+1;
			if (ks<1) ks=1;
			for (k=ks;k<=j;k++) { // 100
				a=D[i-1][k-1];
				b=dist[k][j-k+1];
				now=(a>b)?a:b;
				if (min==-1) {
					min=now;
				} else if (min>now) {
					min=now;
				}
			}
			D[i][j]=min;
		}
		min=D[i][m];
		if (ok==1) {
			if (sol==-1) sol=min;
			else if (sol>min) sol=min;
		} else 
			break;
	}
	return sol;
}

void input_() {
	int t,T;
	int result;
	scanf ("%d",&T);
	for (t=1;t<=T;t++) {
		scanf ("%s",st1);
		scanf ("%s",st2);
		n=strlen(st1);
		m=strlen(st2);
		result=process_();
		printf ("%d\n",result);
	}
}

int main() {
	input_();
	return 0;
}
/*
1
aqwer
abbbacccaddd
3
abc
abcdabcabb
abab
ababababababab
xyz
abcdefghikjlmn
*/