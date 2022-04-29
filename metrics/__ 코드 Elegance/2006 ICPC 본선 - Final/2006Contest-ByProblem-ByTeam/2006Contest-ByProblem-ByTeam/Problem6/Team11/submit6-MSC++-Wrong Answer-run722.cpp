// wf.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

int main(void)
{
	int nLoop, kkkkk, coco;
	unsigned long M;
	int n;
	int arS1[21], arS2[21];
	int index[21], xi, min, count, hap;
	int count1, count2, count3, count4;
	unsigned long arMap[10100][21];

	cin >> nLoop;
	for(count1=0; count1<nLoop; ++count1)
	{
		cin >> n;

		for(count2=0; count2<n; ++count2)
		{
			cin >> arS1[count2] >> arS2[count2];
		}
		if(n<=0) continue;

		for(count2=0; count2<n; ++count2)
		{
			for(count3=1; count3<=10000; ++count3)
			{
				arMap[count3][count2] = arS1[count2] * count3 + arS2[count2];
				if(arMap[count3][count2] >=10000) break;
			}
			arMap[count3+1][count2]=-1;
			index[count2] = 1;
		}
		cin >> M;		
		
		while (true) {
			min = 0;
			count = 0;
			hap = 0;
			coco = 0;
			for(xi = 0; xi < n; ++xi) {
				if(arMap[index[xi]][xi] == -1) {
					cout << 0 << endl;
					coco = 1;
					break;
				}
			}
			if(coco == 1) {
				break;
			}

			for(xi = 0; xi < n; ++xi) {
				if(arMap[index[xi]][xi] < arMap[index[min]][min]) {
					min = xi;
				} else if(arMap[index[xi]][xi] == arMap[index[min]][min]) {
					++count;
				}
			}
			if(count == n) {
				for(xi = 0; xi < n; ++xi) {
					hap += index[xi];
				}
				if(hap == M) {
					cout << arMap[index[min]][min] << endl;
					break;
				}
				for(xi = 0; xi < n; ++xi) {
					index[xi] += 1;
				}
			} else {
				index[min] += 1;
			}
		}
	}
	
	return 0;
}

