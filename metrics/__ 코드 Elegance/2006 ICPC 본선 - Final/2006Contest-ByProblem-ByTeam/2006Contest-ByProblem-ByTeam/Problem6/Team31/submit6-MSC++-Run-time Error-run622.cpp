#include <iostream>
using namespace std;

int main()
{
	int caseNum;
	cin >> caseNum;

	int func[21][2];

	int i, j, k, n;
	for(i = 0; i < caseNum; i++)
	{
		unsigned long int sumB, M, temp, mult = 1;

		cin >> n;
		if(n <= 0)
		{
			cin >> M;
			cout << "0" << endl;
			continue;
		}

		for(j = 0; j < n; j++)
		{
			cin >> func[j][0] >> func[j][1];

			mult *= func[j][0];
		}

		cin >> M;

		k = sumB = temp = 0;
		for(j = 0; j < n; j++)
		{
			temp = mult / func[j][0];
			k += temp;
			sumB += (func[j][1] * temp);
		}

		M = mult * M;

//		cout << k << " " << sumB << " " << M << endl;

		if(k != 0 && ((M + sumB) % k) == 0)
			cout << ((M + sumB) / k) << endl;
		else
			cout << "0" << endl;
	}

	return 0;
}