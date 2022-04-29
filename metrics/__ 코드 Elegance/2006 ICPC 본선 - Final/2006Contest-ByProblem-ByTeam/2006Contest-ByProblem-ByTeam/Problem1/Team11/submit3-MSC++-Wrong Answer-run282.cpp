// wa.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;


int main(void)
{
	int i,j;
	int nLoop;
	int nCount, nCount2;
	char strData[20];
	unsigned long nTime1, nTime2, temp1, temp2;
	unsigned long nHour, nMinute;
	unsigned long nAnswer;
	int n11,n12,n21,n22;
	int nS1, nS2;

	cin >> nLoop;

	for(nCount=0; nCount<nLoop; ++nCount)
	{
        cin >> strData;

		n11 = ((strData[0]-'0')*10 + (strData[1]-'0'));
		nTime1 = n11*3600;
		n12 = ((strData[3]-'0')*10 + (strData[4]-'0'));
		nTime1 += n12*60;
		nS1 = (strData[6]-'0')*10 + (strData[7]-'0');
 		nTime1 += nS1;

		cin >> strData;
		n21 = ((strData[0]-'0')*10 + (strData[1]-'0'));
		nTime2 = n21*3600;
		n22 = ((strData[3]-'0')*10 + (strData[4]-'0'));
		nTime2 += n22*60;
		nS2 = (strData[6]-'0')*10 + (strData[7]-'0');
		nTime2 += nS2;
		
		temp1 = (n11+n12)%3;
		temp2 = (n21+n22)%3;

		if(nTime1 < nTime2)
		{
			nHour = (nTime2 - nTime1) / 3600;
			nMinute = ((nTime2 - nTime1) - nHour*3600) / 60;
		}else
		{
			nHour = (86400 + nTime2 - nTime1) / 3600;
			nMinute = (86400 + nTime2 - nTime1 - nHour*3600) / 60;
		}

		nAnswer = 0;

		nAnswer += nHour *1200;
		nAnswer += nMinute *20;
		for(i = nS1; i <= 59 ; ++i) {
			if((temp1+i)%3==0) {
				nAnswer++;
			}
		}
		for(i = 0; i <= nS2 ; ++i) {
			if((temp2+i)%3==0) {
				nAnswer++;
			}
		}
		if(nS1 < nS2) {
			nAnswer -= 20;
		}
		

		/*	
		if(nS1 < nS2)
			nAnswer += (nS2 - nS1)/3;
		else
		{
			nAnswer += (60+nS1 - nS2) / 3;
		}
	*/	
		cout << nAnswer << endl;	
	}
    
	return 0;
}

