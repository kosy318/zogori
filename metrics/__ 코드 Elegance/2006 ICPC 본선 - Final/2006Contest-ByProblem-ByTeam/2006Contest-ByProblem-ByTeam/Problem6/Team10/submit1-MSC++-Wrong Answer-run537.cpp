
#include <iostream>
using namespace std;
struct tag_tube
{
	long a, b;
	long x;
}tube[20];

long anums[20];
int anums_cnt;


long gcd(long p, long q)
{
	long g;
	if(q>p)
		return gcd(q,p);
	if(q==0)
		return p;

	return gcd(q,p%q);
}

long lcm(long p, long q)
{
	return p*q/gcd(p,q);
}
int main(){
	int s,i, t_num;
	long temp, m, sumb, sumx;
	cin >> s;
	
	while(s--)
	{
		cin>>t_num;
		sumb=sumx=0;
		for(i=0;i<t_num;i++)
		{
			cin>>tube[i].a;
			cin>>tube[i].b;			
		}
		temp=tube[0].a;
		for(i=1;i<t_num;i++)
			temp=lcm(temp,tube[i].a);
		cin>>m;
		for(i=0;i<t_num;i++)
		{
			tube[i].x=temp/tube[i].a;
			tube[i].b*=tube[i].x;
			sumb+=tube[i].b;
			sumx+=tube[i].x;
		}
		m*=temp;
		m+=sumb;

		if(m%sumx==0)
			cout<<m/sumx<<endl;
		else
			cout<<0 << endl;
	}


			
	return 1;
}
