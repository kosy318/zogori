/*
#include <stdio.h>

main()
{
	int i, j, tcase, h1, m1, s1, h2, m2, s2, flag, nul, result;

	scanf("%d", &tcase);
	for(i=0;i<tcase;i++)
	{
		flag=0;
		result=0;
		scanf("%d%c%d%c%d %d%c%d%c%d", &h1, &nul, &m1, &nul, &s1, &h2, &nul, &m2, &nul, &s2);
		if(s2<s1)
		{
			m2=m2-1;
			s2=s2+60;
		}
		if(m2<m1)
		{
			h2=h2-1;
			m2=m2+60;
		}
		if(h2<h1)
			h2=h2+24;

		s2=s2-s1;
		m2=m2-m1;
		h2=h2-h1;

		result=s2+m2*60+h2*3600+1;
		if(result%3>=2)
			flag=1;
		result=result/3+flag;

		printf("%d\n", result);
	}
}
*/

#include <stdio.h>

void main(void)
{
	int i, j, tcase, h1, m1, s1, h2, m2, s2, flag, nul, result[10000],h,m,s,result1;

	scanf("%d", &tcase);
	for(i=0;i<tcase;i++)
	{
		flag=0;
		result[i]=0;
		scanf("%d%c%d%c%d %d%c%d%c%d", &h1, &nul, &m1, &nul, &s1, &h2, &nul, &m2, &nul, &s2);

		if(s1 < s2)
			s = s2 - s1;
		else
		{
			s = 60 - s1;
			s = s + s2;
			m2 = m2 - 1;
		}
		if(m1 < m2)
		{
			m = m2 - m1;
			m = m * 60;
		}
		else
		{
			m = 60 - m1;
			m = m + m2;
			m = m * 60;
			h2 = h2 - 1;
		}
		if (h1 < h2)
		{
			h = h2 - h1;
			h = h * 3600;
		}
		else
		{
			if (h1==0)
				h1 = 24;
			h = 24 - h1;
			h = h + h2;
			h = h * 3600;
		}
		result1 = (h+m+s) ;
		if(result1%3>=1)
			flag=1;
		result[i] = (h + m + s) / 3;		
		
		result[i]=result[i]+flag;

	}
	for(i=0;i<tcase;i++)
		printf("%d\n",result[i]);

}
			