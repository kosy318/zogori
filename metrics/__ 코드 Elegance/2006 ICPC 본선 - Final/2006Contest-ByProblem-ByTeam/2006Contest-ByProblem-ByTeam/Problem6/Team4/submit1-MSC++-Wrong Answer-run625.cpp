#include <iostream>
using namespace std;

int tube[20][2];
int n;

int main()
{
	int time;

	cin >> time;
	for(int t = 0; t < time; t++)
	{
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			cin >> tube[i][0] >> tube[i][1] ;
		}
		int m ;

		cin >> m;
		int bcd = 7560;

		int ktotal = 0;

		for(int i = 0; i < n; i++)
		{
			ktotal += bcd / tube[i][0];

			//cout << ktotal << endl;
		}

		
		int sum = bcd * m;

		for(int i = 0; i < n; i++)
		{
			sum += tube[i][1] * (bcd / tube[i][0]); 
			//cout << sum << endl;
		}
		double result = static_cast<double>(sum) / ktotal  ;
		double cast_result = static_cast<double> (static_cast<int> (result)); 
		
		//cout << "result : "  << result << endl;
		//cout << "cast result : "  << cast_result << endl;
		if (result == cast_result)
		{
			cout << result << endl;
		}
		else 
		{	
			cout << 0 << endl;
		}

	}
	return 0;
}