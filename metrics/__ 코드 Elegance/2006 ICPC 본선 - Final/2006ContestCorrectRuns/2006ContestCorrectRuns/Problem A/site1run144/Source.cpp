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

		int res = 0;
		while(1) {

			int num = h1 * 10000 + m1 * 100 + s1;
			if(num%3==0) ++res;
			if(h1==h2&&m1==m2&&s1==s2) break;
			++s1;
			if(s1>=60) s1 %= 60, ++m1;
			if(m1>=60) m1 %= 60, ++h1;
			if(h1>=24) h1 %= 24;
		}
		printf("%d\n",res);
/*		t1 = h1*3600+m1*60+s1;
		t2 = h2*3600+m2*60+s2;
		int t;
		if ( t1 <= t2 )
		{
			t = (t2 - t1 + 1);
			
		}
		else
		{
			t = ((3600*24 - t1) + t2+1);
		}
		//if(t%3==0) 
			printf("%d\n",t/3);
		//else printf("%d\n",t/3+1);
*/
	}
	return 0;
}
//3598