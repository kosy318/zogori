#include <iostream>
#include <string>
using namespace std;
int main()
{
	int testcase;

	cin >> testcase;
	while(testcase--)
	{
		string dna[1000];
		string result;
		int k=0,i=0,m=0,n=0,resval=0;
		cin >> m >> n;
		int cntA=0, cntC=0, cntG=0, cntT=0;
		k=m;
		while(k--)
		{
			cin >> dna[i++];
		}
		for(i=0;i<n;i++)
		{
			cntA=0; cntC=0; cntG=0; cntT=0;
			for(int j=0;j<m;j++)
			{
				if(dna[j][i]=='A')
						cntA++;
				else if(dna[j][i] == 'C')
						cntC++;
				else if(dna[j][i] == 'G')
						cntG++;
				else 	cntT++;
			//	cout << dna[j][i]<<" ";

			}
			//cout << cntA << cntC << cntG <<cntT;
			if(cntA >= cntC && cntA >= cntG && cntA >= cntT)
				result+="A";
			else if(cntC > cntA && cntC >= cntG && cntC>=cntT)
				result+="C";
			else if(cntG > cntA && cntG > cntC && cntG >= cntG)
				result+="G";
			else result+= "T";
			if(result[i]=='A')
				resval += (cntC+cntG+cntT);
			else if( result[i] == 'C')
				resval += (cntA+ cntG+ cntT);
			else if (result[i] == 'G')
				resval += (cntA+cntC+cntT);
			else resval += (cntA+cntC+cntG);
	
		}
		cout <<result << endl;
		cout << resval <<endl;







	}
	return 0;
}

