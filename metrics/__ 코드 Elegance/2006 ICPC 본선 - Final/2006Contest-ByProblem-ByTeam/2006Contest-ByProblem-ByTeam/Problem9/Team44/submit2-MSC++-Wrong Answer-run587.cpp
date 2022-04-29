#include<cstdio>
#include<cmath>

#define err 0.00000001

struct pnt {
	double x,y;
};

struct line {
	double a,b,c;
};

double dis(pnt a,pnt b)
{
	return sqrt( pow(a.x-b.x,2.0) + pow(a.y-b.y,2.0) );
}

double segdis(pnt sa,pnt sb,pnt pa)
{
	double a,b,c,t;

	a=dis(sa,pa);
	b=dis(sb,pa);
	c=dis(sa,sb);
	if (a<b)
		t=a,a=b,b=t;
	if (a*a>b*b+c*c || c<err)
		return b;
	t=(a+b+c)/2.0;
	t=sqrt(t*(t-a)*(t-b)*(t-c));
	return 2.0*t/c;
}

int intersec(line t1,line t2,pnt &s)
{
	if (fabs(t1.a*t2.b-t2.a*t1.b)<err)
		return 1;
	s.x=(t1.b*t2.c-t2.b*t1.c)/(t1.a*t2.b-t2.a*t1.b);
	s.y=(t1.c*t2.a-t2.c*t1.a)/(t1.a*t2.b-t2.a*t1.b);
	return 0;
}

int pnt2line(pnt p1,pnt p2,line &t)
{
	if (fabs(p1.x-p2.x)<err && fabs(p1.y-p2.y)<err)
		return 1;
	if (fabs(p1.x-p2.x)<err) {
		t.a=1;
		t.b=0;
		t.c=-p1.x;
	}
	else {
		t.b=1;
		t.a=-(p1.y-p2.y)/(p1.x-p2.x);
		t.c=-(t.a*p1.x)-(t.b*p1.y);
	}
	return 0;
}

double an(int,double,double);
double angle(double,double);

pnt dt[1001];
int n;
double h[1001];
double pi=acos(-1.0);

int main()
{
	int t,i,j;

	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%lf%lf",&dt[i].x,&dt[i].y);
		double dp=9999;
		for (i=0;i<n;i++) {
			double l=dt[i].y;
			double r=l+1000;
			double m,kb=999999.0;
			while (r-l>=0.0001) {
				int ch=0;
				m=(l+r)/2.0;
				double ang=an(0,dt[i].x,m);
				if (fabs(ang-pi)<err)
					ang=-pi;
				if (ang>pi/2)
					ang=-pi-(pi-ang);
				double ka;
				for (j=1;j<n;j++) {
					ka=an(j,dt[i].x,m);
					if (fabs(ka-pi)<err)
						ka=-pi;
					if (ka>pi/2)
						ka=-pi-(pi-ka);
					if (ka<ang) {
						ch=1;
						break;
					}
					else
						ang=ka;
				}
				if (ch==0) {
					kb=m;
					r=m;
				}
				else
					l=m;
			}
			h[i]=kb;
			if (h[i]-dt[i].y<dp)
				dp=h[i]-dt[i].y;
		}
		pnt z,e;
		z.x=dt[0].x;
		z.y=dt[0].y;
		e.x=dt[n-1].x;
		e.y=dt[n-1].y;
		for (i=0;i<n-1;i++) {
			j=i+1;
			line a,b;
			pnt pa,pb,c;

			pa.x=dt[i].x;
			pa.y=h[i];
			pb.x=dt[j].x;
			pb.y=h[j];
			pnt2line(pb,z,a);
			pnt2line(e,pa,b);
			intersec(a,b,c);
			pnt d;
			d.x=c.x;
			d.y=-9999;
			pnt2line(c,d,b);
			pa.x=dt[i].x;
			pa.y=dt[i].y;
			pb.x=dt[j].x;
			pb.y=dt[j].y;
			pnt2line(pa,pb,a);
			intersec(a,b,d);
			if (c.y-d.y<dp) {
				dp=c.y-d.y;
			}
		}
		if (dp>1000)
			printf("IMPOSSIBLE\n");
		else
			printf("%.1lf\n",dp);
	}
	return 0;
}

double angle(double x,double y)
{
	return atan2(y,x);
}

double an(int i,double x,double y)
{
	x=dt[i].x-x;
	y=dt[i].y-y;
	return angle(x,y);
}

/*
3
12
1 8
3 11
5 1
7 4
9 3
10 1
12 7
14 4
16 3
19 2
20 13
22 12
11
11 9
16 215
21 9
26 215
31 9
36 1
41 9
46 215
51 9
56 215
61 9
8
7 8
12 18
17 18
27 23
37 23
47 8
52 18
57 8

1
8
7 8
12 18
17 8
27 23
37 23
47 8
52 18
57 8
*/