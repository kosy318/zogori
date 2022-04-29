#include<bits/stdc++.h>
using namespace std;
int n;
pair<long long,long long> p[100010];
int f(long long d){
    long long l=p[0].first+d;
    for(int i=1; i<n; i++){
        if(l<=p[i].second){
            l=max(p[i].first,l)+d;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%lld%lld",&p[i].first,&p[i].second), p[i].second+=p[i].first;
    sort(p,p+n);
    long long low=0, up=2e9+10,mid, ans = 2e9+10;
    while(low<=up){
        mid = (low+up)/2;
        if(f(mid)){
            low=mid+1;
            ans = mid;
        }else up=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}
