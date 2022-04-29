#include <stdio.h>
#include <stdlib.h>
#include <cstring>

char ary[50][1001];
char result[1001];
int idx = 0;
int dist = 0;


int main()
{
	int cases, n , m , a , c ,g , t, i , j, k,l ;

	scanf("%d", &cases);

	for(l = 0 ; l < cases; l++)
	{
		scanf("%d %d", &m, &n);

		for(i = 0 ; i < m ; i++)
			scanf("%s", ary[i]);
		
		memset(result, 0, sizeof(result));
		
		idx = dist = 0;
		for( j = 0 ; j < n ; j++)
		{
			t = g = c = a = 0;
			for( k = 0 ; k < m ; k++)
			{
				switch(ary[k][j])
				{
				case 'A' : a++; break;
				case 'C' : c++; break;
				case 'G' : g++; break;
				case 'T' : t++; break;
				}
			}

				if(a >= c && a >= g && a >=t)
				{
					result[idx++] = 'A';
					dist += c;
					dist += g;
					dist += t;
				}
				else if(c >= a && c >= g && c >=t)
				{
					result[idx++] = 'C';
					dist += a;
					dist += g;
					dist += t;
				}
				else if(g >= a && g >= c && g >=t)
				{
					result[idx++] = 'G';
					dist += a;
					dist += c;
					dist += t;
				}
				else if(t >= a && t >= c && t >=g)
				{
					result[idx++] = 'T';
					dist += a;
					dist += c;
					dist += g;
				}
			
		}

		printf("%s\n", result);
		printf("%d\n", dist);
	}

	return 0;
}