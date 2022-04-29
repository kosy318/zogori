#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x, y;
};

int W, H, N;
point P[4004];
int X[4004], Y[4004], NX, NY;

int sort_function_1(const void *t1, const void *t2)
{
	return (*(int *)t1) - (*(int *)t2);
}

int sort_function_x(const void *t1, const void *t2)
{
	return (((point *)t1)->x) - (((point *)t2)->x);
}

int sort_function_y(const void *t1, const void *t2)
{
	return (((point *)t1)->y) - (((point *)t2)->y);
}

int sum;
int answer;

void update(point pp)
{
	if (pp.x < 0) pp.x = 0;
	if (pp.y < 0) pp.y = 0;
	if (pp.x > W) pp.x = W;
	if (pp.y > H) pp.y = H;
	if (N == 0 || pp.x != P[N-1].x || pp.y != P[N-1].y) P[N++] = pp;
}

int main()
{
	int T;
	int i, j;
	point pp;
	int minx, miny, maxx, maxy, xx, yy, nn;
	int minxy1, minxy2, minyx1, minyx2, maxxy1, maxxy2, maxyx1, maxyx2;
	int g1, g2;
	int c;

	scanf("%d", &T);
	while (--T >= 0)
	{
		NX = NY = N = 0;
		answer = 2147483647;
		scanf("%d%d%d", &W, &H, &nn);
		for (i = 0; i < nn; i++)
		{
			scanf("%d%d", &xx, &yy);
			pp.x = xx-1; pp.y = yy-1; update(pp);
			pp.x = xx+1; pp.y = yy-1; update(pp);
			pp.x = xx-1; pp.y = yy+1; update(pp);
			pp.x = xx+1; pp.y = yy+1; update(pp);
			if (xx > 0) X[NX++] = xx-1;
			if (xx <= W) X[NX++] = xx;
			if (yy > 0) Y[NY++] = yy-1;
			if (yy <= H) Y[NY++] = yy;
		}
		
		qsort(X, NX, sizeof(int), sort_function_1);
		qsort(Y, NY, sizeof(int), sort_function_1);
		for (j = i = 1; i < NX; i++)
			if (X[i] != X[i-1]) X[j++] = X[i];
		NX = j;
		for (j = i = 1; i < NY; i++)
			if (Y[i] != Y[i-1]) Y[j++] = Y[i];
		NY = j;

		qsort(P, N, sizeof(point), sort_function_x);
		minx = P[0].x; minxy1 = 99999; minxy2 = -1;
		maxx = P[N-1].x; maxxy1 = 99999; maxxy2 = -1;
		for (i = 0; i < N; i++)
		{
			if (P[i].x == minx)
			{
				if (P[i].y < minxy1) minxy1 = P[i].y;
				if (P[i].y > minxy2) minxy2 = P[i].y;
			}
			if (P[i].x == maxx)
			{
				if (P[i].y < maxxy1) maxxy1 = P[i].y;
				if (P[i].y > maxxy2) maxxy2 = P[i].y;
			}
		}
		
		qsort(P, N, sizeof(point), sort_function_y);
		miny = P[0].y; minyx1 = 99999; minyx2 = -1;
		maxy = P[N-1].y; maxyx1 = 99999; maxyx2 = -1;
		for (i = 0; i < N; i++)
		{
			if (P[i].y == miny)
			{
				if (P[i].x < minyx1) minyx1 = P[i].x;
				if (P[i].x > minyx2) minyx2 = P[i].x;
			}
			if (P[i].y == maxy)
			{
				if (P[i].x < maxyx1) maxyx1 = P[i].x;
				if (P[i].x > maxyx2) maxyx2 = P[i].x;
			}
		}
		
		// sorted by y coordination
		for (i = 0; i < NX; i++)
		{
			g1 = X[i]; g2 = X[i]+1;
			sum = H;

			// right part
			if (maxx - g2 > 0) sum += (maxxy2 - maxxy1) * (maxx - g2);
			c = g2;
			for (j = 0; j < N; j++)
			{
				if (j > 0) sum += (c - g2) * (P[j].y - P[j-1].y);
				if (P[j].x == maxx) break;
				if (P[j].x > c) c = P[j].x;
			}
			c = g2;
			for (j = N-1; j >= 0; j--)
			{
				if (j < N-1) sum += (c - g2) * (P[j+1].y - P[j].y);
				if (P[j].x == maxx) break;
				if (P[j].x > c) c = P[j].x;
			}

			// left part
			if (g1 - minx > 0) sum += (minxy2 - minxy1) * (g1 - minx);
			c = g1;
			for (j = 0; j < N; j++)
			{
				if (j > 0) sum += (g1 - c) * (P[j].y - P[j-1].y);
				if (P[j].x == minx) break;
				if (P[j].x < c) c = P[j].x;
			}
			c = g1;
			for (j = N-1; j >= 0; j--)
			{
				if (j < N-1) sum += (g1 - c) * (P[j+1].y - P[j].y);
				if (P[j].x == minx) break;
				if (P[j].x < c) c = P[j].x;
			}

			if (sum < answer) answer = sum;
		}

		// sorted by x coordination
		qsort(P, N, sizeof(point), sort_function_x);
		for (i = 0; i < NY; i++)
		{
			g1 = Y[i]; g2 = Y[i]+1;
			sum = W;

			// right part
			if (maxy - g2 > 0) sum += (maxyx2 - maxyx1) * (maxy - g2);
			c = g2;
			for (j = 0; j < N; j++)
			{
				if (j > 0) sum += (c - g2) * (P[j].x - P[j-1].x);
				if (P[j].y == maxy) break;
				if (P[j].y > c) c = P[j].y;
			}
			c = g2;
			for (j = N-1; j >= 0; j--)
			{
				if (j < N-1) sum += (c - g2) * (P[j+1].x - P[j].x);
				if (P[j].y == maxy) break;
				if (P[j].y > c) c = P[j].y;
			}

			// left part
			if (g1 - miny > 0) sum += (minyx2 - minyx1) * (g1 - miny);
			c = g1;
			for (j = 0; j < N; j++)
			{
				if (j > 0) sum += (g1 - c) * (P[j].x - P[j-1].x);
				if (P[j].y == miny) break;
				if (P[j].y < c) c = P[j].y;
			}
			c = g1;
			for (j = N-1; j >= 0; j--)
			{
				if (j < N-1) sum += (g1 - c) * (P[j+1].x - P[j].x);
				if (P[j].y == miny) break;
				if (P[j].y < c) c = P[j].y;
			}

			if (sum < answer) answer = sum;
		}

		printf("%d\n", answer);
	}
}