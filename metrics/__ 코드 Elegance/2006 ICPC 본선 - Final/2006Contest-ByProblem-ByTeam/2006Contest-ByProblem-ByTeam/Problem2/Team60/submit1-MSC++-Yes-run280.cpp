#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> buff[1000];

int main()
{
	int testNum;
	cin >> testNum;

	for(int i=0 ; i<testNum ; i++)
	{
		int row, col;
		char temp[51][1000];
		cin >> row >> col;
		char asdf[51];
		cin.getline(asdf, 51, '\n');		
		memset(buff, 0, sizeof(buff));
		for(int j=0 ; j<row ; j++)
		{
			cin.getline(temp[j], sizeof(temp), '\n');
			for(int k=0 ; k<col ; k++)
			{
				buff[k].push_back(temp[j][k]);
			}
		}

		for(int j=0 ; j<col ; j++)
		{
			sort(buff[j].begin(), buff[j].end());
		}
	
		int max = 0;
		char maxChar = 0;
		int cnt = 0;
		char tmp[1000];
		for(int j=0 ; j<col ; j++)
		{
			max = maxChar = cnt = 0;
			char ptr = buff[j][0];
			for(int k=0 ; k<row ; k++)
			{
				if(ptr == buff[j][k])
				{
					cnt++;
				}
				else
				{
					if(max < cnt)
					{
						max = cnt;
						maxChar = ptr;
					}
					ptr = buff[j][k];
					cnt = 1;
				}
			}
			if(max < cnt)
			{
				maxChar = ptr;
			}

			tmp[j] = maxChar;
		}

		cnt = 0;
		for(int j=0 ; j<col ; j++)
			cout << tmp[j];
		cout << endl;
		for(int j=0 ; j<row ; j++)
		{
			for(int k=0 ; k<col ; k++)
			{
				if(temp[j][k] != tmp[k])
					cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}







