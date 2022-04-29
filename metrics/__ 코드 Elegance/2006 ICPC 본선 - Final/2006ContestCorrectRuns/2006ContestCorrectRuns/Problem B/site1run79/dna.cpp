#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, len;
vector<string> set;
string answer;
int count;

int findMax(int* c) {
	int max = 0;
	for(int i = 1; i < 4; ++i)  
		if ( c[max] < c[i] )
			 max = i;
	return max;
}

void compare() {
	int chr[4];
	answer = "";
	for(int j = 0; j < len; ++j) {
		chr[0] = chr[1] = chr[2] = chr[3] = 0;
		for(int i = 0; i < n; ++i) {
			switch(set[i][j]) {
			case 'A' : chr[0]++; break;
			case 'C' : chr[1]++; break;
			case 'G' : chr[2]++; break;
			case 'T' : chr[3]++; break;
			}			
		}

		int maxI = findMax(chr);

		switch(maxI) {
		case 0 : answer += 'A'; break;
		case 1 : answer += 'C'; break;
		case 2 : answer += 'G'; break;
		case 3 : answer += 'T'; break;
		}		
	}

	count = 0;
	for(int i = 0; i < n; ++i ) 
		for(int j = 0; j < len; ++j)
			if ( answer[j] != set[i][j] )
				count++;
}


int main() {
	int t;

	cin >> t;

	for(int i = 0;i < t; ++i) {
		string in;
		set.clear();

		cin >> n >>len;
		
		for(int j =0; j < n; ++j) {
			cin >> in;
			set.push_back(in);
		}
		compare();

		cout << answer << endl;
		cout << count << endl;

	}

	return 0;
}