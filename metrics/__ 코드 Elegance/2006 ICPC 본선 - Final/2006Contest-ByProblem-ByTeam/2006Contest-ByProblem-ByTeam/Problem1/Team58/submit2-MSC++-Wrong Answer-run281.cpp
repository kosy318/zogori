#include <stdio.h>

int start, mod;
int end;
char buf[6][10];

int calc(int a, int b ,int c)
{
	return a * 60 * 20 + b* 20 + c/3;
}

void init()
{
	int a[6], i, sum,j;
	int b[6][2];
	char c;
	scanf("%c%c:%c%c:%c%c %c%c:%c%c:%c%c",&buf[0][0],&buf[0][1],&buf[1][0],&buf[1][1],&buf[2][0],&buf[2][1],&buf[3][0],&buf[3][1],&buf[4][0],&buf[4][1],&buf[5][0],&buf[5][1]);
	scanf("%c",&c);
	for ( i = 0; i < 6; i++ )
	{
		sscanf(buf[i],"%d",&a[i]);
	}

	
	for ( i = 0; i < 6; i++ )
	{
		b[i][0] = a[i] / 10;
		b[i][1] = a[i] % 10;
	}

	start = 0;

	while (1)
	{
		sum = 0;
		for (i=0;i<3;i++)
		{
			for (j=0;j<2;j++)
				sum += b[i][j];
		}
		if (sum %3 == 0) 
			start++;
        
		b[2][1]++;
		if (b[2][1] == 10)
		{ b[2][1] = 0;b[2][0]++;
		}
		if (b[2][0] == 6)
		{b[2][0] = 0;b[1][1]++;
		}
		if (b[1][1] == 10)
		{b[1][1]=0;b[1][0]++;
		}
		if(b[1][0] == 6)
		{b[1][0] = 0;b[0][1]++;
		}
		if(b[0][1] == 10)
		{b[0][1] = 0;b[0][0]++;
		}
		if(b[0][0]==2 && b[0][1]==4)
		{
			if ( b[0][0] == b[3][0] && b[0][1] == b[3][1]
			&& b[1][0] == b[4][0] && b[1][1] == b[4][1] 
			&& b[2][0] == b[5][0] && b[2][1] == b[5][1] )
			{
				break;
			}
			b[0][0]=0;
			b[0][1]=0;
		}
		
			if ( b[0][0] == b[3][0] && b[0][1] == b[3][1]
			&& b[1][0] == b[4][0] && b[1][1] == b[4][1] 
			&& b[2][0] == b[5][0] && b[2][1] == b[5][1] )
			{
				break;
			}
	}

	printf("%d\n",start);

}

int main()
{
	int T;
	int i;
	char c;
	scanf("%d",&T);
	scanf("%c",&c);
	for(i=0;i<T;i++)
	{
		init();
	}
	return 0;
}