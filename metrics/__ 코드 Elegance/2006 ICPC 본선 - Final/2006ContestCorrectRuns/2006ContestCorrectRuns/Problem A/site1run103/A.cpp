#include <stdio.h>

int gn(int h,int m,int s)
{
	return h*3600+m*60+s;
}
int getno(int begin,int end)
{
	int c = 0;
	int k,t,h,m,s;
	while(begin<=end)
	{
		t = begin;
		s = t % 60;
		t /= 60;
		m = t % 60;
		t /= 60;
		h = t;
		k = h*10000 + m*100 + s;
		if( k % 3 == 0)
			c++;
		begin++;
	}
	return c;
}
int main()
{
	int h,m,s,cas,t1,t2,t;
	int count;
	scanf("%d",&cas);
	for(;cas > 0;cas--)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		t1 = gn(h,m,s);
		scanf("%d:%d:%d",&h,&m,&s);
		t2 = gn(h,m,s);

		if(t1<t2)
			count = getno(t1,t2);
		else
		{
			count = getno(t1,24*3600-1);
			count = count + getno(0,t2);
		}
		printf("%d\n",count);
	}
	return 0;
}

