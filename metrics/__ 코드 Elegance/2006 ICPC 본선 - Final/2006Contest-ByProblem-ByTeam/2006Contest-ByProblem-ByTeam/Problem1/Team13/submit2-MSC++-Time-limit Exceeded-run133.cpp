#include <iostream>
using namespace std;

int main()
{
	int nCase;
	int nRow, nCol;
	char** array;
	
	char chac[4] = {'A', 'T', 'G', 'C'};

	cin >> nCase;

	while(nCase--)
	{
		int total=0;
		
		cin >> nRow >> nCol;
		array = new char*[nRow];
		for (int i = 0; i < nRow; i++)
			array[i] = new char[nCol];

		for (i = 0; i < nRow; i++)
			cin >> array[i];

		for (i = 0; i < nCol; i++)
		{
			int flag[4] = {0};
			for (int j =0; j < nRow; j++)
			{
				switch(array[j][i])
				{
					case 'A' :
						flag[0]++; break;
					case 'T' :
						flag[1]++; break;
					case 'G' :
						flag[2]++; break;
					case 'C' :
						flag[3]++; break;
				}
			}

			int max = 0;
			char mmax;
			for (j = 0; j < 4; j++)
			{
				if (max < flag[j])
				{
					max = flag[j];
					mmax = j;
				}
			}
			total = total + nRow - max;
			cout << chac[mmax];

		}
		cout << endl << total << endl;
	}


	return 0;
}