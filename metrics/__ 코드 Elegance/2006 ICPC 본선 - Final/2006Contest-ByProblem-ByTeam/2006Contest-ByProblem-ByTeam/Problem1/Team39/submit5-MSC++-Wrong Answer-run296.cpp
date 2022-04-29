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

	int t1sec =  s + m*60 + h*3600;

	h = atoi(h2);
	m = atoi(m2);
	s = atoi(s2);

	t2 += s;
	t2 += (m*100);
	t2 += (h*10000);

	int t2sec =  s + m*60 + h*3600;
	
	
	if(t1sec > t2sec)
	{
		t2sec+= 60*60*24-1;
	}

	for(int aa = t1sec ; aa <= t2sec ; aa++)
	{
		if(aa%3 == 0)
			val++;
	}
	return val;

	


	int temp = 0;
	if(t1sec%3!=0)
	{
		temp = 3- (t1sec%3);
	}

	t1sec+=temp;

	temp = 0;
	if(t2sec%3!=0)
	{
		temp = (t2sec%3);
	}

	t2sec-=temp;


	int diff = t2sec - t1sec;
	int value = diff /3;
	return value+1;


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