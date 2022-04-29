#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for (i=0; i<n; i++)
	{
		char a[150], b[150];
		scanf("%s %s", a, b);
		int ha = (a[0]-'0')*10+(a[1]-'0');
		int ma = (a[3]-'0')*10+(a[4]-'0');
		int sa = (a[6]-'0')*10+(a[7]-'0');
		int hb = (b[0]-'0')*10+(b[1]-'0');
		int mb = (b[3]-'0')*10+(b[4]-'0');
		int sb = (b[6]-'0')*10+(b[7]-'0');
		if ( ha>hb || (ha==hb && (ma>mb || ma==mb && (sa>sb))))
			hb += 24;
		int result = 0;
		int j;
		for (j=sa; j<60; j++)
			if ( (ha*10000+ma*100+j)%3==0 ) result ++;
		for (j=0; j<=sb; j++)
			if ( ((hb%24)*10000+mb*100+j)%3==0 ) result ++;
		int diff_m = (hb-ha)*60+(mb-ma);
		result += (diff_m-1)*20;
		printf("%d\n", result);
	}
	return 0;
}