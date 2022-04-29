#include <stdio.h>

int main()
{
	int test;

	char clock1[7];
	char clock2[7];
	
	int num1, num2;

	scanf("%d", &test);

	while(test--)
	{
		scanf("%s %s", clock1, clock2);
		printf("%d\n", a(clock1, clock2));	
	}

}

int a(char *clock1, char *clock2)
{
	int result;
	int h1, m1, s1;
	int h2, m2, s2;
	int limit, num;

	h1 = clock1[1] - '0';
	h1 += (clock1[0] - '0') * 10 ;

	m1 = clock1[4] - '0';
	m1 += (clock1[3] - '0') * 10; 

	s1 = clock1[7] - '0';
	s1 += (clock1[6] - '0') * 10 ;

	h2 = clock2[1] - '0';
	h2 += (clock2[0] - '0') * 10 ;

	m2 = clock2[4] - '0';
	m2 += (clock2[3] - '0') * 10; 

	s2 = clock2[7] - '0';
	s2 += (clock2[6] - '0') * 10;

	limit = h2 * 10000 + m2 * 100 + s2;

	result = 0;
	while(1)
	{
		num = h1 * 10000 + m1 * 100 + s1;

		if(num % 3 == 0)
				result++;
		
		if(num == limit)
			break;

		s1++;
		if(s1 == 60)
		{
			s1 = 0;
			m1++;
		}
		if(m1 == 60)
		{
			m1 = 0;
			h1++;
		}
		if(h1 == 24)
			h1 = 0;
	}
	return result;
}
