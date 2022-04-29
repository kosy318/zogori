#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstddef>

using namespace std;

#define FOR(V,I,L) for(int V=(I); V<(L); V++)
#define REP(V,L) FOR(V,0,L)
#define ITER(adt, type) adt<type>::iterator
#define FOR_EACH(I,C) for(I=(C).begin(); I!=(C).end(); ++I)

#define ASSERT(x) ((x)?0:*(int *)0=0)

bool check_integer(double dbl_num);
int _round(double dbl_num);
int make_G(int A, int B, int X);

int A[20], B[20];

int main()
{
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int A_LCM=1;
		REP(i, N) {
			cin >> A[i] >> B[i];
			A_LCM*=A[i];
		}
		int M;
		cin >> M;
		//L_M * G = ~~~
		int L_M=0;
		REP(i, N) {
			L_M+=A_LCM/A[i];
		}
		double R_E;
		R_E= (double)(M*A_LCM);

		REP(i, N) {
			R_E+= B[i]*(A_LCM/A[i]);
		}
		R_E/=(double)L_M;

		double dbl_G=R_E;
		int int_G=_round(dbl_G);
		bool is_exist=true;
		int max_sum=0;
		REP(i, N) {
			double x=(dbl_G-(double)B[i])/(double)A[i];
			max_sum+=_round(x);
			if(check_integer(x)==false) { // check integer
				is_exist=false;
				break;
			}
			else // true
			{	
				int int_x =_round(x);
				if(make_G(A[i], B[i], int_x)!= int_G) {
					is_exist=false;
					break;
				}
			}
		}
		if(is_exist==false)
			R_E=0;
		else {
			if(max_sum!=M)
				R_E=0;
		}
        
		

		cout << _round(R_E) << endl;
	}

	return 0;
}

#define DIFF	0.000000001

int _round(double dbl_num) {
	int close;
	double check=dbl_num-(double)(int)dbl_num;
	if( check>=0.5)
		close=((int)dbl_num)+1;
	else
		close=(int)dbl_num;
	return close;
}

bool check_integer(double dbl_num) {
	int close;
	double check=dbl_num-(double)(int)dbl_num;
	if( check>=0.5)
		close=((int)dbl_num)+1;
	else
		close=(int)dbl_num;

	if(fabs(dbl_num-(double)close) <= DIFF)
		return true;
	else
		return false;
}

int make_G(int A, int B, int X) {
	return (A*X+B);
}