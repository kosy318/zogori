#include<stdio.h>
#include<math.h>

#include<vector>
#include<set>

		/*
3
12
1 8
3 11
5 1
7 4
9 3
10 1
12 7
14 4
16 3
19 2
20 13
22 12
11
11 09
16 215
21 9
26 215
31 9
36 1
41 9
46 215
51 9
56 215
61 9
8
7 8
12 18
17 8
27 23
37 23
47 8
52 18
57 8
*/

typedef struct _f1_type
{
	double a, b;
} f1_type;

typedef struct _coord
{
	int x, y;
} coord;

typedef struct _dcoord
{
	double x, y;
} dcoord;

bool operator<(const dcoord &A, const dcoord &B)
{
	if(A.x < B.x) return true;
	else if(A.x == B.x && A.y < B.y) return true;

	return false;
}

coord co[1000];
f1_type f1[1000];

std::vector<dcoord> cx;



int main()
{
	int n;
	int m;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &co[i].x, &co[i].y);
			if(i == 0) continue;

			f1[i-1].a = (double)(co[i].y - co[i-1].y) / (co[i].x - co[i-1].x);
			f1[i-1].b = (double)co[i].y - (f1[i-1].a * co[i].x);
		}

/*
		for(i = 0; i < m; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(f1[i].a == f1[i].b) continue;

				dcoord temp;
				temp.x = (double)(f1[i].b - f1[j].b) / (double)(f1[i].a - f1[j].b);
				temp.y = (double)(f1[i].a * temp.x) + f1[i].b;
				cx.push_back(temp);
			}
		}

		int size = cx.size();

		std::set<dcoord> ds;
		ds.clear();
		for(int z = 0; z < size; z++)
		{
			for(int g = 0; g < m; g++)
			{
				if(cx[z].y >= (f1[g].a * cx[z].x + f1[g].b))
				{
					ds.insert(cx[z]);
				}
			}
		}

		double min = 1001;
		std::set<dcoord>::iterator itr;
		for(itr = ds.begin(); itr != ds.end(); itr++)
		{
			dcoord p;
			p.x = (*itr).x;
			p.y = (*itr).y;

			for(int z = 0; z < m-1; z++)
			{
				if(co[z].x < p.x && p.x < co[z+1].x) break;
			}

			double gap = (f1[z].a * p.x + p.y) - (f1[z].a * p.x + f1[z].b);
			if(gap < min) min = gap;
		}
		*/

		double min = 1001;
		for(i = 0; i < m; i++)
		{
			double partmax = 0;
			for(int j = 0; j < m; j++)
			{
				double height = f1[j].a * co[i].x + f1[j].b - co[i].y;
				if(partmax < height)
				{
					partmax = height;
				}
			}

			if(partmax < min)
			{
				min = partmax;
			}

		}

		for(i = 0; i < m-1; i++)
		{
			if(co[i].y == co[i+1].y)
			{
				double midx = (double)(co[i].x + co[i+1].x) / 2.0;
				double midy = (double)(co[i].y);

				double partmax = 0;
				for(int j = 0; j < m-1; j++)
				{
					double height = f1[j].a * midx + f1[j].b - midy;
					if(partmax < height)
					{
						partmax = height;
					}
				}

				if(partmax < min)
				{
					min = partmax;
				}
			}
		}


		if(min > 1000)
		{
			printf("IMPOSSIBLE\n");
		} else {
			printf("%.1f\n", min);
		}
	}
	return 0;
}