#include <bits/stdc++.h>
#define L long long

using namespace std;

L g(L x){
	if(x<=3)
		return 1;
	return 1+g((x+1)/2);
}

int main()
{
	L n;
	cin>>n;
	if(n<6) cout<<(n-2)/2;
	else cout<<g((n-1)/3+2);
}
