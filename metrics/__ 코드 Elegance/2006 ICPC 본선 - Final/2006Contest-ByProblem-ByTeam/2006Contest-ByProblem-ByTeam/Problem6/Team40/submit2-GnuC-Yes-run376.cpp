#include <iostream>

using namespace std;

int main() {
	int test_c;
	
	cin >> test_c;

	while(test_c--) {
		int pair[20][2];
		int tubes;
		int gases;
		bool flag=true;
		memset(pair, 0, sizeof(pair));
		
		cin >> tubes;
		for(int i=0; i<tubes; i++)
			cin >> pair[i][0] >> pair[i][1];
		cin >> gases;

		//for(int i=1; i<gases-(tubes-1); i++) {
		for(int i=1; i<gases; i++) {
			int weight=i*pair[0][0]+pair[0][1];
			int total_weight=i;

			for(int j=1; j<tubes; j++) {
				if((weight-pair[j][1])%pair[j][0] != 0)
					break;
				if(weight-pair[j][1] < 0)
					break;
				int next_weight	= (weight-pair[j][1])/pair[j][0];
				total_weight+=next_weight;
			}
			if(gases == total_weight) {
				cout << weight << endl;
				flag=false;
				break;
			}
		}
		if(flag)
			cout << "0" << endl;
	}

	return 0;
}
