#include <bits/stdc++.h>
using namespace std;
pair<long long,long long> a[100001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        a[i].second+=a[i].first;
    }
    sort(a,a+n);

    long long l=0,r=a[n-1].second;
    while(l<=r){
        long long m=(l+r)/2;
        long long t=a[0].first;
        bool flag=true;
        for(int i=1;i<n;i++){
            if(t+m >a[i].second){
                flag=false;
                break;
            }
            else{
                t=t+m;
            }
            if(t<a[i].first)t=a[i].first;
        }
        if(flag){
            l=m+1;
        }
        else r=m-1;
    }
    cout<<r;
}
