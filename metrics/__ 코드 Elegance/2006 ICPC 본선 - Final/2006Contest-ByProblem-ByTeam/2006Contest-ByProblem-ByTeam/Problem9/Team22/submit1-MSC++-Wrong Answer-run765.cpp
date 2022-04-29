#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ERR 1e-4
#define INF 99999999
typedef struct _p {
	double x, y;
} POINT;
POINT pt[1001];
int ccw(POINT a, POINT b, POINT c)
{
	double l = (a.x*b.y+b.x*c.y+c.x*a.y) - (a.y*b.x+b.y*c.x+c.y*a.x);
	if (l > 0)
		return 1;
	else if (l < 0)
		return -1;
	return 0;
}
int main()
{
	int tc;
	int n;
	double min1, left, right, mid;
	int i, j, l;
	int fl;
	POINT p;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%lf%lf", &pt[i].x, &pt[i].y);
		}
		min1 = INF;
		left = 0;
		right = 1000;
		fl = 0;
		while (1) {
			mid = (left + right) * 0.5;
			for (i = 0; i < n; i++) {
				if (i+1 < n && pt[i].y == pt[i+1].y) {
					p.x = (pt[i].x + pt[i+1].x) * 0.5;
					p.y = pt[i].y + mid;
				}
				else {
				p.x = pt[i].x;
				p.y = pt[i].y + mid;
				}

				for (j = i-1; j >= 0; j--) {
					l = ccw(p, pt[j+1], pt[j]);
					if (l > 0)
						break;
				}
				if (j >= 0) {
					continue;
				}
				for (j = i+1; j < n; j++) {
					l = ccw(p, pt[j-1], pt[j]);
					if (l < 0) {
						break;
					}
				}
				if (j < n) {
					continue;
				}
				break;
			}

			if (i < n) {
				fl = 1;
				right = mid;
				min1 = mid;
				printf("min1 = %lf..\n", min1);
		//		mid = (right+left)*0.5;
			}
			else {
				left = mid;
		//		mid = (right+left)*0.5;
			}
			if (right - left < ERR)
				break;
		}
		if (!fl) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%.1lf\n", min1);
		}
	}
	return 0;
}