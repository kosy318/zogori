/*#include<stdio.h>

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
	freopen("input.txt","r",stdin);

	int tn;
	scanf("%d",&tn);

	double At=0,Bt=0;
	double g;

	while(tn--)
	{
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

		double x1 = (g - b1)/a1;

		printf("%.0lf\n",x1);
	}

	return 0;
}
*/

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
			x = (double)(int)(x+0.5);
			if (x <= 0 || !isint(x))
				g = 0;
		}

		printf("%d\n", (int)g);
	}

	return 0;
}
