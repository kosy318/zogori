#pragma optimize("awgty", on)

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const double eps = numeric_limits<float>::epsilon();

struct POINT
{
	double x, y;
	POINT(void)
	{
		;
	}
	POINT(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	bool operator <(const POINT &rhs) const
	{
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	bool operator ==(const POINT &rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
};

struct EVENT
{
	POINT p;
	int a, b;
	EVENT(void)
	{
		;
	}
	EVENT(const POINT &p, int a, int b)
	{
		this->p = p;
		this->a = a;
		this->b = b;
	}
	bool operator <(const EVENT &rhs) const
	{
		return p < rhs.p;
	}
};

#define MAXN 1000
#define MAXM (MAXN * (MAXN - 1) / 2)

EVENT event[MAXM];
int M;

POINT p[MAXN];
int N;

int line_id[MAXN];
int line_index[MAXN];

double xs[MAXM + MAXN + 2];
int xn;

double gety(int i, double x)
{
	return ((x - p[i].x) * p[i + 1].y - (x - p[i + 1].x) * p[i].y) / (p[i + 1].x - p[i].x);
}

struct comp
{
	double x;
	comp(double x)
	{
		this->x = x;
	}
	bool operator ()(int lhs, int rhs) const
	{
		return gety(lhs, x) < gety(rhs, x);
	}
};

struct comp2
{
	bool operator ()(int lhs, int rhs) const
	{
		return line_index[lhs] < line_index[rhs];
	}
};

double cross(const POINT &a, const POINT &b, const POINT &c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

void preprocess(void)
{
	M = 0;
	for(int i = 0; i < N - 1; ++i)
	{
		double dxi = p[i + 1].x - p[i].x;
		double dyi = p[i + 1].y - p[i].y;
		for(int j = i + 1; j < N; ++j)
		{
			double dxj = p[j + 1].x - p[j].x;
			double dyj = p[j + 1].y - p[j].y;
			if(dxi * dyj != dxj * dyi)
			{
				double s1 = cross(p[i], p[i + 1], p[j]);
				double s2 = cross(p[i], p[i + 1], p[j + 1]);
				double x = (s1 * p[j + 1].x - s2 * p[j].x) / (s1 - s2);
				double y = (s1 * p[j + 1].y - s2 * p[j].y) / (s1 - s2);
				if(x > p[0].x && x < p[N].x)
				{
					event[M++] = EVENT(POINT(x, y), i, j);
				}
			}
		}
	}
	sort(event, event + M);
	xn = 0;
	for(int i = 0, j; i < M; i = j)
	{
		for(j = i + 1; j < M && fabs(event[i].p.x - event[j].p.x) < eps; ++j)
		{
			;
		}
		xs[xn++] = event[i].p.x;
	}
	for(int i = 0; i <= N; ++i)
	{
		xs[xn++] = p[i].x;
	}
	sort(xs, xs + xn);
	xn = unique(xs, xs + xn) - xs;
	for(int i = 0; i < N; ++i)
	{
		line_id[i] = i;
	}
	sort(line_id, line_id + N, comp((xs[0] + xs[1]) / 2));
	for(int i = 0; i < N; ++i)
	{
		line_index[line_id[i]] = i;
	}
}

void dump(void)
{
	for(int i = N - 1; i >= 0; --i)
	{
		printf("%d ", line_id[i]);
	}
	putchar('\n');
}

void solve(void)
{
	int i, j, k, l, m, n;
	double h, t;
	preprocess();
/*	printf("M = %d xn = %d\n", M, xn);
	for(int i = 0; i < xn; ++i)
	{
		printf("%lg ", xs[i]);
	}
	putchar('\n');
	for(int i = 0; i < M; ++i)
	{
		printf("%d %d %lg %lg\n", event[i].a, event[i].b, event[i].p.x, event[i].p.y);
	}*/
//	dump();
	h = gety(line_id[N - 1], xs[0]) - gety(0, xs[0]);
	for(i = 0, j = 0, l = 0; i < xn - 1; ++i)
	{
		if(p[l + 1].x == xs[i])
		{
			++l;
		}
		for(k = j; k < M && fabs(event[k].p.x - xs[i]) < eps; ++k)
		{
			;
		}
		while(j != k)
		{
			vector<int> s;
			for(m = j; m < k && fabs(event[m].p.y - event[j].p.y) < eps; ++m)
			{
				s.push_back(event[m].a);
				s.push_back(event[m].b);
			}
			j = m;
			sort(s.begin(), s.end(), comp2());
			s.erase(unique(s.begin(), s.end()), s.end());
			for(n = 0, m = (int)s.size() - 1; n < m; ++n, --m)
			{
				int a = s[n], b = s[m];
				swap(line_id[line_index[a]], line_id[line_index[b]]);
				swap(line_index[a], line_index[b]);
			}
		}
	//	dump();
		t = gety(line_id[N - 1], xs[i + 1]) - gety(l, xs[i + 1]);
	//	printf("%d: x = %lg, %lg(%d) - %lg(%d) = %lg\n", i, xs[i], gety(line_id[N - 1], xs[i + 1]), line_id[N - 1], gety(l, xs[i + 1]), l, t);
		if(t < h)
		{
			h = t;
		}
	}
	if(h < 1000 + eps)
	{
		printf("%.1lf\n", h);
	}
	else
	{
		puts("IMPOSSIBLE");
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(--t >= 0)
	{
		scanf("%d", &N);
		--N;
		for(int i = 0; i <= N; ++i)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		solve();
	}
	return 0;
}
