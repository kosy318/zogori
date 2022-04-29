#include <stdio.h>

main()
{
	int i, j, tcase, h1, m1, s1, h2, m2, s2, result[10000], flag;

	scanf("%d", &tcase);
	for(i=0;i<tcase;i++)
	{
		flag=0;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
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

		result[i]=s2+m2*60+h2*3600;
		if(result[i]%3>=1)
			flag=1;
		result[i]=result[i]/3+flag;
	}

	for(i=0;i<tcase;i++)
	{
		printf("%d\n", result[i]);
	}
}