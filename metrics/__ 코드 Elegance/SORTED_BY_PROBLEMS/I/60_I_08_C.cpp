#include <bits/stdc++.h>
using namespace std;

long long N;
pair<long long,long long> l[100004];


bool cmp(pair<long long,long long>&a, pair<long long,long long>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main(){
    scanf("%lld", &N);
    for(long long i=1;i<=N;i++){
        scanf("%lld%lld", &l[i].first, &l[i].second);
    }
    sort(l+1, l+N+1, cmp);

    long long ans = 0;
    long long lo = 0, hi = 2e9;
    while(lo<=hi){
        long long mid = (lo+hi)/2;
        long long st = l[1].first;
        bool flag = 1;
        for(long long i=2;i<=N;i++){
            if(st + mid < l[i].first ){
                st = l[i].first;
            }
            else if(st+mid > l[i].first + l[i].second){
                flag = 0;
                break;
            }
            else st = st + mid;
        }
        if(flag) ans = mid, lo = mid+1;
        else hi= mid-1;
    }
    printf("%lld\n", ans);
    return 0;
}
