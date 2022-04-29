#include <iostream>
using namespace std;
int cal(int h, int m, int s){
	return h*10000 + m*100 + s;
}
int main(){
	int test_case, h1, m1, s1, h2, m2, s2;
	char ch;
	cin >> test_case;
	while(test_case--){
		int fir=0, sec=0, cnt=0;
		bool flag=true;
		cin >> h1 >> ch >> m1 >> ch >> s1;
		cin >> h2 >> ch >> m2 >> ch >> s2;
		fir = cal(h1,m1,s1);
		sec = cal(h2,m2,s2);
			while(flag){
				if(fir%3 == 0)
					cnt++;
				s1++;
				if(s1 == 60){
					s1=0; m1++;
					if(m1 == 60){
						m1=0; h1++;
						if(h1 == 24){
							h1=0;
						}
					}
				}
				fir = cal(h1,m1,s1);			
				if(fir == sec)
					flag=false;
			}
		cout << cnt << endl;
	}

}
