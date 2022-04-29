#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int result[4], T, m, n;
vector<string> data;
string res;

int dist(string a, string b) {
	int ct=0;
	for(int i=0;i<n;i++) {
		if(a[i] != b[i]) ct++;
	}
	return ct;
}

int main(void) {
	int max_v, max_i, dap;
	cin >> T;
	while(T--) {
		dap = 0;
		res.clear();
		cin >> m >> n;
		data.clear();
		data.resize(m);
		for(int i=0;i<m;i++) {
			cin >> data[i];
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<4;j++) result[j] = 0;
			for(int j=0;j<m;j++) {
				if(data[j][i] == 'A') result[0]++;
				else if(data[j][i] == 'G') result[1]++;
				else if(data[j][i] == 'C') result[2]++;
				else if(data[j][i] == 'T') result[3]++;
			}
			max_v = result[0];
			max_i = 0;
			for(int j=1;j<4;j++) {
				if(max_v < result[j]) {
					max_v = result[j];
					max_i = j;
				}
			}
			if(max_i == 0) res.push_back('A');
			else if(max_i == 1) res.push_back('G');
			else if(max_i == 2) res.push_back('C');
			else if(max_i == 3) res.push_back('T');
		}
		for(int i=0;i<m;i++) {
			dap = dap + dist(data[i], res);
		}
		cout << res << endl << dap << endl;
	}
	return 0;
}