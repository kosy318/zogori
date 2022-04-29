#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int GetValue(char * str1, char * str2)
{
	int val = 0;
	char h1[9],m1[9],s1[9],h2[9],m2[9],s2[9];
	int nh1,nm1,ns1,nh2,nm2,ns2;
	int t1 = 0, t2 = 0;

	h1[0] = str1[0];
	h1[1] = str1[1];
	h1[3] = '\0';

	h2[0] = str2[0];
	h2[1] = str2[1];
	h2[3] = '\0';

	m1[0] = str1[3];
	m1[1] = str1[4];
	m1[3] = '\0';

	m2[0] = str2[3];
	m2[1] = str2[4];
	m2[3] = '\0';

	s1[0] = str1[6];
	s1[1] = str1[7];
	s1[3] = '\0';

	s2[0] = str2[6];
	s2[1] = str2[7];
	s2[3] = '\0';

	nh2 = atoi(h2);
	nm2 = atoi(m2);
	ns2 = atoi(s2);

	t2 += ns2;
	t2 += (nm2*100);
	t2 += (nh2*10000);

	nh1 = atoi(h1);
	nm1 = atoi(m1);
	ns1 = atoi(s1);

	t1 += ns1;
	t1 += (nm1*100);
	t1 += (nh1*10000);
	
	if(t1 > t2)
	{
		t2+=240000;
		nh2 += 24;
	}


	while(1)
	{
		if(t1 == t2)
		{
			break;
		}
		if(t1 %3 == 0)
			val++;

		ns1++;
		t1++;

		if(ns1==60)
		{
			nm1++;
			ns1=0;

			if(nm1==60)
			{
				nh1++;
				nm1=0;
			}
			t1 = 0;
			t1 += ns1;
			t1 += (nm1*100);
			t1 += (nh1*10000);
	
		}
	

	}


	return val;
	/*

	if(ns1>ns2)
	{
		if(nm2==0)
		{
			nh2--;
			nm2+=60;
		}
		nm2--;
		
		ns2+=60;
	}
	
	if(nm1>nm2)
	{
		nh2--;
		nm2+=60;
	}

	int hdiff  = nh2-nh1;
	int mdiff  = nm2-nm1;

	int h3 = hdiff * 1140;
	int m3 = mdiff * 19;

	for(int i = ns1 ; i <= ns2 ; i++)
	{
		if(i%3 == 0)
			val++;
	}

	return val + h3 + m3;
	*/



	







/*
	int temp = 0;
	if(t1%3!=0)
	{
		temp = 3-(t1%3);
	}
	t1 += temp;
	ns1 += temp;

	if(ns1+temp >=60)
	{
		nm1++;
		ns1 -= 60; 
		if(nm1 >= 60)
		{
			nh1++;
			nm1 = 0;
		}
		t1 = 0;
		t1 += ns1;
		t1 += (nm1*100);
		t1 += (nh1*10000);
	}

	temp = 0;
	if(t2%3!=0)
	{
		temp = 3-(t2%3);
	}
	t2 += temp;
	ns2 += temp;

	if(ns2+temp >=60)
	{
		nm2++;
		ns2 -= 60; 
		if(nm2 >= 60)
		{
			nh2++;
			nm2 = 0;
		}
		t2 = 0;
		t2 += ns2;
		t2 += (nm2*100);
		t2 += (nh2*10000);
	}


	int t1sec = ns1 + nm1*60 + nh1*3600;
	int t2sec = ns2 + nm2*60 + nh2*3600;


	for(int i = t1sec ; i <= t2sec ; i++)
	{
		if(i%3==0)
			val++;
	}
	return val;
*/


	
	
	
	
	

}

int main()
{
	int nQues;
	cin >> nQues;
	char str1[100];
	char str2[100];
	for(int Ques = 0 ; Ques < nQues ; Ques++)
	{
		str1[0] = '\0';
		str2[0] = '\0';
		cin >> str1 >> str2;

		cout << GetValue(str1, str2) << endl;

	}
	return 0;
}