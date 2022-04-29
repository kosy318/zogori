#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	for(int count = 0; count < N; count ++) {
		int m, n;
		char seq[51][1010];
		char ans[1010];
		int cnt = 0;
		cin >> m >> n;
		for(int i=0; i<m; i++)
			cin >> seq[i];

		for(int i=0; i<n; i++) {
			int sw = 0;
			for(int j=1; j<m; j++)
				if(seq[0][i] != seq[j][i]) sw = 1;
			if(sw==0) {
				ans[i] = seq[0][i];
				continue;
			}
			



			char now, nowmax;
			int min = 10000;



			// Additional case...
			sw = 0; now = 'A';
			for(int j=0; j<m; j++) if(seq[j][i] != now) sw++;
			if(sw<min) { min = sw; nowmax = now; }

			sw = 0; now = 'C';
			for(int j=0; j<m; j++) if(seq[j][i] != now) sw++;
			if(sw<min) { min = sw; nowmax = now; }


			sw = 0; now = 'G';
			for(int j=0; j<m; j++) if(seq[j][i] != now) sw++;
			if(sw<min) { min = sw; nowmax = now; }

			sw = 0; now = 'T';
			for(int j=0; j<m; j++) if(seq[j][i] != now) sw++;
			if(sw<min) { min = sw; nowmax = now; }

			ans[i] = nowmax;
			cnt += min;
		}

		ans[n] = '\0';
		cout << ans << endl << cnt << endl;
	}
}