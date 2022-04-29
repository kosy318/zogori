#include <stdio.h>
#include <stdlib.h>
int ans=0;

void go(int &h,int &m,int &s)
{
	//printf("%d\n",(h*10000+m*100+s));
	if ((h*10000+m*100+s)%3==0)
	{
		
		ans++;
	}
	s++;
	if (s>=60)
	{
		s-=60;
		m++;
	}
	if (m>=60 )
	{
		m-=60;
		h++;
	}
	if (h>=24)
		h-=24;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		ans=0;
		int h1,h2,m1,m2,s1,s2;
		scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		while(h1 != h2 || m1 !=m2 || s1!=s2)
		{
			go(h1,m1,s1);
		}
		go(h1,m1,s1);
		printf("%d\n",ans);
	}
}