#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int x[1100], y[1100];

int main()
{
	freopen("i.in", "r", stdin);
	int t, i;
	scanf("%d", &t);
	for (i=0; i<t; i++)
	{
		int n;
		scanf("%d", &n);
		int j, k;
		vector<double> candi;
		candi.resize(0);
		for (j=0; j<n; j++)
		{
			scanf("%d %d", &x[j], &y[j]);
			candi.push_back(x[j]);
		}
		for (j=0; j<n-1; j++)
			for (k=j+2; k<n-1; k++)
			{
				double a = (y[j+1]-y[j])/(double)(x[j+1]-x[j]);
				double b = y[j] - x[j]*a;
				double c = (y[k+1]-y[k])/(double)(x[k+1]-x[k]);
				double d = y[k] - x[k]*c;
				if ( fabs(a-c)>0.000000001 )
				{
					double xx = (d-b)/(a-c);
					if ( xx > x[0] && xx < x[n-1] )
					{
						candi.push_back(xx);
					}
				}
			}
		int sz = candi.size();
		sort(candi.begin(), candi.end());
		int now_target = 0;
		double res = 9999999.9;
		for (j=0; j<sz; j++)
		{
			double max = 0;
			double nz = candi[j];
			while (now_target < n-1 && x[now_target+1]<nz) now_target ++;
			int nt = now_target;
			for (k=0; k<n-1; k++)
			{
				double now = y[k]+((y[k+1]-y[k])/(double)(x[k+1]-x[k]))*(nz-x[k]);
				if ( now > max ) max = now;
			}
			double yy = y[nt]+((y[nt+1]-y[nt])/(double)(x[nt+1]-x[nt]))*(nz-x[nt]);
			max -= yy;
			if ( res>max ) res = max;
		//	printf("%f %f %f\n", nz, yy, max);
		}
		if ( res < 999.999999999 ) printf("%.1f\n", res);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}