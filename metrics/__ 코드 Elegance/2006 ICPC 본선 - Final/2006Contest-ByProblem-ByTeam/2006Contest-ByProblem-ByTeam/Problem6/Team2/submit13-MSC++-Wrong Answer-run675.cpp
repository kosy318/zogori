#include <iostream>
#include <fstream>
#include <cassert>
#include <algorithm>
using namespace std;

typedef struct __fc {
	int ai; int bi;
} fc;

fc funct[20];
int M;
int nfc;
int nm;

class sf{
public:
	bool operator()(fc x, fc y) 
	{
		return x.ai > y.ai;
	}
};

class f {
public:
	void Run() {
//		ifstream cin("input.txt");
		int ncase;
		int i, j;
		cin >> ncase;
		for(i = 0; i < ncase; i++) {
			cin >> nfc;
			for(j = 0; j < nfc; j++) {
				cin >> funct[j].ai >> funct[j].bi;
			}
			cin >> M;
			if(Proc())
				cout << nm << endl;
			else
				cout << 0 << endl;
		}
	}
	bool Proc();

private:

};

inline bool f::Proc()
{
	int total;
	int i, j;
	bool flag;
	int st, add;
	sort(&(funct[0]), &(funct[1]), sf());
	st = funct[0].bi;
	add = funct[0].ai;
	for(i = st; i <= 101000; i+= add) {
		total = 0;
		flag = true;
		for(j = 0; j < nfc; j++) {
			if( (i-funct[j].bi <= 0) ||  (i-funct[j].bi) % funct[j].ai != 0) {
				flag = false;
				break;
			}
		}
		if(flag == true) {
			for(j = 0; j < nfc; j++) {
				total += (i - funct[j].bi) / funct[j].ai;
			}
			if(total == M) {
				nm = i;
				return true;
			}
		}
	}
	return false;
}


int main(void)
{
	f fc;
//	fc.Test();
	fc.Run();

	return 0;
}
	