#include <bits/stdc++.h>

using namespace std;


vector<pair<long long,long long> > v;
long long start[100005];
long long len[100005];
int n;

int decis(long long mid){
    long long left=start[0];

    for(int i=1;i<n;i++){
        if(start[i]<=left+mid && left+mid<=start[i]+len[i])
            left=left+mid;
        else if(left+mid<start[i])
            left=start[i];
        else return 0;
    }
    return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        v.push_back(make_pair(l,r));
	}
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        start[i]=v[i].first;
        len[i]=v[i].second;
    }

    long long low=0;
    long long high=2100000001;
    while(low+1<high){
        long long mid=(low+high)/2;
        if(decis(mid)) low = mid;
        else{
            high = mid;
        }
    }
    printf("%lld",low);

}
