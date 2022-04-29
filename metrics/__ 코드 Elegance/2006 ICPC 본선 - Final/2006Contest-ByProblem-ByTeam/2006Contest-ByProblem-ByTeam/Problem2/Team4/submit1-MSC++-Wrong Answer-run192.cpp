// team04 


#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;



const int NUC_NUM = 4;
const int MAX_SEQ = 1000;



int main()
{
	unsigned short** accumAll = new unsigned short* [NUC_NUM];
	for (int i = 0; i < NUC_NUM; ++i)
		accumAll[i] = new unsigned short [MAX_SEQ];
	char* seq = new char [MAX_SEQ + 1];

	int numOfTestCases;
	cin >> numOfTestCases;

	while (numOfTestCases--)
	{
		int numOfSeqs, seqLen;
		cin >> numOfSeqs >> seqLen;

		for (int i = 0; i < NUC_NUM; ++i)
		{
			for (int j = 0; j < seqLen; ++j)
				accumAll[i][j] = 0;
		}

		for (int i = 0; i < numOfSeqs; ++i)
		{
			cin >> seq;
			for (int j = 0; j < seqLen; ++j)
			{
				if (seq[j] == 'A')
					accumAll[0][j]++;
				else if (seq[j] == 'T')
					accumAll[1][j]++;
				else if (seq[j] == 'G')
					accumAll[2][j]++;
				else if (seq[j] == 'C')
					accumAll[3][j]++;
			}
		}

		int consensusError = 0;
		for (int i = 0; i < seqLen; ++i)
		{
			int max = 0;
			for (int j = 1; j < NUC_NUM; ++j)
			{
				if (accumAll[j][i] > accumAll[max][i])
					max = j;
			}

			if (max == 0)
				cout << 'A';
			else if (max == 1)
				cout << 'T';
			else if (max == 2)
				cout << 'G';
			else if (max == 3)
				cout << 'C';

			consensusError += numOfSeqs - accumAll[max][i];
		}

		cout << '\n' << consensusError << '\n';
	}

	delete [] seq;
	for (int i = 0; i < NUC_NUM; ++i)
		delete [] accumAll[i];
	delete [] accumAll;
}