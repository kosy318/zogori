#include <iostream>

using namespace std;

int n;
int data[1010][2];

void input()
{
	scanf("%d",&n);
	int q;
	for(q=0;q<n;q++) {
		scanf("%d %d",&data[q][0],&data[q][1]);
	}
}

double gety(double x)
{
	int i;
	for(i=0;i<n-1;i++) {
		if(data[i][0]<=x && x<=data[i+1][0]) break;
	}

	double a,b;

	a=((double)data[i+1][1]-data[i][1])/((double)data[i+1][0]-data[i][0]);
	b=data[i][1]-a*data[i][0];

	return (a*x+b);

	/*
	int i,j,mid;
	i=0;
	j=n-1;
	while(1) {
		mid=(i+j)/2;

		if(data[mid][0]<=x) 
			i=mid+1;
		else 
			j=mid;
	}
	*/
}

void process()
{
	int i,j;
	double result=1001;


	for(i=0;i<n-1;i++) {
		double a,b,x,y,max=-1,dif,mx;
		a=((double)data[i+1][1]-data[i][1])/((double)data[i+1][0]-data[i][0]);
		b=data[i][1]-a*data[i][0];
		if(a!=0) {
			for(j=0;j<n-1;j++) {
				double aa,bb;
				aa=((double)data[j+1][1]-data[j][1])/((double)data[j+1][0]-data[j][0]);
				bb=data[j][1]-a*data[j][0];
				if(j<i && aa>0) {
					x=(b-bb)/(aa-a);
					y=a*x+b;

					if(max<y) {
						max=y;
						mx=x;
					}
				}
				if(i<j && aa<0) {
					x=(b-bb)/(aa-a);
					y=a*x+b;
					
					if(max<y) {
						max=y;
						mx=x;
					}
				}
			}
		}
		else {
		}
		if(max>-1) {
			double aaaa=max-gety(mx);
			if(result>aaaa) result=aaaa;
		}
	}

	if(result==1001) {
		printf("IMPOSSIBLE\n");
	}
	else {
		printf("%.1lf\n",result);
	}
}

int main()
{
	int nn,q;
	scanf("%d",&nn);
	for(q=0;q<nn;q++) {
		input();
		process();
	}
	return 0;
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
17 8
27 23
37 23
47 8
52 18
57 8

*/