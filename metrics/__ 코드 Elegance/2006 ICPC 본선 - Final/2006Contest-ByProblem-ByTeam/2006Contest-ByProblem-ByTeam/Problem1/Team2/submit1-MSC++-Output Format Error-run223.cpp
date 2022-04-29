//#define TEST
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#ifdef TEST
ifstream in("input.txt");
#else
istream &in = cin;
#endif

int main()
{
	int testcase, i, j, k, num1i, num2i, count;
	string num1, num2;
	in >> testcase;
	for(i = 0; i < testcase; i++)
	{
		in >> num1 >> num2;
		cout << num1 << ' ' << num2;
		num1i = num2i = count = 0;
		j = 5;
		for(k = 0; k < num1.size(); k++)
		{
			if(num1[k] == ':')
				continue;
			num1i += (pow(10, j) * (num1[k]-'0'));
			j--;
		}
		j = 5;
		for(k = 0; k < num2.size(); k++)
		{
			if(num2[k] == ':')
				continue;
			num2i += (pow(10, j) * (num2[k]-'0'));
			j--;
		}
		cout << endl << num1i << ' ' << num2i << endl;
		while(num1i != num2i)
		{
			if(num1i == 240000)
			{
				num1i = 0;
				continue;
			}
			else if(num1i % 10000 == 6060)
			{
				num1i += 3940;
				continue;
			}
			else if(num1i % 10000 == 6000)
			{
				num1i += 4000;
				continue;
			}
			else if(num1i % 100 == 60)
			{
				num1i += 40; 
				continue;
			}

			if(num1i % 3 == 0)
			{
				count++;
			}
			num1i++;
		}
		if(num1i %3 == 0)
			count++;
		cout << count << endl;
	}
	return 0;
}