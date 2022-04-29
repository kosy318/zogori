#include <bits/stdc++.h>
#define fs first
#define se second
#define va first
#define vb second
#define y0 qweriuot
#define y1 asdfjklhaks
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pp push_back
#define ep emplace_back

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using ll = long long; using llong = long long;
using ld = long double;
using lf = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;

struct pt{
	ll x,y,z;
	pt():x(0),y(0),z(0){}
	pt(ll x, ll y, ll z):x(x),y(y),z(z){}
	pt operator+ (pt u){
		return pt(x + u.x, y + u.y, z + u.z);
	}
	pt operator- (pt u){
		return pt(x - u.x, y - u.y, z - u.z);
	}
	ll operator* (pt u){
		return x * u.x + y * u.y + z * u.z;
	}
};
inline ll sq(ll x){return x*x;}
inline ll sq(pt z){return sq(z.x) + sq(z.y) + sq(z.z);}

ll var(vector<pt> &v){
	pt m;
	for(int i = 0; i < v.size(); i++){
		v[i].x *= v.size();
		v[i].y *= v.size();
		v[i].z *= v.size();
		m = m + v[i];
	}
	m.x /= v.size(); m.y /= v.size(); m.z /= v.size();
	ll V = 0;
	for(int i = 0; i < v.size(); i++) V += sq(v[i] - m);
	return V;
}

pt P[105];
int n, k;

void pro(lf &ans){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			pt d = P[j] - P[i];
			vector<pt> A, B;
			sort(P+1, P+n+1, [d](pt u, pt v){return u*d < v*d;});
			for(int k = 1; k < n; k++){
				A.clear(); B.clear();
				copy(P+1, P+k+1, back_inserter(A));
				copy(P+k+1, P+n+1, back_inserter(B));
				ll v1 = var(A), v2 = var(B);
				lf calc = lf(v1) / sq(A.size()) + lf(v2) / sq(B.size());
				ans = min(ans, calc);
			}
		}
	}
	cout << ans << '\n';
	return;
}

int main(){
	fio;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> P[i].x >> P[i].y >> P[i].z;
	}
	cout << fixed; cout.precision(6);
	vector<pt> X; copy(P+1,P+n+1,back_inserter(X));
	ld x = ld(var(X)) / sq(n);
	if(k == 1){
		cout << x << '\n';
		return 0;
	}
	pro(x);
}
