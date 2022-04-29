#include <bits/stdc++.h>

using namespace std;

long long dp[15005];
long long until_now[15205];
int m,n;
long long cost[105];
vector<pair<long long,pair<long long,long long> > > v;

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
        scanf("%lld",&cost[i]);
    for(int i=0;i<n;i++){
        long long s,e,t;
        scanf("%lld%lld%lld",&s,&e,&t);
        v.push_back(make_pair(e,make_pair(s,(e-s)*cost[t-1] )));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        long long temp=v[i].first;
        v[i].first=v[i].second.first;
        v[i].second.first=temp;
    }

    //for(int i=0;i<v.size();i++){
      //  printf("%lld %lld %lld\n",v[i].first,v[i].second.first,v[i].second.second);
   // }
   // printf("\n\n");
    int watching=0;
    for(int i=1;i<15100;i++){
        until_now[i]=until_now[i-1];
        while(v[watching].second.first==i){
            until_now[i]=max(until_now[i],until_now[v[watching].first]+v[watching].second.second);
            watching++;
        }
    }
    return !printf("%lld",until_now[15009]);
    for(int i=1;i<15;i++)
        printf("%d %lld\n",i,until_now[i]);
}

