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
	int sn,fn;

	while(s--)
	{
		stime = ftime = 0,interval = 0;
		input();
		fn = 10000*ftime + 100*fmin + fsec;
		
		while(1)
		{
			sn = 10000*stime + 100*smin + ssec;
			if(sn == fn)
				break;
			if(sn%3 == 0)
				interval++;
			ssec++;
			if(ssec==60)
			{
				ssec = 0;
				smin++;
			}
			if(smin == 60)
			{
				stime++;
				smin =0;
			}
			if(stime==24)
			{
				stime=0;
				
			}
		}
		
		cout << interval << endl;
		
	}
	
	return 1;
}