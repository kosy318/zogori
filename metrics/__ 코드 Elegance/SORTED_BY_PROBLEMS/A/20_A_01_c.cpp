#include<bits/stdc++.h>
using namespace std;

int a[1005] = {0};
int b[3005] = {0};
set<int> x;
int main(){
	a[0] = a[1] = 1;
	int n;
	scanf("%d", &n);
	for(int i=2;i<=n;i++){
		for(int j=1;i-j-j>=0;j++){
			if(2 * a[i-j] - a[i-j-j] > 0){
				b[2*a[i-j]-a[i-j-j]] = i;
			}
		}
		for(int j=1;;j++){
			if(b[j] == i) continue;
			a[i] = j;
			break;
		}
	}
	printf("%d\n", a[n]);
}
