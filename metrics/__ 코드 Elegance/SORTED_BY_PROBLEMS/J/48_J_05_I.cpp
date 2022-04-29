#include <cstdio>
int main(){
	int n;
	scanf("%d", &n);
	if(n==3)
		puts("0");
	else
		printf("%d", (n+1)/2-1);
}

