#include <iostream>
#include <vector>
#include <string>
using namespace std;

char str[50][1000];

int m, n;
char cnt[4];

void init(){
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0 ;
}
void input(int m){
	int i;
	
	for( i =0; i < m; i++){
	cin >> str[i];
	}
}
void print(int *len, int m){
	int i, tmp, ind = 0,ddd;
	bool flag = false;
	tmp = cnt[0];
	for(i = 0; i < 4; i++)
	{
		if(tmp < cnt[i]){
			ind = i;
			tmp = cnt[i];
		}
	}
	for(i = 0; i < 4; i++){
		if(i!= ind && tmp == cnt[i]){
			ddd = i;
			flag = true;
		}
	}
	if(flag){
		for(i = 0; i < 4; i++){
			if(cnt[i] == tmp){
				ind = i;
				break;
			}

		}
	}

	
	for(i =0; i < 4; i++)
	{
		if(ind != i)
			*len = *len + cnt[i];
	}
	
	switch(ind){
		case 0:
			cout << 'A';
			break;
		case 1:
			cout << 'C';
			break;
		case 2:
			cout << 'G';
			break;
		case 3:
			cout << 'T';
			break;

	}

}

void produce(int *len, int n, int m){
	int i, j, tmp;
	char ch;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			switch(str[j][i]){
				case 'A':
					cnt[0]++;
					break;
				case 'C':
					cnt[1]++;
					break;
				case 'G':
					cnt[2]++;
					break;
				case 'T':
					cnt[3]++;
					break;
			}
			if(j == m-1)
				print(len, m);
		}
        
		init();
	}	
}

int main(){
	int s, i, len;
	cin >> s;
	while(s--){
		cin >> m >> n;
		len = 0;
		init();
		
		input(m);

		produce(&len, n, m);
		cout << endl << len << endl;
		
	}

	return 1;
}