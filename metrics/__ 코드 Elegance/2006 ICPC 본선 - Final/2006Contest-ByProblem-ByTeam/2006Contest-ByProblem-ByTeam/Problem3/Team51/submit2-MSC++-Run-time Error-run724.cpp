#include <iostream>

using namespace std;
#include <fstream>
fstream fin("F.in");
#define cin fin


#define MAX 50005
#define MAXK 1000000
struct data
{
	int max;
	int min;
};
data point[MAX];
data point2[MAX];
int wedth,height;
void init()
{
	int i;
	for(i = 0; i <= wedth; ++i)
	{
		point[i].min = point2[i].min = MAXK;
		point[i].max = point2[i].max =-1;
	}
}

void process()
{
	int pointNum,min1,max1,x,y,i,j,minY,maxY,sum=0,lengthMaxX,lengthMaxY,length,minSum,tempSum,temp,min2,max2;
	cin >> wedth >> height;
	wedth;
	height;
	init();
	cin >> pointNum;

	min1 = MAXK;
	max1 = 0;
	for(i = 0; i < pointNum; ++i)
	{
		cin >> x >> y;
		if( y > max1)
			max1 = y;
		if( y-1 < min1)
			min1 = max(0,y-1);
		if(point[x].min > y-1)
			point[x].min = max(y-1,0);
		if(point[x].max < y)
			point[x].max = y;
		if(x-1 >= 0)
		{
			if(point[x-1].min > y-1)
				point[x-1].min = max(y-1,0);
			if(point[x-1].max < y)
				point[x-1].max = y;
		}
	}
	
	min2 = MAXK;
	max2 = -1;
	lengthMaxY = 0;
	for(i = min1; i <= max1; ++i)
	{
		minY = MAX;
		maxY = -1;
		for(j =0; j <= height; ++j)
		{
			if(point[j].min <= i && point[j].max >=i)
			{
				if(minY > j)
				{
					if(min2 > j)
						min2 = j;
					minY = j;
				}
				if(maxY < j)
				{
					if(max2 < j)
						max2 = j;
					maxY = j;
				}
			}
		}
		for(j = minY; j <= maxY; ++j)
		{
			if(point[j].min > i)
				point[j].min = i;
			if(point[j].max < i)
				point[j].max = i;
		}
		point2[i].min = minY;
		point2[i].max = maxY;
		length = maxY - minY +1;
		if(length > 0)
		{
			sum += length;
			if(length > lengthMaxY)
				lengthMaxY = length;
		}
	}
	lengthMaxX = 0;
	for(i = 0; i <= height; ++i)
	{
		length = point[i].max - point[i].min + 1;
		if(length > lengthMaxY)
			lengthMaxY = length;
	}
	if(lengthMaxY == wedth || lengthMaxX == height)
	{
		cout << sum << endl;
	}
	else 
	{
		minSum = MAX;

		for(i = min1; i <= max1; ++i)
		{
			tempSum = sum;
			temp = point2[i].max - point2[i].min + 1;
			if(temp> 0)
				tempSum += wedth - temp;
			else
				tempSum += wedth;
			for(j = min2; j <=max2; ++j)
			{
				if(point[j].max >i && point[j].min > i)
					tempSum += point[j].min -i-1;
				else if(point[j].max < i && point[j].min < i)
					tempSum += i - point[j].max-1;
			}
			if(tempSum < minSum)
				minSum = tempSum;
		}
		for(i = min2; i <= max2; ++i)
		{
			tempSum = sum;
			temp = point[i].max - point[i].min + 1;
			if(temp> 0)
				tempSum += height - temp;
			else
				tempSum += height;
			for(j = min1; j <=max1; ++j)
			{
				if(point2[j].max >i && point2[j].min > i)
					tempSum += point2[j].min -i-1;
				else if(point2[j].max < i && point2[j].min < i)
					tempSum += i - point2[j].max-1;
			}

			if(tempSum < minSum)
				minSum = tempSum;
		}
		cout << minSum << endl;
	}
		
}


int main()
{
	int testNum;
	cin >> testNum;
	for(int i = 0; i < testNum; ++i)
	{
		process();
	}
	return 0;
}