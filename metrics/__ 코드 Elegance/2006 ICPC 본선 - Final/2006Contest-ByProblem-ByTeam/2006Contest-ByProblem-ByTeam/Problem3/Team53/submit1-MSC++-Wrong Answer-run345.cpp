#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

struct point
{
	int x,y;
};

point v[1001];
int n;
int w,h;
set<int> xset, yset;
vector<int> xv,yv;
int xx[1001][2];
int yy[1001][2];
int a[2][1001][3];

void xsort(point a[], int n)
{
	int i,j;
	point t;

	if(n<2)
		return;

	j=0;
	for(i=1; i<n; i++)
		if(a[0].x > a[i].x || (a[0].x == a[i].x && a[0].y > a[i].y))
		{
			j++;
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}

	t = a[0];
	a[0] = a[j];
	a[j] = t;

	xsort(a, j);
	xsort(a+j+1,n-(j+1));
}

void ysort(point a[], int n)
{
	int i,j;
	point t;

	if(n<2)
		return;

	j=0;
	for(i=1; i<n; i++)
		if(a[0].y > a[i].y || (a[0].y == a[i].y && a[0].x > a[i].x))
		{
			j++;
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}

	t = a[0];
	a[0] = a[j];
	a[j] = t;

	ysort(a, j);
	ysort(a+j+1,n-(j+1));
}

int main(void)
{
	int t, ct;
	int i,j,k;
	int px, py;

//	freopen("c.in","r",stdin);

	scanf("%d",&t);
	for(ct=0; ct<t; ct++)
	{
		scanf("%d %d",&w, &h);
		scanf("%d",&n);
		xset.clear(); 
		yset.clear();
		xv.clear();
		yv.clear();
		for(i=0; i<n; i++)
		{
			scanf("%d %d",&px, &py);
			v[i].x = px;
			v[i].y = py;
			xset.insert(px);
			yset.insert(py);
		}

		set<int>::iterator siter;
		for(siter = xset.begin(); siter != xset.end(); ++siter)
			xv.push_back((*siter));
		for(siter = yset.begin(); siter != yset.end(); ++siter)
			yv.push_back((*siter));

		xsort(v,n);
		j=0;
		for(i=0; i<xv.size(); i++)
		{
			k = j;
			while(k+1 < n && v[k+1].x == xv[i]) k++;
			xx[i][0] = v[j].y < v[k].y ? v[j].y : v[k].y;
			if(xx[i][0]-1 >= 0) xx[i][0]--;
			xx[i][1] = v[j].y > v[k].y ? v[j].y : v[k].y;
			if(xx[i][1]+1 <= h) xx[i][1]++;
			j = k+1;
		}
		
		ysort(v,n);
		j=0;
		for(i=0; i<yv.size(); i++)
		{
			k = j;
			while(k+1 < n && v[k+1].y == yv[i]) k++;
			yy[i][0] = v[j].x < v[k].x ? v[j].x : v[k].x;
			if(yy[i][0]-1 >=0) yy[i][0]--;
			yy[i][1] = v[j].x > v[k].x ? v[j].x : v[k].x;
			if(yy[i][1]+1 <= w) yy[i][1]++;
			j = k+1;
		}

		int result = w*h;

		/////////////////
		for(i=0; i<xv.size(); i++)
		{
			if(i==0)
			{
				a[0][i][0] = xx[i][0];
				a[0][i][1] = xx[i][1];
				if(xv[i]==0)
					a[0][i][2] = 0;
				else
					a[0][i][2] = a[0][i][1] - a[0][i][0];
			}
			else
			{
				a[0][i][0] = xx[i][0] < a[0][i-1][0] ? xx[i][0] : a[0][i-1][0];
				a[0][i][1] = xx[i][1] > a[0][i-1][1] ? xx[i][1] : a[0][i-1][1];
				a[0][i][2] = (a[0][i][1] - a[0][i][0]) +(a[0][i-1][1] - a[0][i-1][0])*(xv[i] - xv[i-1] -1) + a[0][i-1][2];
			}
		}

		for(i=0; i<xv.size(); i++)
		{
			int ri = xv.size() - i -1;
			if(i==0)
			{
				a[1][ri][0] = xx[ri][0];
				a[1][ri][1] = xx[ri][1];
				if(xv[ri]==w)
					a[1][ri][2] = 0;
				else
					a[1][ri][2] = a[0][i][1] - a[0][i][0];
			}
			else
			{
				a[1][ri][0] = xx[ri][0] < a[1][ri+1][0] ? xx[ri][0] : a[1][ri+1][0];
				a[1][ri][1] = xx[ri][1] > a[1][ri+1][1] ? xx[ri][1] : a[1][ri+1][1];
				a[1][ri][2] = (a[1][ri][1] - a[1][ri][0]) +(a[1][ri+1][1] - a[1][ri+1][0])*(xv[ri+1] - xv[ri] -1) + a[1][ri+1][2];
			}
		}

		for(i=0; i<xv.size(); i++)
		{
			if( result > a[0][i][2] + a[1][i][2] + (h-(a[1][i][1]-a[1][i][0])))
			{
				result = a[0][i][2] + a[1][i][2] + (h-(a[1][i][1]-a[1][i][0]));
				//printf("%d : %d, %d, %d\n",xv[i],a[0][i][2], a[1][i][2], (h-(a[1][i][1]-a[1][i][0])));
			}
		}


		/////////////////
		for(i=0; i<yv.size(); i++)
		{
			if(i==0)
			{
				a[0][i][0] = yy[i][0];
				a[0][i][1] = yy[i][1];
				if(yv[i]==0)
					a[0][i][2] = 0;
				else
					a[0][i][2] = a[0][i][1] - a[0][i][0];
			}
			else
			{
				a[0][i][0] = yy[i][0] < a[0][i-1][0] ? yy[i][0] : a[0][i-1][0];
				a[0][i][1] = yy[i][1] > a[0][i-1][1] ? yy[i][1] : a[0][i-1][1];
				a[0][i][2] = (a[0][i][1] - a[0][i][0]) +(a[0][i-1][1] - a[0][i-1][0])*(yv[i] - yv[i-1]-1) + a[0][i-1][2];
			}
		}

		for(i=0; i<yv.size(); i++)
		{
			int ri = yv.size() - i -1;
			if(i==0)
			{
				a[1][ri][0] = yy[ri][0];
				a[1][ri][1] = yy[ri][1];
				if(yv[ri]==w)
					a[1][ri][2] = 0;
				else
					a[1][ri][2] = a[0][i][1] - a[0][i][0];
			}
			else
			{
				a[1][ri][0] = yy[ri][0] < a[1][ri+1][0] ? yy[ri][0] : a[1][ri+1][0];
				a[1][ri][1] = yy[ri][1] > a[1][ri+1][1] ? yy[ri][1] : a[1][ri+1][1];
				a[1][ri][2] = (a[1][ri][1] - a[1][ri][0]) +(a[1][ri+1][1] - a[1][ri+1][0])*(yv[ri+1] - yv[ri]-1) + a[1][ri+1][2];
			}
		}

		for(i=0; i<yv.size(); i++)
		{
			if( result > a[0][i][2] + a[1][i][2] + (w-(a[1][i][1]-a[1][i][0])))
			{
				result = a[0][i][2] + a[1][i][2] + (w-(a[1][i][1]-a[1][i][0]));
				//printf("%d : %d, %d, %d\n",xv[i],a[0][i][2], a[1][i][2], (w-(a[1][i][1]-a[1][i][0])));
			}
		}

		printf("%d\n",result);
	}

	return 0;
}