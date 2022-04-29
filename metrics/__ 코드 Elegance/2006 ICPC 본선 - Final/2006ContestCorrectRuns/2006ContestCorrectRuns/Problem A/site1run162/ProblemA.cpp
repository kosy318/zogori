#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int change (char *a)
{
	return (a[0]-48)*10+(a[1]-48);
}

int change2(int h1,int h2,int h3)
{
	return h1*10000+h2*100+h3;
}

int main() {
	int N;
	cin >> N;
	int hh1,hh2,mm1,mm2,ss1,ss2;
	int out[10000];
	for(int count = 0; count < N; count ++) {
		char time[60] = "";
		char time2[18] = "";
		char h1[3], h2[3], m1[3], m2[3], s1[3], s2[3];
		cin >> time >> time2;
		strcat(time," ");
		strcat(time,time2);
		h1[0]=time[0];
		h1[1]=time[1];
		m1[0]=time[3];
		m1[1]=time[4];
		s1[0]=time[6];
		s1[1]=time[7];
		h2[0]=time[9];
		h2[1]=time[10];
		m2[0]=time[12];
		m2[1]=time[13];
		s2[0]=time[15];
		s2[1]=time[16];
		hh1=change(h1);
		hh2=change(h2);
		mm1=change(m1);
		mm2=change(m2);
		ss1=change(s1);
		ss2=change(s2);
		int cnt=0;
		
		for ( ; ; ){

			//cout << change2(hh1,mm1,ss1) << " ";
			if (change2(hh1,mm1,ss1)==(change2(hh2,mm2,ss2))){
				if (change2(hh1,mm1,ss1)%3==0) cnt++;
				break;
			}
			if (change2(hh1,mm1,ss1)%3==0) cnt++;
			ss1++;
			if (ss1==60) {ss1=0;mm1++;};
			if (mm1==60) {mm1=0;hh1++;};
			if (hh1==24) {hh1=0;}
		}
		out[count]=cnt;
	}
	for(int count = 0; count < N; count ++) {
		cout << out[count] << endl;
	}
	return 0;
}