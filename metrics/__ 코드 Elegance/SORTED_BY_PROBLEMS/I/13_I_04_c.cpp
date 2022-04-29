#include<bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef pair<int, int> pii;
#define Fi first
#define Se second

int N;
pii p[100010];

int main(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = pii(x, x+y);
	}
	sort(p+1, p+1+N);
	ll low = 0, high = 1e10, res = -1;
	while(low <= high) {
		ll mid = (low + high) >> 1;
		ll now = p[1].Fi;
		int ok = 1;
		for(int i=2;i<=N;i++) {
			now += mid;
			if(now > p[i].Se) {
				ok = 0; break;
			}
			if(now < p[i].Fi) now = p[i].Fi;
		}
		if(ok) res = mid, low = mid + 1;
		else high = mid - 1;
	}
	printf("%lld\n", res);
	return 0;
}