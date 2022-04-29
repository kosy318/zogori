#include<iostream>
#include<stdio.h>
using namespace std;

void main()
{
	int T, n;
	int i,j,a,b,c;
	unsigned long long LCM;
	long tmp1, tmp2;
	unsigned long long in[20][2];
	double res;
	int digit[11], M;


	scanf("%d", &T);
	for(i=0;i<T;++i)
	{
		scanf("%d", &n);
		for(j=1;j<=10;++j) digit[j] = 0;
		for(j=0;j<n;++j)
		{
			cin >> tmp1 >> tmp2;
			in[j][0] = tmp1;
			in[j][1] = tmp2;
			++digit[in[j][0]];
		}
		scanf("%d", &M);
		if(M < n)
		{
			cout << "0\n";
			continue;
		}
		LCM = 1;
		for(j=2;j<=10;++j)
		{
			if(digit[j] != 0)
				LCM *= j;
		}
		a = b = c = 0;
		//cout << in[j][0] << " "<< in[j][1] << endl;
		for(j=0;j<n;++j)
		{
			c = LCM/in[j][0];
			a += in[j][1] * c;
			b += c;
//			cout << a << " " << b << " " << c << endl;
		}
	
		res = (M*LCM + a)/(double)b;

		if( res-int(res) > 0) printf("0\n");
		else printf("%d\n", (int)res);
		//cout << res << "-" << int(res) << endl;
	}
}
