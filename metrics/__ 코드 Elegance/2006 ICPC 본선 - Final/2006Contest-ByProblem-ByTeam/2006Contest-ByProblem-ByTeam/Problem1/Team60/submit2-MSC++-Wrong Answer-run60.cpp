#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int testNum;

	cin >> testNum;

	char buff[100];
	cin.getline(buff, 100, '\n');
	for(int i=0 ; i<testNum ; i++)
	{
		int h1, h2, m1, m2, s1, s2;
		cin.getline(buff, 100, '\n');
		
		char* ptr = buff;
		char temp[2];
		
			temp[0] = *ptr++;
			temp[1] = *ptr++;
			ptr++;
			h1 = atoi(temp);

			temp[0] = *ptr++;
			temp[1] = *ptr++;
			ptr++;
			m1 = atoi(temp);

			temp[0] = *ptr++;
			temp[1] = *ptr++;
			ptr++;
			s1 = atoi(temp);

			temp[0] = *ptr++;
			temp[1] = *ptr++;
			ptr++;
			h2 = atoi(temp);

			temp[0] = *ptr++;
			temp[1] = *ptr++;
			ptr++;
			m2 = atoi(temp);

			temp[0] = *ptr++;
			temp[1] = *ptr++;
			ptr++;
			s2 = atoi(temp);
		
		int sum1 = 0;
		int sum2 = 0;

		sum1 = h1*3600 + m1*60 + s1;
		sum2 = h2*3600 + m2*60 + s2;

		if(sum1 > sum2)
			sum2 += 3600*24;

		int sum = sum2 - sum1 + 1;
		if(sum%3 != 0)
			sum += 1;

		cout << sum/3 << endl;

	}

	return 0;
}