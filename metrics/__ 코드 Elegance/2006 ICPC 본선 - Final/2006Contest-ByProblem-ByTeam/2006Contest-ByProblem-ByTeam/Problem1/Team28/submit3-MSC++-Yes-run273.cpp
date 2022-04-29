#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

void main()
{
	int i,j,k,t,hh1,mm1,ss1,hh2,mm2,ss2,n1,n2,res,flag,flag2;
	char col,snum1,snum2;
	int c1,c2;

	cin>>t;
	while(t--)
	{
		cin >> hh1 >> col >> mm1 >> col >> ss1 >> hh2 >> col >> mm2 >> col >> ss2;

		c1=(hh1*60+mm1)*20;//+ss1/3;
		c2=(hh2*60+mm2)*20;//+ss2/3;

		for(i=0;i<ss1;i++){
			if((hh1*10000+mm1*100+i)%3==0) c1++;
		}
		for(i=0;i<=ss2;i++){
			if((hh2*10000+mm2*100+i)%3==0) c2++;
		}

		if((hh1*10000+mm1*100+ss1)>(hh2*10000+mm2*100+ss2)) c2+=28800;
		//if((hh1*10000+mm1*100+ss1)%3==0) c1--;
		//if((hh2*10000+mm2*100+ss2)%3==0) c2--;
		//cout<<c1<<" || "<<c2<<endl;
        cout<<c2-c1<<endl;		
	}
}

/*
void main(){

	int i,j,k,t,hh1,mm1,ss1,hh2,mm2,ss2,n1,n2,res,flag,flag2;
	char col,snum1,snum2;
	int c1,c2;

	cin>>t;
	while(t--)
	{
		cin >> hh1 >> col >> mm1 >> col >> ss1 >> hh2 >> col >> mm2 >> col >> ss2;
		flag=flag2=0;
		//n1=(hh1*60+mm1)*20+ss1/3;
		//if((hh1*10000+mm1*100)%3==0 && (hh1*10000+mm1*100)!=0) n1++;
		//if((hh1*10000+mm1*100+ss1)%3==0) n1--;
		
		//n2=(hh2*60+mm2)*20+ss2/3;
		//if((hh2*10000+mm2*100)%3==0) n2++;
		//if(hh1>hh2) n2+=28801;
		if((hh2*10000+mm2*100+ss2)==0) flag2=1;
		if((hh1*10000+mm1*100+ss1)>(hh2*10000+mm2*100+ss2)) hh2+=24,flag=1;
		res=((hh2-hh1)*60+(mm2-mm1))*20;
		if(ss1>ss2) res-=20,ss2+=60;
		res+=((ss2-ss1)/3);
		if((hh1*10000+mm1*100+ss1)%3==0 && (hh1*10000+mm1*100+ss1)!=0) res++;
		if((hh2*10000+mm2*100+ss2)%3==0 && (hh2*10000+mm2*100+ss2)!=0) res++;
		if(flag && !flag2)
		{
			res--;
		}
		//cout<<n1<<" "<<n2<<endl;
		cout<<res<<endl;
	}
}
*/