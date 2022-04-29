#include <iostream>
#define day 3600*24
using namespace std;
int stime, smin, ssec;
int ftime, fmin, fsec;

void input(){
	cin >> stime;
	cin.get();
	cin >> smin;
	cin.get();
	cin >> ssec;
	cin.get();
	cin >> ftime;
	cin.get();
	cin >> fmin;
	cin.get();
	cin >> fsec;
}
int main(){
	int s;
	long sall, fall, interval;
    cin >> s;

	while(s--)
	{
		stime = ftime = 0;
		input();
		sall = stime * 3600 + smin * 60 + ssec;
		fall = ftime * 3600 + fmin * 60 + fsec;
		if(sall > fall){
			interval = fall + day - sall;
		}
		else
			interval = fall - sall;
		if(interval != 0 && interval % 3 != 0)
			cout << interval/3 + 1 << endl;
		else if(interval == 0)
			cout<<0<<endl;
		else
			cout << interval /3<< endl;
		
	}
	
	return 1;
}