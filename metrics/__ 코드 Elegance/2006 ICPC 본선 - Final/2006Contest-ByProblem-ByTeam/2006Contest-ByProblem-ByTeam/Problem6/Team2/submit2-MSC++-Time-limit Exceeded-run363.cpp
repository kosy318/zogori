#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

typedef struct __fc {
	int ai; int bi;
} fc;

fc funct[20];
int M;
int nfc;
int nm;

class f {
public:
	void Run() {
		ifstream cin("input.txt");
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
	int GetFc(int xi, int idx);
	int FindNum(int val, int idx);
	void Test();

private:

};

inline int f::GetFc(int xi, int idx)
{
	return funct[idx].ai * xi + funct[idx].bi;
}


inline bool f::Proc() 
{
	int i, j;
	int valXi[20];			// each xi
	int sumXi;

	for(i = 0; i < M; i++) {
		valXi[0] = i;
		nm = GetFc(i, 0);			// first Function
		for(j = 0; j < nfc; j++) {				// other function
			if( (valXi[j] = FindNum(nm, j)) == -1)
				break;
		}
		if(j == nfc) {
			sumXi = 0;
			for(j = 0; j < nfc; j++) {
				sumXi += valXi[j]; 
			}
			if(sumXi == M) {
				return true;
			}
		}
	}
	return false;
}

inline int f::FindNum(int val, int idx)
{
	int i, temp;
	temp = 0;
	i = 0;
	while(temp < val) {
		if ( i == M )
			break;
		i++;
		temp = GetFc(i, idx);
	}
	if(temp == val) {
		return i;
	} else 
		return -1;
}


inline void f::Test()
	{
		M = 10;
		funct[0].ai = 4;
		funct[0].bi = 10;
		assert(GetFc(3, 0) == 22);
		assert(FindNum(23, 0) == -1);
		assert(FindNum(22, 0) == 3);

		return;
	}

int main(void)
{
	f fc;
	//fc.Test();
	fc.Run();

	return 0;
}
	