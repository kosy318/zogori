#include<iostream>
#include<string>
using namespace std;

int hour;
int _min;
int sec;

int get_time(){
	sec++;
	if(sec==60){
		sec=0;
		_min++;
		if(_min==60){
			_min=0;
			hour++;
			if(hour==24){
				hour=0;
			}
		}
	}
	return hour*10000+_min*100+sec;


}

int main(){
	int N;
	cin>>N;
	for(int ca=0;ca<N;ca++){
		string ss1,ss2;
		cin>>ss1>>ss2;
		int h1,m1,s1,h2,m2,s2;
		h1=(ss1[0]-'0')*10+(ss1[1]-'0');
		m1=(ss1[3]-'0')*10+(ss1[4]-'0');
		s1=(ss1[6]-'0')*10+(ss1[7]-'0');
		//cout<<h1<<" "<<m1<<" "<<s1<<endl;
		h2=(ss2[0]-'0')*10+(ss2[1]-'0');
		m2=(ss2[3]-'0')*10+(ss2[4]-'0');
	        s2=(ss2[6]-'0')*10+(ss2[7]-'0');
		//cout<<h2<<" "<<m2<<" "<<s2<<endl;		
		hour=h1;
		_min=m1;
		sec=s1;
		int ans=0;
		if((hour*10000+_min*100+sec)%3==0)ans++;
		while(true){
			if(get_time()%3==0)ans++;	
			if(hour==h2&&_min==m2&&sec==s2)break;

		}
		cout<<ans<<endl;
	}

	return 0;
}
