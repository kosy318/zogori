#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define T	1
#define A	2
#define G	3
#define C	4



char DNA[55][1010];
char result[1010];
char info[] = {'N', 'T', 'A', 'G', 'C'};
int counting[5];

int find_max()
{
	int temp;
	int result;

	temp = counting[1];
	result = 1;

	if(temp < counting[2]) {
		temp = counting[2];
		result = 2;
	}

	if(temp < counting[3]) {
		temp = counting[3];
		result = 3;
	}

	if(temp < counting[4]) {
		temp = counting[4];
		result = 4;
	}

//	cout << "max : " << temp << endl << endl;

	return result;
}

int main()
{
	int nTestCase;
	int nHowManyDNAs;
	int nDNALength;
	int nError;

	int i, j, k, l;

	cin >> nTestCase;

	while(nTestCase > 0) {
		
		memset(DNA, 0, sizeof(DNA));
		memset(result, 0, sizeof(result));
		memset(counting, 0, sizeof(counting));

		cin >> nHowManyDNAs;
		cin >> nDNALength;

		for(i=1; i<=nHowManyDNAs; ++i) {
			scanf("%s", DNA[i]);
		}

		for(j=0; j<nDNALength; ++j) {
			for(i=1; i<=nHowManyDNAs; ++i) {
				
				switch(DNA[i][j]) {
					case 'T' :
						++counting[T];
						break;

					case 'A' :
						++counting[A];
						break;

					case 'C' :
						++counting[C];
						break;

					case 'G' :
						++counting[G];
						break;
				}
			}

			result[j] = info[find_max()];
		//	cout << "MAX FIND : " << info[find_max()] << endl;
			memset(counting, 0, sizeof(counting));
		}

		result[j] = '\0';

		nError = 0;

		for(i=1; i<=nHowManyDNAs; ++i) {
			for(j=0; j<nDNALength; ++j) {
				if(result[j] != DNA[i][j])
					++nError;
			}
		}

		printf("%s\n", result);
		cout << nError << endl;

		--nTestCase;
	}

	return 0;
}

/*
3
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
4 10
ACGTACGTAC
CCGTACGTAG
GCGTACGTAT
TCGTACGTAA
6 10
ATGTTACCAT
AAGTTACGAT
AACAAAGCAA
AAGTTACCTT
AAGTTACCAA
TACTTACCAA
*/