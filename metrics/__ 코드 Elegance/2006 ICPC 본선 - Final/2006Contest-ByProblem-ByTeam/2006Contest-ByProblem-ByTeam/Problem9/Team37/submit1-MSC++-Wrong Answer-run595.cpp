#include <iostream>

using namespace std;

int n;
double data[1010][2];

void input()
{
	scanf("%d",&n);
	int q;
	for(q=0;q<n;q++) {
		scanf("%lf %lf",&data[q][0],&data[q][1]);
		if(q-1>=0 && data[q-1][1]==data[q][1]) {
			data[q+1][0]=data[q][0];
			data[q+1][1]=data[q][1];
			data[q][0]=(data[q-1][0]+data[q][0])/2;
			n++; q++;
		}
	}
}

void process()
{
	int i,j;
	double result=1001;
	for(i=0;i<n;i++) {
		double max=0;
		for(j=0;j<n-1;j++) {
			double a,b;
			double y;
			a=((double)data[j][1]-data[j+1][1])/((double)data[j][0]-data[j+1][0]);
			b=data[j][1]-a*data[j][0];
			
			y=a*data[i][0]+b;
			if(max<y) max=y;
		}
		if((double)data[i][1]<=max) {
			if(max-data[i][1]<result) result=max-data[i][1];
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