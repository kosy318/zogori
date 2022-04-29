#include<stdio.h>
#include<math.h>
#define SIZE 21

int n,m;
int data[SIZE][2];

int main(void)
{
	//freopen("input.txt","r",stdin);
	
	int tn;
	scanf("%d",&tn);
	
	while(tn--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&data[i][0],&data[i][1]);
		}
		scanf("%d",&m);

		bool flag=false;

		for(int i=0;i<=30000;i++)
		{
			int g=i;
			int sum_x=0;

			if(i==23)
			{
				i=i;
			}

			for(int j=0;j<n;j++)
			{
				double x = (double)((double)(i-data[j][1])/(double)(data[j][0]));

				if(x<0.0)
				{
					sum_x=-1;
					break;
				}

				double t = (int)x;
				t = (t<0.0)? -t:t;

				if(fabs(t-x)<0.0000001)
				{
					sum_x+=(i-data[j][1])/(data[j][0]);
				}
				else{
					sum_x=-1;
					break;
				}
			}
			if(sum_x==m)
			{
				printf("%d\n",g);
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			printf("%d\n",0);
		}
	}

	return 0;
}

/*#include <stdio.h>

struct bun{
	int par;
	int child;
};

int gcd(int a,int b)
{
	if(a<b)
	{
		return gcd(b,a);
	}
	else
	{
		if(b == 0)
			return a;
		return gcd(b,a%b);
	}
}

bun sum(bun a,bun b)
{
	bun res;
	int gc;
	res.par = a.par * b.par;
	res.child = a.child * b.par + b.child * a.par;
	gc = gcd(res.par,res.child);
	res.par /= gc;
	res.child /= gc;

	return res;
}

bun pro(bun a,bun b)
{
	bun res;
	int gc = gcd(a.par,b.par);
	res.par = a.par * b.par;
	res.child = a.child * b.child;
	gc = gcd(res.par,res.child);
	res.par /= gc;
	res.child /= gc;

	return res;
}

int tn,n;

int main()
{
	int i;
	bun at;
	bun bt;
	bun temp;
	bun g;
	bun m;
	int t;

	freopen("input.txt","r",stdin);

	scanf("%d",&tn);

	while(tn--)
	{
		scanf("%d",&n);
		at.child = 0;
		at.par = 1;
		bt.child = 0;
		bt.par = 1;
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&temp.par);
			temp.child = 1;
			at = sum(at,temp);
			scanf("%d",&temp.child);
			bt = sum(bt,temp);			
		}
		m.par = 1;
		scanf("%d",&m.child);
		g = m;
		g = sum(g,bt);
		t=at.par;
		at.par = at.child;
		at.child = t;
		g = pro(g,at);
		if(g.par == 1 && g.child > 0)
		{
			printf("%d\n",g.child);
		}
		else
		{
			printf("%d\n",0);
		}
	}

	return 0;
}

/*
#include<stdio.h>

int n;

int Is_Int(double temp)
{
	double a=(int)temp;
	temp-=a;

	double buffer=(temp<0)? -temp:temp;
	
	if(buffer<=0.00001)
	{
		return true;
	}
	return false;
}
int main(void)
{
//	freopen("input.txt","r",stdin);

	int tn;
	scanf("%d",&tn);

	while(tn--)
	{
		double At=0,Bt=0;
		double g;

		scanf("%d",&n);
		
		double a1,b1;

		for(int i=0;i<n;i++)
		{
			double a,b;
			scanf("%lf %lf",&a,&b);

			if(i==0)
			{
				a1=a; b1=b;
			}
			double temp=1.0 / a;
			At += temp;
			
			temp = b / a;
			Bt+=temp;
		}
		double M;
		scanf("%lf",&M);

		g = (M + Bt)/At;

		if(g<=0){
			printf("0\n");
			continue;
		}
		bool flag=Is_Int(g);
		
		if(!flag)
		{
			printf("0\n");
			continue;
		}
		double x1= (g - b1)/a1;
		flag=Is_Int(x1);

		if(!flag)
		{
			printf("0\n");
			continue;
		}

		printf("%.0lf\n",g);
	}

	return 0;
}
*/
/*
#include <stdio.h>
#include <math.h>
#define N 20

int n, t, m;
int a[N], b[N];
double at, bt, g;



bool isint(double a)
{
	double b = (double)(int)a;

	if(fabs(a-b) < 0.000001)
		return true;
	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		at = bt = 0;
		g = 0;

		int i;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &a[i], &b[i]);
			at += 1 / (double)a[i];
			bt += (double)b[i] / (double)a[i];
		}
		scanf("%d", &m);

		g = (m + bt) / at;

		if (g <= 0 || !isint(g))
			g = 0;
		g = (double)(int)(g+0.5);

		double x;
		for (i = 0; i < n && g; i++) {
			x = (g - b[i]) / a[i];			
			if (!isint(x))
				g = 0;
			x = (double)(int)(x+0.5);
	//		if(x <= 0.0f)
	//			g = 0.0f;
		}

		printf("%d\n", (int)g);
	}

	return 0;
}
*/