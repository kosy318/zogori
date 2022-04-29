#include<iostream>
#include<stdio.h>
using namespace std;

void main()
{
	int T, n;
	long long int i,j,a,b,c;
	long long int LCM;// = 7*9*10;
	long long int tmp1, tmp2;
	long long int in[20][2];
	double res, tmp3;
	int digit[11], M;
	bool flag;


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
	
		res = double(M*LCM + a)/(double)b;

//		cout << M << " " << LCM << ' ' << a << ' ' << b << endl;

//		cout << res << endl;
		flag = false;
		for(j=0;j<n;++j)
		{
			tmp3 = (res - in[j][1]) / double(in[j][0]);
			if( tmp3 - int(tmp3) > 0) flag = true;
		}

		if( flag ) printf("0\n");
		else cout << res << endl;//printf("%d\n", (int)res);
/*
		if( res - int(res) > 0 ) printf("0\n");
		else printf("%d\n", (int)res);
*/
		//cout << res << "-" << int(res) << endl;
	}
}
