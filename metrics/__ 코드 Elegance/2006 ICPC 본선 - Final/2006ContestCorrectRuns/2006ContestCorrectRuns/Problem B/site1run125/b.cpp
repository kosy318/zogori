#include <iostream>
#include <string>
using namespace std;

//#include <fstream>
//fstream fin("b.in");
//#define cin fin


#define askii 65
int length,num;
int check[26];
char oup[1001];
string table[50];

void process()
{
	int i, j, k, max, index, sum = 0;
	for(i = 0; i < length; ++i)
	{
		for(j = 0; j < 26; ++j)
			check[j] = 0;
		for(j = 0; j < num; ++j)
			check[table[j][i]-askii]++;
		
		max = 0;
		index = -1;
		for(j = 0; j  <26; ++j)
		{
			if(check[j] > max)
			{
				max = check[j];
				index = j;
			}
		}
		sum += num - check[index];
		oup[i] = askii  + index;		
	}
	oup[i] = '\n';
	cout << oup << sum << endl;

}

int main()
{
	int testNum;
	cin >> testNum;
	for(int i =0; i < testNum; ++i)
	{
		cin >> num >> length;
		for(int j = 0; j < num; ++j)
			cin >> table[j];
		process();
	}
	return 0;
}