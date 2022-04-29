#include <iostream>
#include <vector>
using namespace std;
typedef struct ss{
	int id;
	int du;
}s;

vector<s> ji;
vector<s> yo;
vector<int> sche1;
vector<int> sche2;
int tray[50] = {false};
void input_w(int n){
	s tmp;
	int i;
	for(i = 1; i <= n; i++){
		tmp.id = i;
		cin >> tmp.du;
		ji.push_back(tmp);
	}
	for(i = 1; i <= n; i++){
		tmp.id = i;
		cin >> tmp.du;
		yo.push_back(tmp);
	}
}
void input_t(int t1, int t2){
	int i, tmp;
	for(i = 0; i < t1; i++){
		cin >> tmp;
		sche1.push_back(tmp);
	}
	for(i = 0; i < t2; i++){
		cin >> tmp;
		sche2.push_back(tmp);
	}
}
void init(){
	int i;
	for(i = 0; i < 50; i++)
		tray[i] = false;
	ji.clear();
	yo.clear();
	sche1.clear();
	sche2.clear();

}
void print(){
	int i;
	for(i = 0; i < ji.size(); i++)
		cout << ji[i].id << " " << ji[i].du << endl;
	cout << endl;
	for(i = 0; i < yo.size(); i++)
		cout << yo[i].id << " " << yo[i].du << endl;

	cout << endl;
	for(i = 0; i < sche1.size(); i++)
		cout << sche1[i];
	cout << endl;
	for(i = 0; i < sche2.size(); i++)
		cout << sche2[i];
	cout << endl;

}
int produce(int tray1, int tray2){
	bool flag1 = false, flag2 = false; // while ended time
	bool use1 = false, use2 = false;
	int time = 0;			//iterator
	int rt1 = 0, rt2 = 0;		//save end time
	int ntray1 = 0 , ntray2 = 0;
	int i;
	while(flag1 == false || flag2 == false){
		
		if(time){
			if(time == rt1){
				tray[sche1[ntray1++]] = false;
				use1 = false;
				if(ntray1 == tray1)
					flag1 = true;
			}
			if(time == rt2){
				tray[sche2[ntray2++]] = false;
				use2 = false;
				if(ntray2 == tray2)
					flag2 = true;
			}
		}
		
		if(flag2 == false && flag2 == false)
		{
            if(sche1[ntray1] == sche2[ntray2])
			{
                if(ji[sche1[ntray1]-1].du <= yo[sche2[ntray2]-1].du){
					if(use1 == false && tray[sche1[ntray1]] == false){
						tray[sche1[ntray1]] = true;
						rt1 = time + ji[sche1[ntray1]-1].du;
						use1 = true;
					}
				}
				else{
					if(use2 == false&& tray[sche2[ntray2]] == false){
						tray[sche2[ntray2]] = true;
						rt2 = time + yo[sche1[ntray1]-1].du;
						use2 = true;
					}
				}
			}
			else{
				if(use1 == false && flag1 == false){
					if(tray[sche1[ntray1]] == false){
						tray[sche1[ntray1]] = true;
						rt1 = time + ji[sche1[ntray1]-1].du;
						use1 = true;
					}
				}
				if(use2 == false && flag2 == false){
					if(tray[sche2[ntray2]] == false){
						tray[sche2[ntray2]] = true;
						rt2 = time + yo[sche2[ntray2]-1].du;
						use2 = true;
					}
				}
			}
		}
		else if(flag1 == true){
			for(i = ntray2; i < sche2.size(); i++)
				rt1 += yo[sche2[ntray2]-1].du;
			break;
		}
		else if(flag2 == true){
			for(i = ntray1; i < sche1.size(); i++){
				rt2 += ji[sche1[ntray1]-1].du;			
			}
			break;
		}
		time++;
	}
	if(rt1 > rt2)
		return rt1;
	else
		return rt2;
}

int produce2(int tray1, int tray2){
	bool flag1 = false, flag2 = false; // while ended time
	bool use1 = false, use2 = false;
	int time = 0;			//iterator
	int rt1 = 0, rt2 = 0;		//save end time
	int ntray1 = 0 , ntray2 = 0;
	int i;
	while(flag1 == false || flag2 == false){
		
		if(time){
			if(time == rt1){
				tray[sche1[ntray1++]] = false;
				use1 = false;
				if(ntray1 == tray1)
					flag1 = true;
			}
			if(time == rt2){
				tray[sche2[ntray2++]] = false;
				use2 = false;
				if(ntray2 == tray2)
					flag2 = true;
			}
		}
		
		if(flag2 == false && flag2 == false)
		{
            if(sche1[ntray1] == sche2[ntray2])
			{
                if(ji[sche1[ntray1]-1].du >= yo[sche2[ntray2]-1].du){
					if(use1 == false && tray[sche1[ntray1]] == false){
						tray[sche1[ntray1]] = true;
						rt1 = time + ji[sche1[ntray1]-1].du;
						use1 = true;
					}
				}
				else{
					if(use2 == false&& tray[sche2[ntray2]] == false){
						tray[sche2[ntray2]] = true;
						rt2 = time + yo[sche1[ntray1]-1].du;
						use2 = true;
					}
				}
			}
			else{
				if(use1 == false && flag1 == false){
					if(tray[sche1[ntray1]] == false){
						tray[sche1[ntray1]] = true;
						rt1 = time + ji[sche1[ntray1]-1].du;
						use1 = true;
					}
				}
				if(use2 == false && flag2 == false){
					if(tray[sche2[ntray2]] == false){
						tray[sche2[ntray2]] = true;
						rt2 = time + yo[sche2[ntray2]-1].du;
						use2 = true;
					}
				}
			}
		}
		else if(flag1 == true){
			for(i = ntray2; i < sche2.size(); i++)
				rt1 += yo[sche2[ntray2]-1].du;
			break;
		}
		else if(flag2 == true){
			for(i = ntray1; i < sche1.size(); i++){
				rt2 += ji[sche1[ntray1]-1].du;			
			}
			break;
		}
		time++;
	}
	if(rt1 > rt2)
		return rt1;
	else
		return rt2;
}
int main(){
	int s;
	int n;
	int tray1, tray2;
	int tmp1, tmp2;
	cin >> s;
	while(s--)
	{
		cin >> n;
		init();
		input_w(n);
		cin >> tray1 >> tray2;
		input_t(tray1, tray2);
		tmp1 = produce(tray1, tray2);
		tmp2 = produce2(tray1, tray2);
		if( tmp1 > tmp2)
			cout << tmp2;
		else
			cout << tmp1;
		cout << endl;
		
    }
	return 1;
}