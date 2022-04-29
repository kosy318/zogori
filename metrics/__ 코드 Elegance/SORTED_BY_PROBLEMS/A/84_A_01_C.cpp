#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

int n,i,j,k,A[N];

int main() {
	cin >> n;
	A[0] = A[1] = 1;	
	for(i=2;i<=n;i++){
		for(j=1;;j++){
			for(k=i&1;k<i;k+=2)
				if(j+A[k] == 2*A[(i+k)>>1])
					break;
			if(k == i) break;
		}
		A[i] = j;
	}
	
	cout << A[n];
	return 0;
}
