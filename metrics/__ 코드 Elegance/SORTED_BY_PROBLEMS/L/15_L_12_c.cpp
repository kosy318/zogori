#include <bits/stdc++.h>
using namespace std;

struct nn{
    int s, e;
    int v;
};
nn n[10005];
int dp[10005];
int ldp[10005];

int bound(int s, int e, int v)
{
    int ans=0;
    while(s <= e) {
        int mid = (s+e)/2;
        if(ldp[mid]<=v) {
            ans = mid;
            s = mid+1;
        }
        else e=mid-1;
    }
    return ans;
}
int main() {
    int M, N;
    int V[105];

    cin>> M>>N;
    for(int i = 1 ; i <= M; i++) cin>>V[i];
    for(int i = 1; i <= N; i++) {
        cin>>n[i].s>>n[i].e>>n[i].v;
        n[i].v = (n[i].e-n[i].s) * V[n[i].v];
    }
    sort(n+1, n+N+1, [](const nn& a, const nn& b){
        return a.e != b.e?a.e<b.e:a.s<b.s;
    });

    for(int i = 1; i <= N; i++){
        int w = bound(0, i-1, n[i].s);
        if(dp[i-1] < dp[w] + n[i].v){
            dp[i] = dp[w] + n[i].v;
            ldp[i] = n[i].e;
        }
        else {
            dp[i] = dp[i-1];
            ldp[i] = ldp[i-1];
        }
    }
    cout<<dp[N];
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> pv;
int dp[10005];
int ldp[10005];
int V[10005];
int bound(int s, int e, int v)
{
    int ans=0;
    while(s < e) {
        int mid = (s+e)/2;
        if(ldp[mid]<=v) {
            ans = mid;
            e = mid-1;
        }
        else s=mid+1;
    }
    return ans;
}
int main() {
    int M, N;
    int T[105];

    cin>> M>>N;
    pv.resize(N+1);
    for(int i = 1 ; i <= M; i++) cin>>T[i];
    for(int i = 1; i <= N; i++) {
        int t;
        cin>>pv[i].first>>pv[i].second>>t;
        V[i]=T[t]*(pv[i].second-pv[i].first);
    }
    sort(pv.begin(),pv.end());
    for(int i = 1; i <= N; i++){
        int w = bound(0,i-1,pv[i].first);
        cout<<w<<'\n';
        if(dp[i-1] < dp[w] + V[i]){
            dp[i] = dp[w] + V[i];
            ldp[i] = pv[i].second;
        }
        else {
            dp[i] = dp[i-1];
            ldp[i] = ldp[i-1];
        }
    }
    cout<<dp[N];
    return 0;
}*/