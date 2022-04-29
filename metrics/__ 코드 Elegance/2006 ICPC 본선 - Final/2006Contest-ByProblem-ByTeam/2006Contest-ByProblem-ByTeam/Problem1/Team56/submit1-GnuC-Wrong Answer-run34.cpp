#include <stdio.h>

int gn(int h,int m,int s)
{
	return h*3600+m*60+s;
}

int main()
{
	int h,m,s,cas,t1,t2,t;
	scanf("%d",&cas);
//	if(cas == 0) while(1);
	for(;cas > 0;cas--)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		t1 = gn(h,m,s);
		scanf("%d:%d:%d",&h,&m,&s);
		t2 = gn(h,m,s);
		t = t2 - t1;
		if(t <= 0)
			t += 24*3600;
		printf("%d\n",(t+2)/3);
	}
	return 0;
}

