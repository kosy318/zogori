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

int main(){
	int n; scanf("%d", &n);
	int cnt = 0;
	while (n > 3) {
		n = (n + 1) / 2;
		cnt++;
	}
	if(n == 3) cnt *= 2;
	else cnt = cnt * 2 - 1;
	printf("%d\n", cnt);
	return 0;
}

