#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int h1,m1,s1;
	int h2,m2,s2;
	int t1,t2;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d:%d:%d",&h1,&m1,&s1);
		scanf("%d:%d:%d",&h2,&m2,&s2);
		t1 = h1*3600+m1*60+s1;
		t2 = h2*3600+m2*60+s2;
		int t;
		if ( t1 < t2 )
		{
			t = (t2 - t1 + 1);
			
		}
		else
		{
			t = ((3600*24 - t1) + t2);

		}
		if ( t % 3 == 0 ) printf("%d\n",t/3);
		else printf("%d\n",t/3+1);
	}
	return 0;
}
//3598