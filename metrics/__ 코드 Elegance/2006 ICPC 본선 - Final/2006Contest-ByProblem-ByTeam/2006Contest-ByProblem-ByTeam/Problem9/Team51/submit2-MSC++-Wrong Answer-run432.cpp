#include <iostream>
using namespace std;
#include <cstdio>

//#include <fstream>
//fstream fin ("i.txt");
//#define cin fin

struct myLine
{
	double a;
	double b;
	double c;
};

struct myPoint
{
	double x;
	double y;
};

myLine points_to_line(myPoint, myPoint);
void input();
void process(int);

myPoint p[1003];

void main()
{
	input();
}

myLine points_to_line(myPoint p1, myPoint p2)
{
	myLine l;
	if (p1.x == p2.x) {
		l.a = 1;
		l.b = 0;
		l.c = -p1.x;
	}
	else 
	{
		l.b = 1;
		l.a = -(p1.y - p2.y) / (p1.x - p2.x);
		l.c = -(l.a * p1.x) - (l.b * p1.y);
	}

	return l;
}

void input()
{
	int nCase;
	int n;

	cin >> nCase;
	for (int i = 0; i < nCase; ++i)
	{
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> p[j].x >> p[j].y;
		}
		process(n);
	}
}

void process(int n)
{
	myPoint bp;
	myLine l;

	double distance, dist, minDistance;

	minDistance = 10000;
	for (int i = 0; i < n; ++i)
	{
		
		bp = p[i];
		dist = 0;
		for (int j = 0; j < n - 1; ++j)
		{
			if ( i != j && i != (j + 1))
			{
				l = points_to_line(p[j], p[j+1]);

				if (l.b)
				{
					distance = (-l.c - l.a * bp.x) / l.b;
					if (distance > bp.y)
					{
						distance -= bp.y;
						if (dist < distance)
						{
							dist = distance;
						}
					}
				}
			}
		}
		if (dist < minDistance)
		{
			minDistance = dist;
		}

	//	if (p[i].y == p[i - 1].y)
	//	{
			bp.x = (p[i].x + p[i - 1].x) / 2;
			//bp.y = p[i].y;
			bp.y = (p[i].y + p[i - 1].y) / 2;
			dist = 0;
			for (int j = 0; j < n - 1; ++j)
			{
				l = points_to_line(p[j], p[j+1]);

				if (l.b)
				{
					distance = (-l.c - l.a * bp.x) / l.b;
					if (distance > bp.y)
					{
						distance -= bp.y;
						if (dist < distance)
						{
							dist = distance;
						}
					}
				}				
			}
			if (dist < minDistance)
			{
				minDistance = dist;
			}

	//	}
	}
	if (minDistance > 1000) cout << "IMPOSSIBLE" << endl;
	else printf ("%.1f \n", minDistance);
}