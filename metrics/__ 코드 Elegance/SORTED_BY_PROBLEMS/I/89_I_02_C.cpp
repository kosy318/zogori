#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    long long s,e;
};
A arr[100000];
bool cmp(const A& a,const A& b){
    if(a.s==b.s)    return a.e<b.e;
    return a.s<b.s;
}
int check_ans(long long dis){
    long long now=0;
    for(int i=0;i<n;i++){
        if(now<=arr[i].s)   now=arr[i].s;
        else if(now>arr[i].e)   return 0;
        now+=dis;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].s>>arr[i].e;
        arr[i].e+=arr[i].s;
    }
    sort(arr,arr+n,cmp);
    long long f=0,l=2e9,ans=0;
    while(f<=l){
        long long mid=(f+l)/2;
        if(check_ans(mid)){
            ans=mid;
            f=mid+1;
        }
        else l=mid-1;
    }
    cout<<ans;
}
