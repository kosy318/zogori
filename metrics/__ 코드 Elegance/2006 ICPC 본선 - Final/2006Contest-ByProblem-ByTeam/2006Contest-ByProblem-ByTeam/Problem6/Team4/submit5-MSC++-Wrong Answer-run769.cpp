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
		int bcd = 2520;

		if(n == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			int ktotal = 0;

			for(int i = 0; i < n; i++)
			{
				ktotal += bcd / tube[i][0];
			}

			int sum = bcd * m;

			for(int i = 0; i < n; i++)
			{
				sum += tube[i][1] * (bcd / tube[i][0]); 
			}
			double result =  sum / ktotal  ;
			double cast_result = static_cast<double> (static_cast<int> (result)); 
			
		
			int pre = result *  tube[0][0] + tube[0][1];

			for(int i = 1;i < n ;i ++)
			{
				 if(pre != (result * tube[i][0] + tube[i][1]))
					 result = 0;
			}
			cout << result << endl;
	
		}

	}
	return 0;
}