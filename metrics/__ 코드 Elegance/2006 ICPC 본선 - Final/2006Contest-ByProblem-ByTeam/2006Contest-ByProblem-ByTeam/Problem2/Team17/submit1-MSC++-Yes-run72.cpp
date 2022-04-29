#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	int M, N;
	const string ord = "ACGT";
	int ord_err[4];
	string d[50];

	cin >> T;
	while(T-->0) {
		cin >> N >> M;
		for(int i=0;i<N;++i) cin >> d[i];

		string res;
		int err = 0;
		for(int i=0;i<M;++i) {
			for(int j=0;j<4;++j) {
				ord_err[j] = 0;
				for(int k=0;k<N;++k) {
					if(ord[j]!=d[k][i]) {
						++ord_err[j];
					}
				}
			}
			int mp = 0;
			for(int j=1;j<4;++j) {
				if(ord_err[mp]>ord_err[j]) mp = j;
			}
			res += ord[mp];
			err += ord_err[mp];
		}
		cout << res << endl;
		cout << err << endl;
	}
}