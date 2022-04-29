#include <stdio.h>

const int MAX_N = 1000;

int main()
{
	int case_num, now_case;
	int n;
	int eq[MAX_N][2];
	int m;
	int i, j;
	int min, p;
	//int k;
	//double matrix[MAX_N][MAX_N + 1];
	int x[MAX_N], f[MAX_N];
	bool check;

	scanf("%d", &case_num);

	for(now_case = 0 ; now_case < case_num ; now_case++)
	{
		scanf("%d", &n);
		
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d %d", &eq[i][0], &eq[i][1]);
			x[i] = 0;
			f[i] = eq[i][1];
		}

		scanf("%d", &m);

		if(n == 0)
		{
			printf("0\n");
			continue;
		}

		for(i = 0 ; i < m ; i++)
		{
			min = f[0];
			p = 0;

			for(j = 1 ; j < n ; j++)
				if(f[j] < min)
				{
					min = f[j];
					p = j;
				}

			x[p]++;
			f[p] += eq[p][0];
		}

		check = true;
		for(i = 0 ; i < n - 1 ; i++)
			if(f[i] != f[i + 1])
				check = false;
		
		if(check)
			printf("%d\n", f[0]);
		else
			printf("0\n");

/*		for(i = 0 ; i < n ; i++)
			for(j = 0 ; j <= n ; j++)
				matrix[i][j] = 0;

		for(i = 0 ; i < n - 1 ; i++)
		{
			matrix[i][i] = (double)eq[i][0];
			matrix[i][i + 1] = (double)(-eq[i + 1][0]);
			matrix[i][n] = (double)eq[i + 1][1] - eq[i][1];
		}
		for(i = 0 ; i < n ; i++)
			matrix[n - 1][i] = 1.0;
		matrix[n - 1][n] = (double)m;

		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j <= n ; j++)
				if(j != i)
					matrix[i][j] /= matrix[i][i];

			matrix[i][i] = 1;

			for(j = 0 ; j < n ; j++)
				if(j != i)
				{
					for(k = 0 ; k <= n ; k++)
						matrix[j][k] -= matrix[i][k] * matrix[j][i];
				}
		}

		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j <= n ; j++)
				printf("%lf ", matrix[i][j]);
			printf("\n");
		}

		for(i = 0 ; i < n ; i++)
			result[i] = (int)(matrix[i][n] / matrix[i][i]);

		check = true;
		for(i = 0 ; i < n - 1 ; i++)
			if(eq[i][0] * result[i] + eq[i][1] != eq[i + 1][0] * result[i + 1] + eq[i + 1][1])
				check = false;
		for(i = 0 ; i < n ; i++)
			m -= result[i];
		if(m != 0)
			check = false;

		if(check)
			printf("%d\n", eq[0][0] * result[0] + eq[0][1]);
		else
			printf("0\n");*/
	}

	return 0;
}
