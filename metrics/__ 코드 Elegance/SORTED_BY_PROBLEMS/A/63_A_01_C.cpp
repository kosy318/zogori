#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(X) (X).begin(), (X).end()
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define pb push_back
typedef long long LL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e6 + 7;

int a[MXN];
int main(){
	IOS;
	int n;
	a[0] = a[1] = 1;
	for(int i=2;i<=1000;i++){
		set<int> s;
		for(int j=1;j<=1006;j++) s.insert(j);
		for(int k=1;i-2*k>=0;k++){
			s.erase(2*a[i-k]-a[i-2*k]);
		}
		a[i] = *s.begin();
	}
	cin >> n;
	cout << a[n] << '\n';
	return 0;
}

