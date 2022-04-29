#include <iostream>
using namespace std;


int main()
{
	int tc;
	int ns;
	int len;
	int i, j, k,x;

	int a,t,g,c;

	cin >> tc;

	int dl;

	char szGene[51][1001];
	char szAnswer[1001];

	for (i = 0; i < tc; i++)
	{
		cin >> ns >> len;

		for (j =0; j < ns; j++)
		{
			cin >> szGene[j];
		}
		
		dl = 0;

		for (j = 0; j < len; j++)
		{
			a =t=g=c=0;
			
			for (k =0; k < ns; k++)
			{
				switch (szGene[k][j])
				{
				case 'A':a++;break;
				case 'T':t++;break;
				case 'G':g++;break;
				case 'C':c++;break;
				}
			}

			if (a >= t && a>= g && a>=c)
			{
				szAnswer[j] = 'A';
				dl += (t+g+c);
			}
			else if (c>=t && c>=g)
			{
				szAnswer[j] = 'C';
				dl += (a+g+t);
			}
			else if (g>=t)
			{
				szAnswer[j] = 'G';
				dl += (a+t+c);
			}
			else
			{
				szAnswer[j] = 'T';
				dl += (a+g+c);
			}
		}
		szAnswer[j] = 0;

		cout << szAnswer << endl << dl << endl;
	}


	return 0;
}