#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int d[N];

int main(){
	int n;
	cin >> n;
	d[0] = d[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; ; j++){
			int t = 1;
			for(int k = 1; ; k++){
				if(i - 2*k < 0) break;
				if(j - d[i-k] == d[i-k] - d[i-2*k]){ t = 0; break; } 
			}
			if(t == 1){
				d[i] = j;
				break;
			}
		}
	}
	cout << d[n] << endl;
}
