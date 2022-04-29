#include <stdio.h>

main()
{
	int i, j, tcase, h1, m1, s1, h2, m2, s2, result, sum;

	scanf("%d", &tcase);
	for(i=0;i<tcase;i++)
	{
		result=0;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		while(!(h1==h2 && m1==m2 && s1==s2))
		{
			sum=0;
			sum=sum+h1/10;
			sum=sum+h1%10;
			sum=sum+m1/10;
			sum=sum+m1%10;
			sum=sum+s1/10;
			sum=sum+s1%10;
			if(!(sum%3))
				result++;

			s1++;
			if(s1>=60)
			{
				s1=0;
				m1++;
				if(m1>=60)
				{
					m1=0;
					h1++;
					if(h1>=24)
						h1=0;
				}
			}
		}
		printf("%d\n", result);
	}
}