#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int a1, a2, a3;
	int b1, b2, b3;
	int n;
	int i, j, k;
	int count, res,aa,bb,asas;
	char buf1[10], buf2[10];

	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%s %s", buf1, buf2);
		a1 = atoi(&buf1[0]);
		a2 = atoi(&buf1[3]);
		a3 = atoi(&buf1[6]);
		b1 = atoi(&buf2[0]);
		b2 = atoi(&buf2[3]);
		b3 = atoi(&buf2[6]);
		aa=bb=0;

		
		aa = a1*60*60+a2*60+a3;
		bb = b1*60*60+b2*60+b3;

		if((bb-aa)>(aa-bb)) asas=bb-aa;
		else asas= aa-bb;
		printf("%d\n\n\n",(asas+2)/3);

		
	}

	return 0;
}