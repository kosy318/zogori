#include <stdio.h>
#include <stdlib.h>


void main()
{
	int count[4], T, m, n, i, j, k, err, sum, max, max_index;
	char buf[51][1005], string[1005];

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &m, &n);
		gets(buf[0]);
		for(i = 0; i < m; i++)
			gets(buf[i]);

		err = 0;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < 4; j++)
				count[j] = 0;

			for(j = 0; j < m; j++)
			{
				switch(buf[j][i])
				{
				case 'A':
					count[0]++;
					break;
				case 'C':
					count[1]++;
					break;
				case 'G':
					count[2]++;
					break;
				case 'T':
					count[3]++;
					break;
				}
			}
			
			max = max_index = 0;
			for(k = 0; k < 4; k++)
				if(count[k] > max)
				{
					max = count[k];
					max_index = k;
				}

			switch(max_index)
			{
			case 0:
				string[i] = 'A';
				break;
			case 1:
				string[i] = 'C';
				break;
			case 2:
				string[i] = 'G';
				break;
			case 3:
				string[i] = 'T';
				break;
			}

			err += (m - max);
		}
		string[n] = '\0';

		printf("%s\n", string);
		printf("%d\n", err);
	}
}

