#include <bits/stdc++.h>
using namespace std;

int N;
pair<int,int> l[100004];


bool cmp(pair<int,int>&a, pair<int,int>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        scanf("%d%d", &l[i].first, &l[i].second);
    }
    sort(l+1, l+N+1, cmp);

    int ans = 0;
    int lo = 0, hi = 1e9;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int st = l[1].first;
        bool flag = 1;
        for(int i=2;i<=N;i++){
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
    printf("%d\n", ans);
    return 0;
}
