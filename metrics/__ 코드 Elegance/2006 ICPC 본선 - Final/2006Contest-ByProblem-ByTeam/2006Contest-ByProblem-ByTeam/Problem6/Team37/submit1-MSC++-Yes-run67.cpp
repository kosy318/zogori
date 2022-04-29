#include <fstream>

using namespace std;


int n,M,res;
int a[30], b[30];

void input()
{
	scanf("%d",&n);
	int q;
	for(q=0;q<n;q++) scanf("%d %d",&a[q],&b[q]);
	scanf("%d",&M);
}

void process()
{
	int m,x;
	int eq,i,q;

	for(i=0;i<=M;i++) {
		m=M-i;
		eq=a[0]*i+b[0];
		
		for(q=1;q<n;q++) {
			if( (eq-b[q])%a[q] !=0 ) break;
			x=(eq-b[q])/a[q];
			if(x<0) break;
			m-=x;
		}
		if(q==n && m==0) {
			printf("%d\n",eq);
			return;
		}
	}
	printf("0\n");
}

int main()
{
	int nn,q;
	scanf("%d",&nn);
	for(q=0;q<nn;q++) {
		input();
		process();
	}
	return 0;
}

/*
3
3
3 5 4 3 1 7
27
3
3 5 4 3 1 7
26
8
2 156 2 2 2 216 4 12 3 24 5 36 1 96 3 6
695

*/