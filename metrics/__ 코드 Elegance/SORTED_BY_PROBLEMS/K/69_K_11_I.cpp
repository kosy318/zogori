#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

struct point
{
  double x;
  double y;
  double z;
};

point operator - (const point &a, const point &b)
{
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

point operator + (const point &a, const point &b)
{
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}

point operator / (const point &a, double v)
{
  return {a.x / v, a.y / v, a.z / v};
}

double norm(point a)
{
  return a.x * a.x + a.y * a.y + a.z * a.z;
}

int n;
int m;
point p[maxn];

int belong[maxn];

double A;
double B;
double C;
double D;

void cross(point a, point b, double &x, double &y, double &z)
{
  x=a.y*b.z-a.z*b.y;
  y=a.z*b.x-a.x*b.z;
  z=a.x*b.y-a.y*b.x;
}

void prepare(point a, point b, point c)
{
  cross(b - a, c - a, A, B, C);
  D = -(a.x * A + a.y * B + a.z * C);
}

bool check(point pt)
{
  double res = A * pt.x + B * pt.y + C * pt.z + D;
  return res > 0;
}

double calc(int bl)
{
  int tot = 0;
  double ans = 0;
  point sum = {0, 0, 0};
  for (int i = 1; i <= n; i++) {
    if (belong[i] == bl) {
      sum = sum + p[i];
      tot ++;
    }
  }
  if (tot == 0) return 0;
  sum = sum / tot;
  for (int i = 1; i <= n; i++) {
    if (belong[i] == bl) {
      ans += norm(p[i] - sum);
    }
  }
  return ans;
}

double calc()
{
  return calc(0) + calc(1);
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].z;
  }
  double ans = 0;
  if (m == 1) {
    ans = calc(0);
  } else {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
	for (int k = j + 1; k <= n; k++) {
	  for (int status = 0; status < (1 << 3); status++) {
	    belong[i] = status & 1;
	    belong[j] = (status >> 1) & 1;
	    belong[k] = (status >> 2) & 1;
	    prepare(p[i], p[j], p[k]);
	    for (int t = 1; t <= n; t++) {
	      if (t == i || t == j || t == k) continue;
	      belong[t] = check(p[t]);
	    }
	    if (!flag) {
	      ans = calc();
	      flag = true;
	    } else {
	      ans = min(ans, calc());
	    }
	  }
	}
      }
    }
  }
  cout << setprecision(6) << fixed << ans << endl;
  return 0;
}
