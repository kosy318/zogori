#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long,long long> a[100005];
#define f first
#define s second

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    int i,j;
    for(i=1 ; i<=n ; i++)cin>>a[i].first>>a[i].second;
    for(i=1 ; i<=n ; i++)a[i].second+=a[i].first;
    sort(a+1,a+n+1);
    long long ans=0;
    long long lef=0;
    long long rig=2e9;
    while(rig>=lef){
        long long mid=(lef+rig)/2;
        long long x=a[1].first;
        int isok=1;
        for(i=2 ; i<=n ; i++){
            if(x+mid>a[i].second){
                isok=0;
                break;
            }
            x=max(a[i].first,x+mid);
        }
        if(isok){
            ans=mid;
            lef=mid+1;
        }
        else
            rig=mid-1;
    }
    cout<<ans;
    return 0;

}
