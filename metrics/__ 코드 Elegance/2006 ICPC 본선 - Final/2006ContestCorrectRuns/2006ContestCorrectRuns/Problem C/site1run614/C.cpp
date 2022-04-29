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

unsigned cut_by_row()
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

	unsigned bounding=0;

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
		bounding = (unsigned)(maxy-miny);
		bounding += (unsigned)w;
	}

	unsigned min_area=UINT_MAX;
	fori(rowi, nrow_cand)
	{
		int lw[MAXN];
		int up[MAXN];
		int lw2[MAXN];
		int up2[MAXN];
		int xx[MAXN];
		int nn=0;

		int row=row_cand[rowi];
		unsigned indoor=0;
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
		fori(i,nn)
		{
			if (up2[i]<up[i]) up[i]=up2[i];
			if (lw2[i]>lw[i]) lw[i]=lw2[i];
		}
		fori(i,nn)
		{
			int x=xx[i];
			if (x>0 && x<w) indoor += (unsigned)(up[i]-lw[i]-1);
			if (i>0)
			{
				indoor+=(unsigned)(min(up[i-1],up[i])-max(lw[i],lw[i-1])-1)*(unsigned)(xx[i]-xx[i-1]-1);
			}
		}

		unsigned area=indoor+bounding-1;
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
		unsigned sol=cut_by_row();
		swap(w,h);
		fori(i,n) swap(p[i].x, p[i].y);
		unsigned sol2=cut_by_row();
		printf("%u\n",min(sol,sol2));
	}
	return 0;
}