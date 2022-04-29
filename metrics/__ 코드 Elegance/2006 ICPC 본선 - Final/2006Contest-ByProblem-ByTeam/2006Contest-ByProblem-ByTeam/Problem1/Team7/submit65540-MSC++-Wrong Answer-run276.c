#include <stdio.h>

int digital(void);
int check_sum(void);
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

int ah, am, as, bh, bm, bs;
int tmp;
int cnt;

int main(void)
{
	int T;
	int i;	

	scanf("%d", &T);

	for (i = 0; i < T; i ++)
	{
		cnt = 0;
		scanf("%d:%d:%d%d:%d:%d", &ah, &am, &as, &bh, &bm, &bs);

		printf("%d\n", digital());
	}

	return 0;
}

int check_sum(void)
{
	tmp = 0;
	tmp += ah / 10;
	tmp += am / 10;
	tmp += as / 10;
	tmp += ah % 10;
	tmp += am % 10;
	tmp += as % 10;

	if ((tmp % 3) == 0)
	{
		cnt ++;
		return 1;
	}
	return 0;
}

int digital(void)
{	
	while (!((ah == bh) && (am == bm) && (as >= bs)))
	{		
		if (check_s(as) == 1)
		{			
			as = 0;
			am++;
			if (check_m(am) == 1)
			{
				am = 0;
				ah++;
				if (check_h(ah) == 1)
					ah = 0;
			}
		}		
		if (check_sum() == 1) {
            if (as < 58)
				as += 3;
			else
				as++;
		}
		else
			as++;
		//printf("%d %d %d %d %d\n", ah, am ,as, tmp, cnt);
	}
	//check_sum();

	return cnt;
}