#include <iostream>
#include <string>


using namespace std;

#define START int testcase; \
	cin >> testcase;\
	while(testcase--)

struct ROAD
{
	int a,b;
	int on;
};
//////////global/////////////
int on_city[1000];
ROAD road[1000000];
bool solve;
int must1,must2;

int r_num, c_num;



void BackTrack(int s, int p)
{
	if(solve) return;
	if(s == p && road[must1].on == 1 && road[must2].on == 1/*IsSolve*/)
	{
		solve = true;
		return;
	}
	if(on_city[p]==1)
		return;

	for(int i=0;i<r_num;i++)
	{
		if(road[i].a == p && road[i].on == 0)
		{
			road[i].on = 1;
			on_city[road[i].a] = 1;
			BackTrack(s, road[i].b);
			road[i].on = 0;
			on_city[road[i].b] = 1;
		}

		if(road[i].b == p && road[i].on == 0)
		{
			road[i].on = 1;
			on_city[road[i].b] = 1;
			BackTrack(s, road[i].a);
			road[i].on = 0;
			on_city[road[i].a] = 1;
		}
	}
}

void main()
{
	int i;

	ROAD temp;
	
	START
	{
		cin >> c_num >> r_num;
		memset(road, 0,sizeof(road));
		memset(on_city, 0,sizeof(on_city));
		solve = false;

		for(int i = 0; i < r_num; i++)
		{
			cin >> road[i].a  >> road[i].b;
		}
		cin >> temp.a >> temp.b;
		for(int j = 0;j < r_num; j++)
		{
			if(temp.a == road[j].a && temp.b == road[j].b)
				must1 = j;
			if(temp.a == road[j].b && temp.b == road[j].a)
				must1 = j;
		}
		cin >> temp.a >> temp.b;
		for(int j = 0;j < r_num; j++)
		{
			if(temp.a == road[j].a && temp.b == road[j].b)
				must2 = j;
			if(temp.a == road[j].b && temp.b == road[j].a)
				must2 = j;
		}
		int x;
		cin >> x;
		for(int i = 0; i < x; i++)
		{
			cin >> temp.a  >> temp.b;
			for(int j = 0;j < r_num; j++)
			{
				if(temp.a == road[j].a && temp.b == road[j].b)
					road[j].on = 2;
				if(temp.a == road[j].b && temp.b == road[j].a)
					road[j].on = 2;
			}
		}

		for(int i = 1;i < c_num+1;i++)
		{
			if(solve)
				break;
			BackTrack(i,i);
		}
		if(solve)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}