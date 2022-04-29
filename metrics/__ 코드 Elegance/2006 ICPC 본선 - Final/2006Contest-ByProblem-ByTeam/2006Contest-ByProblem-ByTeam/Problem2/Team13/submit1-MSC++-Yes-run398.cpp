#include <iostream>
using namespace std;
int flag[1000][4];
int main()
{
	int nCase;
	int nRow, nCol;
	char** array;

	char chac[4] = {'A', 'C', 'G', 'T'};

	cin >> nCase;

	while(nCase--)
	{
		cin >> nRow >> nCol;
		array = new char*[nRow];
		
		
		for (int i = 0; i < nRow; i++)
		{
			array[i] = new char[nCol];

			cin >> array[i];

			for (int j = 0; j < nCol; j++)
			{
				switch(array[i][j])
				{
					case 'A' :
						flag[j][0]++; break;
					case 'C' :
						flag[j][1]++; break;
					case 'G' :
						flag[j][2]++; break;
					case 'T' :
						flag[j][3]++; break;
				}
			}
		}

		int total=0;
		for (i = 0; i < nCol; i++)
		{
			int max = 0;
			char mmax;
			
			for (int j = 0; j < 4; j++)
			{
				if (max < flag[i][j])
				{
					max = flag[i][j];
					mmax = j;
				}
				flag[i][j] = 0;
			}
			total = total + nRow - max;
			cout << chac[mmax];
		}
		cout << endl << total << endl;

	}
	return 0;
}