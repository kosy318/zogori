#include <iostream>

using namespace std;

int a[20];
int b[20];
int LCM;
int G;
int t;
int M;
int n;
int cases;
int module;

int getLCM(){
	bool check;

	for(int i = 1; i <= 1260; i++){
		check = true;

		for(int j = 0; j < n; j++){
			if(i % a[j] != 0) check = false;
		}

		if(check) return i;
	}

	return 2520;
}

int getG(){
	bool check;

	for(int i = 0; i < LCM; i++){
		check = true;

		for(int j = 0; j < n; j++){
			if(i % a[j] != b[j] % a[j]) check = false;
		}

		if(check) return i;
	}

	return -1;
}

int getmodule(){
	module = 0;

	for(int i = 0; i < n; i++){
		module += LCM / a[i];
	}

	return module;
}

int getM(int g){
	int m = 0;

	for(int i = 0; i < n; i++){
//		if(g < b[i]) return 0;
		m += (g-b[i])/a[i];
	}

	return m;
}

int main(){
	cin >> cases;

	for(int asdf = 0; asdf < cases; asdf++){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
		}
		cin >> M;

		LCM = getLCM();
		getmodule();

//		cout << "module : " << module << endl;

/*		cout << "LCM : " << LCM << endl;
		cout << "a[i] : ";
		for(int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << endl;  */

		G = getG();
//		cout << "G : " << G << endl;

		if(G < 0) {
//			cout << "out " << endl;
			cout << '0' << endl;
		}
		else{
/*			t = 0;
			G -= LCM;
			while(t < M){
				G += LCM;
				t = getM(G);
				cout << t << endl;
			}
			if(t == M) cout << G << endl;
			else cout << '0' << endl;
*/

			t = getM(G);
			t %= module;
			if(t < 0) t += module;
//			cout << " t : " << t << endl;
			if(M % module != t) cout << '0' << endl;
			else{
				G = G + LCM*(M - getM(G))/module;

				if(G <= 0) cout << '0' << endl;
				else cout << G << endl;
			}
		}
	}
}