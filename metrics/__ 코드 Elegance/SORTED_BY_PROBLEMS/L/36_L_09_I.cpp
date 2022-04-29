#include <bits/stdc++.h>

using namespace std;

struct node {
    int s, e, value;
};

bool comp(node a, node b) {
    if ( a.e == b.e )
        return a.value > b.value;
    return a.e < b.e;
}

int dp[15010];

int main() {
    int m, n;
    cin >> m >> n;
    int type[m+1];
    node arr[n];
    for ( int i = 0; i < m; i++ ) {
        cin >> type[i+1];
    }

    for ( int i = 0; i < n; i++ ) {
        int t;
        cin >> arr[i].s >> arr[i].e >> t;
        arr[i].value = (arr[i].e-arr[i].s) * type[t];
    }

    sort(arr, arr+n, comp);

    int lastTime = arr[n-1].e;
    int idx = 0;
    for(int i = 1; i <= lastTime; ++i){
    	dp[i] = dp[i-1];
        if(i == arr[idx].e){
			dp[i] = max(dp[i],dp[arr[idx].s] + arr[idx].value);
            while(idx+1 < n &&arr[idx].e <= i){
				dp[i] = max(dp[i],dp[arr[idx+1].s] + arr[idx+1].value);
				idx += 1;
            }
        }
      
    }
    cout << dp[lastTime] << endl;;
}
