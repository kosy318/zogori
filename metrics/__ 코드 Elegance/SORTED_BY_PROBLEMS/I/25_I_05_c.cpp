#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;

pii arr[100001];
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].first,&arr[i].second);
        arr[i].second += arr[i].first;
    }
    sort(arr,arr+n);
    ll l = 1, r = 2000000000, mid, ans;
    while(l<=r) {
        mid =(l+r)/2;
        ll cur = arr[0].first + mid;
        int i=1;
        ll mx = 20000000000;
        bool suc = true;
        while(!pq.empty()) pq.pop();
        while(i<n || !pq.empty()){
            if(arr[i].first > cur && pq.empty()) {
                mx = min(mx, arr[i].first - cur);
                cur = arr[i].first + mid;
                i++;
                continue;
            }
            else{
                while(i < n && arr[i].first <= cur){
                    pq.push(arr[i].second);
                    i++;
                }
            }
            if(cur <= pq.top()){
                pq.pop();
                cur = cur + mid;
            }
            else{
                suc = false;
                break;
            }
        }
        if(suc){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid -1;
        }
    }
    printf("%d",ans);
}
