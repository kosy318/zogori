#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

int a1, a2, a3;
int convert();
string input;	
int main()
{

	int b1, b2, b3;
	int n;
	int i, j, k;
	int count=0, res,start,end;
	char buf1[10], buf2[10];

	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%s %s", buf1, buf2);
		a1 = atoi(&buf1[0]);
		a2 = atoi(&buf1[3]);
		a3 = atoi(&buf1[6]);
		b1 = atoi(&buf2[0]);
		b2 = atoi(&buf2[3]);
		b3 = atoi(&buf2[6]);
		start = a3+a2*100+a1*10000;
		end = b3+b2*100+b1*10000;

		while(start!=end)
		{
			
			if(start%3==0) count++;
			start = convert();

			
		}
		if(start%3==0) count++;

		printf("%d\n",count);
		count = 0;
	}
}

int convert()
{
	a3++;
	if(a3>59) {a2++;a3=0;}
	if(a2>59) {a1++;a2=0;}
	if(a1>23) {a1=0;}
	
	return a3+a2*100+a1*10000;
}

