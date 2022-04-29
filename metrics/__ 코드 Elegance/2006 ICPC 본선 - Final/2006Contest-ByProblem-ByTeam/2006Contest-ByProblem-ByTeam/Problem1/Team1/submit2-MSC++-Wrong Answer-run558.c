#include <stdio.h>

#define  X    1000

char input[100];
char input2[100];
int output[X];

void main()
{
	int n;
	int start;
	int end;
	int i,j;
	int cnt = 0;
	int a, b,c, d,e, f;
	int h, m, s;
	int temp;
	
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		//scanf("%d %c %d %c %d %d %c %d %c %d", &a[i], t, &b[i],t, &c[i], &d[i], t,&e[i], t,&f[i]);
		scanf("%s %s", input, input2);
		
		start = (input[0]-'0')*100000 + (input[1]-'0')*10000+ (input[3]-'0')*1000+(input[4]-'0')*100+(input[6]-'0')*10+(input[7]-'0');
		end = (input2[0]-'0')*100000 + (input2[1]-'0')*10000+ (input2[3]-'0')*1000+(input2[4]-'0')*100+(input2[6]-'0')*10+(input2[7]-'0');
		a = (input[0]-'0')*10 + (input[1]-'0');
		b = (input[3]-'0')*10 + (input[4]-'0');
		c = (input[6]-'0')*10 + (input[7]-'0');
		
		d = (input2[0]-'0')*10 + (input2[1]-'0');
		e = (input2[3]-'0')*10 + (input2[4]-'0');
		f = (input2[6]-'0')*10 + (input2[7]-'0');
		temp = start;

		if(f >= c)
			s = f - c;
		else
		{
			f = f + 60;
			e = e - 1;
			s = f - c;
		}

	    if(e >= b)
			m = e - b;
		else
		{
			e = e + 60;
			d = d - 1;
			m = e - b;
		}
		if(d >= a)
			h = d - a;
		else
		{
			d = d + 24;
			h = d - a;
		}

		output[i] = h*1200+m*20;

		if(f>=c)
		{
			for(j=c; j<f; j++)
				if(j%3 == 0)
					output[i] = output[i] +1;
		}
		else
		{
			for(j=f; j<=c; j++)
			{
				if(j%3 == 0)
					temp = temp + 1;
			}
			temp = 20 - temp;
			output[i] = output[i] + temp;
		}
	}

	for(i=0; i<n; i++)
		printf("%d\n",  output[i]);
}