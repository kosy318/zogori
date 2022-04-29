#include <bits/stdc++.h>
#define L long long

using namespace std;

L f(L x){
	if(x==2) return -1;
	if(x==3) return 0;
	return f((x+1)/2)+2;
}

int main()
{
	L n;
	cin>>n;
	cout<<f(n);
}
