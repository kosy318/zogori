#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> vtr;
int main()

{
	int m,n,i,j,k,testCase,max,flag,sum;
	string input,test1,test2,result;
	int check[1002][4];
	cin >> testCase;
	for(i=0;i<testCase;i++)
	{
		for(k=0;k<52;k++)
				for(j=0;j<4;j++)
					check[k][j]=0;
			
		cin >> m >> n;
		for(j=0;j<m;j++)
		{
			cin >> input;
			for(k=0;k<n;k++)
			{
				if(input[k]=='A') check[k][0]++;
				else if(input[k]=='C') check[k][1]++;
				else if(input[k]=='G') check[k][2]++;
				else if(input[k]=='T') check[k][3]++;
			}
			vtr.push_back(input);

		}
		result="";
		for(j=0;j<n;j++)
		{
			for(k=0;k<4;k++)
			{
				if(k==0) {max = check[j][0];flag=0;}
				else
				{
					if(max < check[j][k]) {max = check[j][k];flag=k;}
				}
			}
			if(flag==0) result += "A";
			else if(flag==1) result +="C";
			else if(flag==2) result +="G";
			else if(flag==3) result +="T";
			
			

		}
		sum=0;
		for(j=0;j<vtr.size();j++)
		{
			test1 = vtr[j];
			for(k=0;k<n;k++)
			{

				if(result[k]!=test1[k]) sum++;
			}
	
		}
		cout << result<< endl;
		cout << sum << endl;
		vtr.clear();

	}

	return 0;
}