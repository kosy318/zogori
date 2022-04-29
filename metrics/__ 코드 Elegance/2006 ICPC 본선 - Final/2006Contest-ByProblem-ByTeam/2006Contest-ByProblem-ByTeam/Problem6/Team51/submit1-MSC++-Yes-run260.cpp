#include <iostream>
using namespace std;

//#include <fstream>
//fstream fin("f.txt");
//#define cin fin

struct myType
{
	double a;
	double b;
};

struct fractionType
{
	double mother;
	double son;
};

void input();
long gcd(long, long);
fractionType fractionCal(fractionType, fractionType);

void main()
{
	input();
}

void input()
{
	int nCase;
	int n;
	double sumM = 0;
	myType myData[25];

	cin >> nCase;
	for (int i = 0; i < nCase; i++)
	{
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> myData[j].a >> myData[j].b;
		}
		cin >> sumM;

		fractionType sumF, d;
		sumF.mother = 1;
		sumF.son = 0;
		fractionType sumA;
		sumA.mother = 1;
		sumA.son = 0;
		double k;
		int temp;

		for (int j = 0; j < n; j++)
		{
			d.mother = myData[j].a;
			d.son = myData[j].b;
			sumF = fractionCal(sumF, d);
			d.son = 1.0;
			sumA = fractionCal(sumA, d);
		}

		d.mother = 1;
		d.son = sumM;
		d = fractionCal(d, sumF);
			//(sumM + (sumF.son / sumF.mother) ) / (sumA.son / sumA.mother);
		k = (d.son * sumA.mother) / (d.mother * sumA.son);

		temp = k/1;
		if ((k - temp) != 0)
		{
			cout << 0 << endl;
		}
		else cout << temp << endl;
	}
}

fractionType fractionCal(fractionType a, fractionType e)
{
	fractionType re;
	long g = 0;

	re.mother = a.mother * e.mother;
	re.son = a.son * e.mother + a.mother * e.son;

	g = gcd(re.mother, re.son);
	if (g)
	{
		re.mother = re.mother / g;
		re.son = re.son / g;
	}
	return re;
}


long gcd(long p, long q)
{
	long g;

	if (q > p)
		return gcd(q, p);
	if (q == 0)
		return p;
	return gcd(q, p % q);
}