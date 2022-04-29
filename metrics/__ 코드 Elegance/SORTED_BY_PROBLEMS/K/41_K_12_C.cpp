#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll r[111], g[111], b[111];
pair<double, pair<ll, pair<ll, ll> > > V[111];
ll Prs[111], Pgs[111], Pbs[111];
ll Pr[111], Pg[111], Pb[111];
double ans=1e18;
ll n, k;

double trial(double R, double G, double B)
{
	int i, j; double ret=1e18;
	for(i=1 ; i<=n ; i++) V[i]=make_pair(R*r[i]+G*g[i]+B*b[i], make_pair(r[i], make_pair(g[i], b[i])));
	sort(V+1, V+n+1);
	Prs[1]=V[1].second.first*V[1].second.first;
	Pr[1]=V[1].second.first;
	Pgs[1]=V[1].second.second.first*V[1].second.second.first;
	Pg[1]=V[1].second.second.first;
	Pbs[1]=V[1].second.second.second*V[1].second.second.second;
	Pb[1]=V[1].second.second.second;
	for(i=2 ; i<=n ; i++)
	{
		Prs[i]=Prs[i-1]+V[i].second.first*V[i].second.first;
		Pr[i]=Pr[i-1]+V[i].second.first;
		Pgs[i]=Pgs[i-1]+V[i].second.second.first*V[i].second.second.first;
		Pg[i]=Pg[i-1]+V[i].second.second.first;
		Pbs[i]=Pbs[i-1]+V[i].second.second.second*V[i].second.second.second;
		Pb[i]=Pb[i-1]+V[i].second.second.second;
	}
	for(i=1 ; i<=n ; i++)
	{
		double vv=Prs[i]+Pgs[i]+Pbs[i]-1.0*(Pr[i]*Pr[i]+Pg[i]*Pg[i]+Pb[i]*Pb[i])/i;
		if(i!=n) vv+=(Prs[n]+Pgs[n]+Pbs[n]-Prs[i]-Pgs[i]-Pbs[i])-1.0*((Pr[n]-Pr[i])*(Pr[n]-Pr[i])+(Pg[n]-Pg[i])*(Pg[n]-Pg[i])+(Pb[n]-Pb[i])*(Pb[n]-Pb[i]))/(n-i);
		ret=min(ret, vv);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k; ll i, j;
	if(n<=k) { cout<<fixed<<setprecision(6)<<0.0; return 0; }
	for(i=1 ; i<=n ; i++) cin>>r[i]>>g[i]>>b[i];
	if(k==1)
	{
		double mr=0, mg=0, mb=0; ans=0;
		for(i=1 ; i<=n ; i++) mr+=r[i]; mr/=n;
		for(i=1 ; i<=n ; i++) mg+=g[i]; mg/=n;
		for(i=1 ; i<=n ; i++) mb+=b[i]; mb/=n;
		for(i=1 ; i<=n ; i++) ans+=(r[i]-mr)*(r[i]-mr)+(g[i]-mg)*(g[i]-mg)+(b[i]-mb)*(b[i]-mb);
		cout<<fixed<<setprecision(6)<<ans;
		return 0;
	}
	for(i=1 ; i<=n ; i++)
		for(j=i+1 ; j<=n ; j++)
			ans=min(ans, trial(r[j]-r[i], g[j]-g[i], b[j]-b[i]));
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
