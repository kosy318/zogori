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
	else
	{
		vector<L>v;
		v.push_back(g((n-1)/3+2));
		v.push_back(g((n-2)/3+2));
		v.push_back(g((n-3)/3+2));
		sort(v.begin(),v.end());
		cout<<v[1]+v[2];
	}
}
