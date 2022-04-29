#include <stdio.h>

int digital(void);

int ah, am, as, bh, bm, bs;

int main(void)
{
	int T;
	int i;	

	scanf("%d", &T);

	for (i = 0; i < T; i ++)
	{
		scanf("%d:%d:%d%d:%d:%d", &ah, &am, &as, &bh, &bm, &bs);

		printf("%d\n", digital());
	}

	return 0;
}

int digital(void)
{
	int i;
	int cnt = 0;
	int tmp;

	while (!((ah == bh) && (am == bm) && (as == bs)))
	{
		tmp = 0;

		if (check_s(as) == 1)
		{
			as = 0;
			am++;
		}
		if (check_m(am) == 1)
		{
			am = 0;
			ah++;
		}
		if (check_h(ah) == 1)
			ah = 0;
                
		tmp += ah / 10;
		tmp += am / 10;
		tmp += as / 10;
		tmp += ah % 10;
		tmp += am % 10;
		tmp += as % 10;		

		if ((tmp % 3) == 0)
			cnt ++;
		//printf("%d %d %d %d %d\n", ah, am ,as, tmp, cnt);
		as++;
	}
	tmp = 0;
	tmp += ah / 10;
	tmp += am / 10;
	tmp += as / 10;
	tmp += ah % 10;
	tmp += am % 10;
	tmp += as % 10;		

	if ((tmp % 3) == 0)
		cnt ++;
	return cnt;
}

int check_h (int x)
{
	return x > 23 ? 1 : 0;
}
int check_m (int x)
{
	return x > 59 ? 1 : 0;
}
int check_s (int x)
{
	return x > 59 ? 1 : 0;
}