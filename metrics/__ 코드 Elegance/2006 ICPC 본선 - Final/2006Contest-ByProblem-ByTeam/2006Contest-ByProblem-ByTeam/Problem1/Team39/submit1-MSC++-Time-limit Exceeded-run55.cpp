#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int GetValue(char * str1, char * str2)
{
	int val = 0;
	char h1[9],m1[9],s1[9],h2[9],m2[9],s2[9];
	int h,m,s;
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

	h = atoi(h1);
	m = atoi(m1);
	s = atoi(s1);

	t1 += s;
	t1 += (m*100);
	t1 += (h*10000);

	h = atoi(h2);
	m = atoi(m2);
	s = atoi(s2);

	t2 += s;
	t2 += (m*100);
	t2 += (h*10000);

	h = atoi(h1);
	m = atoi(m1);
	s = atoi(s1);

	int tt = t1;

	while(1)
	{
		tt = 0;

		tt += s;
		tt += (m*100);
		tt += (h*10000);

		if(tt%3==0)
			val++;

		if(tt == t2)
			break;

		s++;
		if(s==60)
		{s = 0; m++;}
		if(m==60)
		{m = 0 ; h++;}
		if(h==24)
		{
			h=0;
		}

		
		

	}


	return val;
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