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
		char temp1[7], temp2[7];
		temp1[6] = temp2[6] = '\0';
		
			temp1[0] = *ptr++;
			temp1[1] = *ptr++;
			ptr++;

			temp1[2] = *ptr++;
			temp1[3] = *ptr++;
			ptr++;

			temp1[4] = *ptr++;
			temp1[5] = *ptr++;
			ptr++;
			
			temp2[0] = *ptr++;
			temp2[1] = *ptr++;
			ptr++;
			

			temp2[2] = *ptr++;
			temp2[3] = *ptr++;
			ptr++;
			

			temp2[4] = *ptr++;
			temp2[5] = *ptr++;
			ptr++;
			
		
		int sum1 = atoi(temp1);
		int sum2 = atoi(temp2);

		if(sum1 > sum2)
			sum2 += 240000;

		int cnt = 0;

		for(int j=sum1 ; j<=sum2 ; j++)
		{

			if(j-j/100*100 == 60)
			{
				j = j + 40;
			}

			if(j-j/10000*10000 == 6000)
				j += 4000;

			if(j%3 == 0)
				cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}