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

void print(int n, int l) {
	if (n==1) {
		printf("*");
		return;
	}
	if (l<n/3||n/3*2<=l) {
		print(n/3,l%(n/3));
		print(n/3,l%(n/3));
		print(n/3,l%(n/3));
	}
	else {
		print(n/3,l%(n/3));
		for (int i=0;i<n/3;i++) printf(" ");
		print(n/3,l%(n/3));
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		print(n,i);
		puts("");
	}

	return 0;
}