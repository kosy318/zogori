#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<complex>

using namespace std;

#define clr(x) memset(x,0,sizeof(x))
#define clr2(x) memset(x,-1,sizeof(x))
#define For(i,s,t) for(int i=(s); i<(t); i++)
#define fori(n) For(i,0,n)
#define forj(n) For(j,0,n)
#define fork(n) For(k,0,n)

typedef complex<double> Pt;
#define X real()
#define Y imag()

typedef double D;

const double eps=1e-8, inf=1e30;

double interp(Pt a,Pt b,double x) {
	if(fabs(b.X-a.X)<eps) return a.Y;
	double y=a.Y+(b.Y-a.Y)/(b.X-a.X)*(x-a.X);
	return y;
}

int better(D &x,D &y,D &k, D x2, D y2, D k2) {
	#define DO { x=x2, y=y2, k=k2; return 1; }
	if(x2<x-eps) DO;
	if(x2>x+eps) return 0;

	if(y2>y+eps) DO;
	if(y2<y-eps) return 0;

	if(k2>k+eps) DO;
	return  0;
}

double getk(Pt a,Pt b) {
	double dy=b.Y-a.Y, dx=b.X-a.X;
	if(fabs(dy)<=eps*2) return 0;
	if(fabs(dx)<=eps*2) return inf;
	return dy/dx;
}

void line_arg(Pt a, Pt b, D &aa, D &bb, D &cc) {
	aa=a.Y-b.Y, bb=-(a.X-b.X), cc=a.X*b.Y-a.Y*b.X;
}

int line_inter(Pt A1, Pt B1, Pt A2, Pt B2, double &x, double &y) {
	double a1,b1,c1,a2,b2,c2;
	line_arg(A1,B1,a1,b1,c1);
	line_arg(A2,B2,a2,b2,c2);
	double d=a1*b2-a2*b1;
	if(fabs(d)<eps) return fabs(a1*c2-a2*c1)<eps? 2: 0;
	x= (b1*c2-c1*b2)/d;
	y=-(a1*c2-a2*c1)/d;
	return 1;
}

const int maxN=2000;

Pt I[maxN], P[maxN];
int n,ni;

void calc() {
	int g=-1;
	int mark[maxN];
	clr(mark);

	double x0=P[0].X, y0=0, k0=-inf;
	fori(n-1) {
		double y=interp(P[i],P[i+1],x0);
		if( better(x0,y0,k0, x0,y,getk(P[i],P[i+1])) ) g=i;
	}
	if(g<0) {
		//?
	}
	mark[g]=1;
	I[0]=Pt(x0,y0);
	ni=1;
	
	y0=-inf, k0=-inf;//?
	while(1) {//?		
		k0=-inf;
		int g2=-1;
		double minx=x0;
		x0=inf, y0=0, k0=-inf;//?
		fori(n-1) if(!mark[i]) {
			double x,y;
			if(line_inter(P[g],P[g+1], P[i], P[i+1], x, y)!=1) continue;
			if(x<minx+eps) continue;
			if(better(x0,y0,k0, x,y,getk(P[i],P[i+1]))) g2=i;
		}
		if(g2<0) break;
		I[ni++]=Pt(x0,y0);
		mark[g2]=1;
		g=g2;
	}

	if(P[n-1].X>I[ni-1].X-eps) 
		I[ni++]=Pt(P[n-1].X, interp(P[g],P[g+1],P[n-1].X));
/*
	printf("==== I %d\n",ni);
	fori(ni) {
		printf("( %.1lf, %.1lf )\n",I[i].X, I[i].Y);
	}
*/
}

void solve() {
	double h=inf;
	int j;
	fori(n) {
		j=1; while(j<ni && I[j].X< P[i].X+eps ) j++;
		if(j>=ni) continue;
		double y=interp(I[j-1],I[j],P[i].X);
		//printf("--- ( %.1lf %.1lf )\n", P[i].X, y);
		/*
		if(fabs(y-P[i].Y)<eps)
			printf(" **** %.1lf %.1lf (%.1lf %.1lf) (%.1lf %.1lf) \n",y,P[i].X, I[j].X, I[j].Y, I[j+1].X, I[j+1].Y);
		*/
		//if(y>inf/2) y=min(I[j].Y, I[j+1].Y);		
		//printf("===%.1lf %.1lf %.1lf %.1lf\n",P[i].X, y-P[i].Y, y,P[i].Y);
		h<?= y-P[i].Y;
	}
	For(i,1,ni-1) { //?
		j=1; while(j<n && P[j].X< I[i].X+eps ) j++;
		if(j>=n) continue;
		double y=interp(P[j-1],P[j],I[i].X);
		h<?= I[i].Y-y;
	}
	
	//h<?=I[0].Y-P[0].Y;
	//h<?=I[ni-1].Y-P[n-1].Y;

	if(h>1000) printf("IMPOSSIBLE\n");
	else printf("%.1lf\n",h);
}

int main() {
	int ca;
	for(scanf("%d",&ca);ca;ca--) {
		scanf("%d",&n);
		fori(n) {
			double x,y; scanf("%lf %lf",&x,&y);
			P[i]=Pt(x,y);
		}
		calc();
		solve();
	}
}


