#include <iostream>
using namespace std;
#include <cstdio>

//#include <fstream>
//fstream fin ("i.txt");
//#define cin fin

struct myLine
{
	long double a;
	long double b;
	long double c;
};

struct myPoint
{
	long double x;
	long double y;
};

myLine points_to_line(myPoint, myPoint);
void input();
void process(long long);
void init();

myPoint p[3000];

void main()
{
	input();
}
void init()
{
	for (int i = 0; i < 3000; ++i)
	{
		p[i].x = 0;
		p[i].y = 0;
	}
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
	long long nCase;
	long long n;

	cin >> nCase;
	for (long long i = 0; i < nCase; ++i)
	{
		cin >> n;
		init();
		for (long long j = 0; j < n; ++j)
		{
			cin >> p[j].x >> p[j].y;
		}
		process(n);
	}
}

void process(long long n)
{
	myPoint bp;
	myLine l;

	long double distance, dist, minDistance;

	minDistance = 10000;
	p[n] = p[n - 1];
	for (long long i = 0; i < n; ++i)
	{
		
		bp = p[i];
		dist = 0;
		for (long long j = 0; j < n; ++j)
		{
		//	if ( i != j && i != (j + 1))
		//	{
				l = points_to_line(p[j], p[j+1]);

				if (l.b)
				{
					distance = -(l.c + l.a * bp.x);
					if (distance > bp.y)
					{
						distance -= bp.y;
						if (dist < distance)
						{
							dist = distance;
						}
					}
				}
		//	}
		}
		if (dist < minDistance)
		{
			minDistance = dist;
		}

		if (p[i].y == p[i - 1].y){
			bp.x = (p[i].x + p[i - 1].x) / 2;
			bp.y = (p[i].y + p[i - 1].y) / 2;
			dist = 0.0;
			for (int j = 0; j < n; ++j)
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
		}

	}
	if (minDistance == 10000) cout << "0.0" << endl;
	else if (minDistance > 1000) cout << "IMPOSSIBLE" << endl;
	else printf ("%.1f \n", minDistance);
}