#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int max_n = 105;
const int max_time = 15005;
ll minerals[max_n], cache[max_time];
ll s, e, t;
vector<pair<ll,ll> > adj[max_time];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> minerals[i];
    }
    for(int i = 0; i < m; i++){
        cin >> s >> e >> t;
        adj[e].push_back({s, (e-s) * minerals[t-1]});
    }
    for(int i = 1; i < max_time; i++) {
        cache[i] = max(cache[i], cache[i-1]);
        for(pair<ll,ll> &p : adj[i]) {
            cache[i] = max(cache[i], cache[p.first] + p.second);
        }
    }
    cout << cache[max_time - 1];
}
/*
long long  arr1[10001][3], arr2[101], cache[10001];
vector<int> s,e;
int m,n;

long long solve(int i, long long sum){

    if(i == n - 1)return sum;
    int c = 0;
    long long ret = 0;
    for(int j = i+1; j< n;j++){
        c= 0;
        for(int k = 0;k < s.size();k++){
            if((s[k] <= arr1[j][0] && arr1[j][0] < e[k]) ||   (s[k] < arr1[j][1] && arr1[j][1] <= e[k])){
            c = 1;
            break;
            }
        }
        if(c == 1)continue;
        s.push_back(arr1[j][0]);
        e.push_back(arr1[j][1]);
        ret = max(ret,solve(j, sum + arr2[arr1[j][2]-1]*(arr1[j][1] - arr1[j][0])));
        s.pop_back();
        e.pop_back();
    }
    return max(ret,sum);
}

int main(){

    cin >> m >> n;
    for(int i = 0;i<m;i++)cin >> arr2[i];

    for(int i = 0; i<n;i++)cin >> arr1[i][0] >> arr1[i][1] >> arr1[i][2];

    long long ret= 0;
    for(int i = 0;i< n;i++){

        s.push_back(arr1[i][0]);
        e.push_back(arr1[i][1]);
        ret = max(ret,solve(i , arr2[arr1[i][2]-1]*(arr1[i][1] - arr1[i][0])));
        s.pop_back();
        e.pop_back();
    }

    cout << ret ;

}
*/
