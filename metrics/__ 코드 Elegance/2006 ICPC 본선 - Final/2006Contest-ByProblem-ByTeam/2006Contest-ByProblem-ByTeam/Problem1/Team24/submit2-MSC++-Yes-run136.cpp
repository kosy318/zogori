#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int getNumber (int &a,int &b,int &c)
{
	if ( c == 60 )
	{
		b++;
		c=0;
	}
	if (b == 60)
	{
		a++;
		b=0;
	}
	if (a== 24)
	{
		a=0;
	}
	return (a*10000)+(b*100)+c;
}
int main()
{
	char str1[20], str2[20];
	int n;

	scanf ("%d", &n);
	for (int i=0;i<n;++i)
	{
		scanf ("%s %s",str1,str2);
		char tmp[4];
		int a1,a2,a3,b1,b2,b3;
		tmp[0]=str1[0];
		tmp[1]=str1[1];
		tmp[2]='\0';
		a1 = atoi (tmp);
	

		tmp[0]=str1[3];
		tmp[1]=str1[4];
		tmp[2]='\0';
		a2 = atoi (tmp);

		tmp[0]=str1[6];
		tmp[1]=str1[7];
		tmp[2]='\0';
		a3 = atoi (tmp);

		tmp[0]=str2[0];
		tmp[1]=str2[1];
		tmp[2]='\0';
		b1 = atoi (tmp);

		tmp[0]=str2[3];
		tmp[1]=str2[4];
		tmp[2]='\0';
		b2 = atoi (tmp);

		tmp[0]=str2[6];
		tmp[1]=str2[7];
		tmp[2]='\0';
		b3 = atoi (tmp);
//		printf ("%d %d\n",getNumber(a1,a2,a3),getNumber(b1,b2,b3));
		int s = getNumber (a1,a2,a3);
		int t = getNumber (b1,b2,b3);
		int temp = s;
		int result = 0;
		while (temp != t)
		{
			if (temp%3==0)
				++result;
			++a3;
			temp = getNumber (a1,a2,a3);
		}
		if (temp%3==0)
				++result;
		printf ("%d\n",result);
	}
	return 0;
}