#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

#define scand(k)		scanf("%d",&k)
#define scanp(k)		scanf("%d%d",&k.x,&k.y)
#define fori(i,k)		for (int i=0; i<k; i++)

#define MAXN 1000

struct POINT { int x, y; };

POINT p[MAXN];
int n, w, h;

bool equal_point(POINT p1, POINT p2)
{
	return (p1.x==p2.x && p1.y==p2.y);
}

bool less_by_row(POINT p1, POINT p2)
{
	if (p1.x!=p2.x) return p1.x<p2.x;
	return p1.y<p2.y;
}

bool less_by_col(POINT p1, POINT p2)
{
	if (p1.y!=p2.y) return p1.y<p2.y;
	return p1.x<p2.x;
}

int cut_by_row()
{
	int row_cand[MAXN*2];
	int nrow_cand=0;

	sort(p, p+n, less_by_row);
	n=unique(p, p+n, equal_point)-p;

	fori(i,n)
	{
		if (p[i].y<h) row_cand[nrow_cand++]=p[i].y;
		if (p[i].y>0) row_cand[nrow_cand++]=p[i].y-1;
	}
	sort(row_cand, row_cand+nrow_cand);
	nrow_cand=unique(row_cand, row_cand+nrow_cand)-row_cand;

	int bounding=0;

	{
		int miny=p[0].y;
		int maxy=p[0].y;
		fori(i,n)
		{
			if (miny>p[i].y-1) miny=p[i].y-1;
			if (maxy<p[i].y+1) maxy=p[i].y+1;
		}
		if (miny<0) miny=0;
		if (maxy>h) maxy=h;
		bounding = maxy-miny;
		bounding += w;
	}

	int min_area=INT_MAX;
	fori(rowi, nrow_cand)
	{
		int lw[MAXN];
		int up[MAXN];
		int lw2[MAXN];
		int up2[MAXN];
		int xx[MAXN];
		int nn=0;

		int row=row_cand[rowi];
		int indoor=0;
		for (int i=0; i<n;)
		{
			int j=i;
			while (j<n && p[j].x==p[i].x) j++;
			int miny=p[i].y;
			int maxy=p[j-1].y;
			if (miny>0) miny--;
			if (maxy<h) maxy++;
			lw[nn]=miny;
			up[nn]=maxy;
			xx[nn]=p[i].x;
			nn++;
			i=j;
		}
		fori(i,nn)
		{
			if (lw[i]>row) lw[i]=row;
			if (up[i]<row+1) up[i]=row+1;			
			lw2[i]=lw[i];
			up2[i]=up[i];
		}
		fori(i,nn-1)
		{
			if (up[i+1]<up[i]) up[i+1]=up[i];
			if (lw[i+1]>lw[i]) lw[i+1]=lw[i];
		}
		for (int i=nn-1; i>0; i--)
		{
			if (up2[i-1]<up2[i]) up2[i-1]=up2[i];
			if (lw2[i-1]>lw2[i]) lw2[i-1]=lw2[i];
		}
		fori(i,n)
		{
			if (up2[i]<up[i]) up[i]=up2[i];
			if (lw2[i]>lw[i]) lw[i]=lw2[i];
		}
		lw[nn]=row;
		up[nn]=row+1;
		xx[nn]=w;
		nn++;
		fori(i,nn)
		{
			int x=xx[i];
			if (x>0 && x<w) indoor += up[i]-lw[i]-1;
			if (i>0)
			{
				indoor+=(min(up[i-1],up[i])-max(lw[i],lw[i-1])-1)*(xx[i]-xx[i-1]-1);
			}
		}

		int area=indoor+bounding-1;
		if (min_area>area) 
		{
			min_area=area;
		}
	}
	return min_area;
}

int cut_by_col()
{
	int col_cand[MAXN*2];
	int ncol_cand=0;

	sort(p, p+n, less_by_col);
	n=unique(p, p+n, equal_point)-p;

	fori(i,n)
	{
		if (p[i].x<w) col_cand[ncol_cand++]=p[i].x;
		if (p[i].x>0) col_cand[ncol_cand++]=p[i].x-1;
	}
	sort(col_cand, col_cand+ncol_cand);
	ncol_cand=unique(col_cand, col_cand+ncol_cand)-col_cand;

	int bounding=0;

	{
		int minx=p[0].x;
		int maxx=p[0].x;
		fori(i,n)
		{
			if (minx>p[i].x-1) minx=p[i].x-1;
			if (maxx<p[i].x+1) maxx=p[i].x+1;
		}
		if (minx<0) minx=0;
		if (maxx>w) maxx=w;
		bounding = maxx-minx;
		bounding += h;
	}

	int min_area=INT_MAX;
	fori(coli, ncol_cand)
	{
		int lw[MAXN];
		int up[MAXN];
		int lw2[MAXN];
		int up2[MAXN];
		int xx[MAXN];
		int nn=0;

		int col=col_cand[coli];
		int indoor=0;
		for (int i=0; i<n;)
		{
			int j=i;
			while (j<n && p[j].y==p[i].y) j++;
			int minx=p[i].x;
			int maxx=p[j-1].x;
			if (minx>0) minx--;
			if (maxx<w) maxx++;
			lw[nn]=minx;
			up[nn]=maxx;
			xx[nn]=p[i].y;
			nn++;
			i=j;
		}
		fori(i,nn)
		{
			if (lw[i]>col) lw[i]=col;
			if (up[i]<col+1) up[i]=col+1;			
			lw2[i]=lw[i];
			up2[i]=up[i];
		}
		fori(i,nn-1)
		{
			if (up[i+1]<up[i]) up[i+1]=up[i];
			if (lw[i+1]>lw[i]) lw[i+1]=lw[i];
		}
		for (int i=nn-1; i>0; i--)
		{
			if (up2[i-1]<up2[i]) up2[i-1]=up2[i];
			if (lw2[i-1]>lw2[i]) lw2[i-1]=lw2[i];
		}
		fori(i,n)
		{
			if (up2[i]<up[i]) up[i]=up2[i];
			if (lw2[i]>lw[i]) lw[i]=lw2[i];
		}
		lw[nn]=col;
		up[nn]=col+1;
		xx[nn]=h;
		nn++;
		fori(i,nn)
		{
			int x=xx[i];
			if (x>0 && x<h) indoor += up[i]-lw[i]-1;
			if (i>0)
			{
				indoor+=(min(up[i-1],up[i])-max(lw[i],lw[i-1])-1)*(xx[i]-xx[i-1]-1);
			}
		}

		int area=indoor+bounding-1;
		if (min_area>area) 
		{
			min_area=area;
		}
	}
	return min_area;
}

int main()
{
	int cases;
	scand(cases);
	while (cases--)
	{
		scand(w);
		scand(h);
		scand(n);
		fori(i,n) scanp(p[i]);
		int sol=min(cut_by_row(), cut_by_col());
		printf("%d\n",sol);
	}
	return 0;
}