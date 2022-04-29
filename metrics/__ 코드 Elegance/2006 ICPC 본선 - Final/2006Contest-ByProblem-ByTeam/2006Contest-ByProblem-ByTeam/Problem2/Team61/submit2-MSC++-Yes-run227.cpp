#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#define START int testcase; \
	cin >> testcase;\
	while(testcase--)

#define LOOP(a, b, c) for(int a = b ; a < c ; a++)
#define FOR(a, b) LOOP(a, 0, b)

using namespace std;

#define GetMAX(a, b, c, d) if(a == b && b == c && b != d && d != a) { retur}
char sw(int A, int C, int G, int T)
{
	//if(T == A && A == G && G == C && G == T )
	//{
	//	return 'A';
	//}
	//if(T == A && A == G && G != C && T != G)
	//{
	//	return 'A'; 
	//}
	//if(T == A && A == G && G != C && T != G)
	//{
	//	return 'A'; 
	//}
	

	vector<int> test;
	test.push_back(A);
	test.push_back(C);
	test.push_back(G);
	test.push_back(T);

	vector<int>::iterator it;
	it = max_element(test.begin(), test.end());

	switch(it - test.begin())
	{
	case 0:
		return 'A';
	case 1:
		return 'C';
	case 2:
		return 'G';
	case 3:
		return 'T';
	}

}

int main()
{
	int m, n;
	int T, A, G, C;
	int wrong;
	char* stdg;
	char gene[1000][50];

	START
	{
		memset(gene, 0, sizeof(gene));

		cin >> m >> n;	
		
		stdg = new char[n+1];
		wrong = T = A = G = C = 0;

		FOR(i,m)
		{
			FOR(j,n)
			{
				cin >> gene[j][i];
			}
		}
		
		FOR(i,n)
		{
			T = 0;
			A = 0;
			G = 0;
			C = 0;

			FOR(j,m)
			{
				switch(gene[i][j])
				{
				case 'T':
					T++;		
					break;
				case 'A':
					A++;
					break;
				case 'G':
					G++;
					break;
				case 'C':
					C++;
					break;
				}
			}
			stdg[i] = sw(A, C, G, T);
		}

		/*FOR(i,n)
		{
			stdg[i] = sw(T, A, G, C);
		}*/
		stdg[n] = '\0';

		FOR(i,n)
		{
			FOR(j,m)
			{
				if(stdg[i] != gene[i][j])
					wrong++;
			}
		}

		cout << stdg << endl << wrong << endl;
		delete stdg;
	}
}