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
	int ns1, ns2;

	cin >> nLoop;

	for(nCount=0; nCount<nLoop; ++nCount)
	{
        cin >> strData;

		n11 = ((strData[0]-'0')*10 + (strData[1]-'0'));
		nTime1 = n11*3600;
		n12 = ((strData[3]-'0')*10 + (strData[4]-'0'));
		nTime1 += n12*60;
		ns1 = (strData[6]-'0')*10 + (strData[7]-'0');
 		nTime1 += ns1;

		cin >> strData;
		n21 = ((strData[0]-'0')*10 + (strData[1]-'0'));
		nTime2 = n21*3600;
		n22 = ((strData[3]-'0')*10 + (strData[4]-'0'));
		nTime2 += n22*60;
		ns2 = (strData[6]-'0')*10 + (strData[7]-'0');
		nTime2 += ns2;

		nAnswer = 0;
		while(true) {
			if(ns1 == 60) {
				ns1 -= 60;
				++n12;
			}
			if(n12 == 60) {
				n12 -= 60;
				++n11;
			}
			if(n11 == 24) {
				n11 -= 24;
			}

			if((n11+n12+ns1)%3 == 0) {
				++nAnswer;
			}
			
			if(n11 == n21 && n12 == n22 && ns1 == ns2) {
				break;
			}
			++ns1;

		}

/*
		
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
		for(i = ns1; i <= 59 ; ++i) {
			if((temp1+i)%3==0) {
				nAnswer++;
			}
		}
		for(i = 0; i <= ns2 ; ++i) {
			if((temp2+i)%3==0) {
				nAnswer++;
			}
		}
		if(ns1 < ns2) {
			nAnswer -= 20;
		}
		

/*	
		if(ns1 < ns2)
			nAnswer += (ns2 - ns1)/3;
		else
		{
			nAnswer += (60+ns1 - ns2) / 3;
		}
*/	
		cout << nAnswer << endl;	
	}
    
	return 0;
}

