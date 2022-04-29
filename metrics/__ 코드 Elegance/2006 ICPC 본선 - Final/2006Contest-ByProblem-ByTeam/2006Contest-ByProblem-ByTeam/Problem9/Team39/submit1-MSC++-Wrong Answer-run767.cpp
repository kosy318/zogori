#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

struct POINT{int x,y;};

void GetValue( vector<POINT> vertices)
{
	vector<float> a;
	vector<float> b;

	for(int i = 0 ; i< vertices.size()-1 ; i++)
	{
		float m = (float)((float)vertices[i+1].y - (float)vertices[i].y)  /  ((float)vertices[i+1].x - (float)vertices[i].x);
		float tempb = (float)vertices[i].y - m * (float)vertices[i].x;
		a.push_back(m);
		b.push_back(tempb);
	}

	float max = 0;
	float final_min = 10000000;
	
	int maxIdx = 0;
	for(int i = 0 ; i < vertices.size() ; i++)
	{
		max = 0;
		for(int j = 0 ; j < a.size() ; j++)
		{
			float y = a[j] * (float)vertices[i].x + b[j];
			//float h = y - (float)vertices[i].y;
			cout << "h = " << y-(float)vertices[i].y << endl;

			if(max < y )
			{
				max = y;		
				maxIdx = i;
			}
		}
		//cout << "h = " << max-(float)vertices[i].y << endl;
		cout << " sdgfafasgagag" << endl;

		if (max-(float)vertices[maxIdx].y < final_min) {
			final_min = max-(float)vertices[maxIdx].y;
		}
	}

	if(final_min >= 1000)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
		printf("%.1f\n",final_min);




}

int main()
{
	int nQues;
	cin >> nQues;

	for(int Ques = 0 ; Ques < nQues ; Ques++)
	{
		int nvert;
		cin >> nvert;
		vector<POINT> vertices;
		vertices.clear();
		for(int i = 0 ; i < nvert ; i++)
		{
			POINT temp;
			cin >> temp.x >> temp.y ;
			vertices.push_back(temp);
		}
		GetValue(vertices);

	}
	return 0;
}