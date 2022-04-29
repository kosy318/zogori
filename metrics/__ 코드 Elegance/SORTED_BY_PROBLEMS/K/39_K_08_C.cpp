#include <bits/stdc++.h>
using namespace std;
#define rrep(i,n) for(int i=1; i<=n; ++i)

int n, k;
struct pt {
	int x, y, z;
} d[101];

inline pt cross(pt L, pt R) {
	return {
		L.y*R.z - L.z*R.y,
		L.z*R.x - L.x*R.z,
		L.x*R.y - L.y*R.x
	};
}

pt operator+(pt l, pt r) {
	return {
		l.x+r.x,
		l.y+r.y,
		l.z+r.z
	};
}

pt operator-(pt l, pt r) {
	return {
		l.x-r.x,
		l.y-r.y,
		l.z-r.z
	};
}

inline long long dot(pt& L, pt& R) {
	return L.x*R.x + L.y*R.y + L.z*R.z;
}

long long dots[101];
int idx[101];

pt ps[101];
pt pss[101];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d%d%d", &d[i].x, &d[i].y, &d[i].z);

	auto calc = [&](pt a, pt s, int c) {
		double ret = 0, t = 0;
		t = a.x - double(s.x)/c; ret += t*t;
		t = a.y - double(s.y)/c; ret += t*t;
		t = a.z - double(s.z)/c; ret += t*t;
		return ret;
	};

	pt S = {0, 0, 0};
	rrep(i, n) S = S + d[i];
	double ans = 0;

	rrep(i, n) {
		ans += calc(d[i], S, n);
	}

	if(k==1) {
		printf("%.6f\n", ans);
		return 0;
	}

	auto sq = [&](const pt& q)->pt {
		return {q.x*q.x, q.y*q.y, q.z*q.z};
	};

	rrep(i, n) {
		ps[i] = ps[i-1] + d[i];
		pss[i] = pss[i-1] + sq(d[i]);
	}

	rrep(i, n) {
		pt ts = ps[n] - d[i];
		pt tss = pss[n] - sq(d[i]);

		auto wow = [&](pt &sum, pt &sqsum) {
			double ret = 0;
			#define WORK(c) {ret += sqsum.c - double(sum.c * 1ll * sum.c) / (n-1); }
			WORK(x);
			WORK(y);
			WORK(z);
#undef WORK
			return ret;
		};

		ans = min(ans, wow(ts, tss));
	}

	iota(idx+1, idx+n+1, 1);

	auto getans = [&](int l, int r) {
		double ret = 0;
		int cnt = r-l+1;
		#define WORK(c) {double t = ps[r].c-ps[l-1].c; \
		t = t*t / cnt; \
		ret += pss[r].c-pss[l-1].c - t;}
		WORK(x);
		WORK(y);
		WORK(z);
		return ret;
	};

	rrep(i, n) {
		for(int j=1; j<i; ++j) {
			for(int k=1; k<j; ++k) {
				pt v = cross(d[i], d[j]) + cross(d[j], d[k]) + cross(d[k], d[i]);
				rrep(l, n) {
					dots[l] = dot(d[l], v);
				}
				sort(idx+1, idx+n+1, [&](const int& a, const int& b){
					return dots[a] < dots[b];
				});

				rrep(l, n) {
					ps[l]=ps[l-1]+d[idx[l]];
					pss[l]=pss[l-1]+sq(d[idx[l]]);
				}

				for(int l=1; l<n; ++l) {
					ans = min(ans, getans(1, l) + getans(l+1, n));
				}
			}
		}
	}

	printf("%.6f\n", ans);
	return 0;
}
