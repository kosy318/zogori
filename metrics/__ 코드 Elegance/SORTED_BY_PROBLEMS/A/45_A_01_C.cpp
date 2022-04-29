#include <bits/stdc++.h>
using namespace std;
long long a[1001];
priority_queue<long long> q;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    a[0] = 1; a[1]= 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j*2<=i;j++){
            long long t=a[i-j]*2LL-a[i-(2*j)];
                q.push(-t);
        }
        long long ans=1;

        while(!q.empty()){
            long long t=-q.top();
            q.pop();
            if(q.empty())a[i]=ans;
            if(t < ans )continue;
            if(t==ans){
                ans++;
                if(q.empty()){
                    a[i]=ans;
                }
            }
            else{
                a[i]=ans;
                while(!q.empty())q.pop();
            }
        }
    }
    //for(int i=0;i<a[n;i++])
    cout<<a[n]<<'\n';

}
