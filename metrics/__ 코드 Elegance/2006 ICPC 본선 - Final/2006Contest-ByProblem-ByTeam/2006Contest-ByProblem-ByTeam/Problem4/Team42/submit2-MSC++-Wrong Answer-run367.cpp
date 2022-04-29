#include <stdio.h>

bool Graph[1001][1001];
int ver[3000000][2];
int parent[1001];
int count[1001];

bool union_find(int i, int j);

void main()
{
	int i, j, k, n;
	int vertex, edge;
	int v1, v2;
	int famous1[2];
	int famous2[2];
	int toll;

	scanf("%d", &n);

	while( n-- )
	{
		scanf("%d %d", &vertex, &edge);

		for( i = 1 ; i <= vertex ; i++ )
		{
			parent[i] = -1;
			count[i] = 0;
		}

		for( i = 0 ; i < edge ; i++ )
		{
			scanf("%d %d", &ver[i][0], &ver[i][1]);

			//Graph[v1][v2] = true;
			//Graph[v2][v1] = true;

			count[ver[i][0]]++;
			count[ver[i][1]]++;

			//union_find(v1, v2);
		}

		scanf("%d %d", &famous1[0], &famous1[1]);
		scanf("%d %d", &famous2[0], &famous2[1]);

		scanf("%d", &toll);

		for( i = 0 ; i < toll ; i++ )
		{
			scanf("%d %d", &v1, &v2);

			count[v1]--;
			count[v2]--;

			Graph[v1][v2] = -1;
			Graph[v2][v1] = -1;
		}

		for( i = 0 ; i < edge ; i++ )
		{
			if( Graph[ver[i][0]][ver[i][1]] == -1 )
				Graph[ver[i][0]][ver[i][1]] = 0;
			else
			{
				Graph[ver[i][0]][ver[i][1]] = 1;

				union_find(ver[i][0], ver[i][1]);
			}		
		}

		if( count[famous1[0]] < 2 || count[famous1[1]] < 2 || count[famous2[0]] < 2 || count[famous2[1]] < 2 )
		{
			printf("NO\n");
		}
		else if( famous1[0] == famous2[0] || famous1[0] == famous2[1] || famous1[1] == famous2[0] || famous1[1] == famous2[1] )
			printf("NO\n");
		else if( !union_find(famous1[0], famous2[0]) || !union_find(famous1[0], famous2[1]) )
			printf("NO\n");
		else
			printf("YES\n");
	}
}

bool union_find(int i, int j)
{
	while( parent[i] >= 0 )
		i = parent[i];
	while( parent[j] >= 0 )
		j = parent[j];

	if( i != j )
	{
		parent[j] = i;
		return false;
	}

	return true;

}