#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;


int GetValue(char str[][1001], int line, int length)
{
	int val = 0;

	int arr['Z'] = {0,};

	for(int i = 0 ; i < length ; i++)
	{

		int j;
		for(j = 0 ; j < line ; j++)
			arr[ str[j][i] ] +=1;

		int max = 0;
		int maxIdx = 0;
		for(j = 'A' ; j < 'Z' ; j++)
		{
			if(max < arr[j]) 
			{
				max = arr[j];
				maxIdx = j;
			}
		}

		val += (line - max);
		

		char tmp = maxIdx;
		cout << tmp;


		memset(arr,0,sizeof(int)*'Z');
		
	}

	cout << endl;
	return val;
}

int main()
{
	int nQues;
	cin >> nQues;

	char str[50][1001];
	for(int Ques = 0 ; Ques < nQues ; Ques++)
	{
		int line,length;
		cin >> line >> length;
		
		for(int i = 0 ; i < line ; i++)
		{	
			cin >> str[i];
		}

		cout << GetValue(str, line, length) << endl;

	}
	return 0;
}