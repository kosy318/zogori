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
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;

struct pt{
	ll x, y;
	pt():x(0),y(0){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator- (pt z){
		return pt(x - z.x, y - z.y);
	}
	ll operator* (pt z){
		return x * z.y - y * z.x;	
	}
	pt operator+ (pt z){
		return pt(x + z.x, y + z.y);
	}
	bool operator< (pt z){
		return x == z.x ? y < z.y : x < z.x;
	}
};

ll A(pt a, pt b, pt c, pt d){ //ccw-ordered in a-b-c-d-a
	return (b-a)*(c-a) + (c-a)*(d-a);
}

ll inp(pt u, pt v){
	return u.x * v.x + u.y * v.y;
}

inline int sgn(ll x){
	return x > 0 ? 1 : -1;
}

int cross(pt a, pt b, pt c, pt d){
	return sgn((b-a)*(c-a)) != sgn((b-a)*(d-a)) && sgn((d-c)*(a-c)) != sgn((d-c)*(b-c));
}

int n;
pt a[1005];
int idx[1005];
using tam = pair<pt,pii>;
vector<tam> V;

int main(){
	fio;
	//pt a(0,0), b(4,0), c(1,1), d(0,3);
	//cout << A(a,b,c,d) << ' ' << A(a,b,d,c) << ' ' << A(c,b,d,a) << '\n';
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a+1,a+n+1);
	iota(idx, idx+n+1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			V.ep(a[j] - a[i], pii(i, j));
		}
	}
	sort(V.begin(), V.end(), [](tam u, tam v){
		ll C = u.va * v.va;
		if(C) return C > 0;
		return u.vb < v.vb;
	});
	ll cor = 0, minA = LLONG_MAX, numA = 0;
	for(tam t : V){
		swap(a[idx[t.vb.va]], a[idx[t.vb.vb]]);
		swap(idx[t.vb.va], idx[t.vb.vb]);
		int mm = min(idx[t.vb.va], idx[t.vb.vb]);
		cor += ll(mm-1) * (n-mm-1);
		for(int l = mm - 1; l >= max(1,mm - 2); l--){
			for(int r = mm + 2; r <= min(n, mm + 3); r++){
				ll area = abs(A(a[mm], a[l], a[mm+1], a[r]));
				debug("%d %d %d %d\n",mm,l,mm+1,r);
				debug("%lld\n",area);
				if(area < minA){
					minA = area;
					numA = 0;
				}
				if(area == minA){
					numA += 2 - cross(a[mm], a[mm+1], a[l], a[r]);
				}
			}
		}
	}
	cout << cor + numA << '\n';
}
