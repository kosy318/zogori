#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define ii pair<int,int>
#define st first
#define nd second
using namespace std;

int f(int x) {

	if(x==3) return 0;
	if(x==4) return 1;
	if(x==5) return 2;
	if(x==6) return 2;
	
	return f((x+1)/2)+2;
	
}

int main() {
	
	int x;

	scanf("%d",&x);
	
	for(int i=x;i<=x;i++)
	
	printf("%d",f(i));
	
}
