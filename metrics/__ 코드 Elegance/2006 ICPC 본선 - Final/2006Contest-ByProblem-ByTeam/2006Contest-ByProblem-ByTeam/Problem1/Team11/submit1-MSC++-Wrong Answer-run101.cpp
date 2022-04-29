// wa.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


int main(void)
{
	int nLoop;
	int nCount, nCount2;
	char strData[20];
	unsigned long nTime1, nTime2;
	unsigned long nAnswer;
	int nS1, nS2;

	cin >> nLoop;

	for(nCount=0; nCount<nLoop; ++nCount)
	{
        cin >> strData;

		nTime1 = ((strData[0]-'0')*10 + (strData[1]-'0'))*3600;
		nTime1 += ((strData[3]-'0')*10 + (strData[4]-'0'))*60;
		nTime1 += (strData[6]-'0')*10 + (strData[7]-'0');
		nS1 = (strData[6]-'0')*10 + (strData[7]-'0');

		cin >> strData;
		nTime2 = ((strData[0]-'0')*10 + (strData[1]-'0'))*3600;
		nTime2 += ((strData[3]-'0')*10 + (strData[4]-'0'))*60;
		nTime2 += (strData[6]-'0')*10 + (strData[7]-'0');
		nS2 = (strData[6]-'0')*10 + (strData[7]-'0');

		if(nTime1 < nTime2)
		{
			nTime1 = nTime2 - nTime1;
			nAnswer = nTime1/3600 *1200;
		}
		else
		{
			nTime1 = (86400-nTime1) + nTime2;
			nAnswer = nTime1/3600 *1200-1;
		}

		nTime1 %= 3600;
		nAnswer += nTime1/60 * 20;
		nTime1 %= 60;

		if(nS1<nS2)
		{
			for(nCount2=nS1; nCount2<=nS2; ++nCount2)
				if(nCount2%3==0) nAnswer+=1;
		}else
		{
			for(nCount2=nS1; nCount2<=nS2+60; ++nCount2)
				if(nCount2%3==0) nAnswer+=1;
		}

		cout << nAnswer << endl;	
	}
    
	return 0;
}

