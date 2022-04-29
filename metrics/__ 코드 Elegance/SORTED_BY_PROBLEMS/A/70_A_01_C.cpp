#include <bits/stdc++.h>

using namespace std;

int a[1003] = {1, 1, };
int chk[10003];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	
	cin >> n;
	for(int i=2;i<=n;i++){
		memset(chk, 0, sizeof(chk));
		for(int k=0;k<=i/2;k++){
			int nxt = 2*a[i-k] - a[i-2*k];
			if(nxt >= 0 && nxt <= 10000) chk[nxt] = 1; 
		}
		for(int j=0;j<=10000;j++){
			if(!chk[j]) {
				a[i] = j;
				break;
			}
		}
	}
	cout << a[n] << '\n';
}
