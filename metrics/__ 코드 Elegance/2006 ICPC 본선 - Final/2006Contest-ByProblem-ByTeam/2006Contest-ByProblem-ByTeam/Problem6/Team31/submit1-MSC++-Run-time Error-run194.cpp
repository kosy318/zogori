#include <iostream>
using namespace std;

int main()
{
	int caseNum;
	cin >> caseNum;

	int func[11][1001];

	int i;
	for(i = 0; i < caseNum; i++)
	{
		int n, a, b, j, mult = 1, k, sumB, M;
		cin >> n;
		for(j = 0; j < n; j++)
		{
			cin >> func[j][0] >> func[j][1];

			mult *= func[j][0];
		}

		cin >> M;

		k = sumB = 0;
		for(j = 0; j < n; j++)
		{
			k += (mult / func[j][0]);
			sumB += (func[j][1] *(mult / func[j][0]));
		}

		M = mult * M;

		if((M + sumB) % k == 0)
			cout << (M + sumB) / k << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}