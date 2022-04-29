#include <stdio.h>
#include <string.h>

int p[5000][100]; // p[a][b] = compare y and x(a..a+b)
int tt[101][101];
int q[5001];

int main()
{
	//freopen("h.in", "r", stdin);
	int t;
	scanf("%d", &t);
	int i;
	for (i=0; i<t; i++)
	{
		char y[60], x[6000];
		scanf("%s", y);
		scanf("%s", x);
		int len_y = strlen(y);
		int len_x = strlen(x);
		int j, k, l;
		for (j=0; j<len_x; j++)
		{
			int px = len_x-j;
			if ( px > len_y*2 ) px = len_y*2;
			for (k=0; k<=px; k++) tt[k][0] = k;
			for (k=0; k<=len_y; k++) tt[0][k] = k;
			for (k=1; k<=px; k++)
				for (l=1; l<=len_y; l++)
				{
					tt[k][l] = tt[k-1][l] + 1;
					if ( tt[k][l] > tt[k][l-1] + 1 ) tt[k][l] = tt[k][l-1] + 1;
					int pp = tt[k-1][l-1];
					if ( x[j+k-1]!=y[l-1] ) pp++;
					if ( tt[k][l] > pp ) tt[k][l] = pp;
				}
			for (k=0; k<px; k++)
			{
				p[j][k] = tt[k+1][len_y];
//				printf("%d ", p[j][k]);
			}
//			printf("\n");
		}
		q[0] = 0;
		for (j=0; j<len_x; j++)
		{
			int px = j+1;
			if ( px > len_y*2 ) px = len_y*2;
			int min = 99999;
			for (k=0; k<px; k++)
			{
				int pm = p[j-k][k];
				if ( pm < q[j-k] ) pm = q[j-k];
				if ( pm < min ) min = pm;
			}
			q[j+1] = min;
			//printf("%d ", q[j+1]);
		}
		printf("%d\n", q[len_x]);
	}
	return 0;
}