#include <stdio.h>
#include <algorithm>
using namespace std;

struct xy
{
	int x, y;
	bool operator < ( const xy& _xy ) const
	{
		return (y<_xy.y || (y==_xy.y && x<_xy.x));
	}
};

xy pt[20000];

long long upper[50001], lower[50001];
long long find(int w, int h, int n)
{
	sort(pt, pt+n);
	int from = 0;
	int left = w;
	int right = 0;
	int i, j;

	for (i=0; i<n; i++)
	{
		for (j=from; j<pt[i].y; j++)
			upper[j] = right-left;
		if ( pt[i].x<left ) left = pt[i].x;
		if ( pt[i].x>right ) right = pt[i].x;
		from = pt[i].y;
	}
	for (j=from; j<h; j++) upper[j] = right-left;

	from = h-1; left = w; right = 0;
	for (i=n-1; i>=0; i--)
	{
		for (j=from; j>=pt[i].y; j--)
			lower[j] = right-left;
		if ( pt[i].x<left ) left = pt[i].x;
		if ( pt[i].x>right ) right = pt[i].x;
		from = pt[i].y-1;
	}
	for (j=from; j>=0; j--) lower[j] = right-left;

	for (j=0; j<h; j++)
	{
		if ( upper[j] < 0 ) upper[j] = 0;
		if ( lower[j] < 0 ) lower[j] = 0;
	}

	for (j=1; j<h; j++) upper[j] += upper[j-1];
	for (j=h-2; j>=0; j--) lower[j] += lower[j+1];

	long long mmin = upper[h-2] + w;
	if ( lower[1] + w < mmin ) mmin = lower[1] + w;
	for (j=1; j<h-1; j++)
		if ( upper[j-1] + lower[j+1] + w < mmin ) mmin = upper[j-1] + lower[j+1] + w;
	return mmin;
}	

int main()
{
	int t;
	scanf("%d", &t);
	int i, j;
	for (i=0; i<t; i++)
	{
		int w, h, n;
		scanf("%d %d", &w, &h);
		scanf("%d", &n);
		for (j=0; j<n; j++)
		{
			int tx, ty;
			scanf("%d %d", &tx, &ty);
			pt[j*4].x = tx-1; pt[j*4].y = ty-1;
			pt[j*4+1].x = tx-1; pt[j*4+1].y = ty+1;
			pt[j*4+2].x = tx+1; pt[j*4+2].y = ty-1;
			pt[j*4+3].x = tx+1; pt[j*4+3].y = ty+1;
		}
		n*=4;
		for (j=0; j<n; j++)
		{
			if ( pt[j].x<0 ) pt[j].x = 0;
			if ( pt[j].x>w ) pt[j].x = w;
			if ( pt[j].y<0 ) pt[j].y = 0;
			if ( pt[j].y>h ) pt[j].y = h;
		}

		long long case1 = find(w, h, n);

		for (j=0; j<n; j++)
		{
			int temp = pt[j].x; pt[j].x = pt[j].y; pt[j].y = temp;
		}

		long long case2 = find(h, w, n);

		if ( case1 > case2 ) case1 = case2;
		printf("%I64d\n", case1);
	}
	return 0;
}