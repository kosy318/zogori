#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e,t;
};
A arr[10001];
bool cmp(const A &a,const A &b){
    if(a.e==b.e)    return  a.s<b.s;
    return a.e<b.e;
}
long long dp[15001];
int n,m;
long long money[101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>m>>n;
    for(int i=1;i<=m;i++)   cin>>money[i];
    int Max=0;
    for(int i=0;i<n;i++)    {
        cin>>arr[i].s>>arr[i].e>>arr[i].t;
        Max=max(Max,arr[i].e);
    }
    for(int i=1;i<=Max ;i++)    dp[i]=-1;
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++){
        if(dp[arr[i].s]==-1){
            int j=arr[i].s;
            while(dp[j]==-1){
                j--;
            }
            for(int k=j;k<=arr[i].s;k++){
                dp[k]=dp[j];
            }
        }
        int j=arr[i].s;
        long long temp=dp[j];
        temp+=(arr[i].e-arr[i].s)*money[arr[i].t];
        dp[arr[i].e]=max(dp[arr[i].e],temp);
        if(i!=0)    dp[arr[i].e]=max(dp[arr[i-1].e],dp[arr[i].e]);
    }
    //for(int i=0;i<=Max;i++) cout<<dp[i]<<" ";
    //cout<<"\n";
    cout<<dp[Max];
}
