#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n, M[101]={};
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> M[i];

    vector<pair<pair<int, int>, int>> v;
    int x,y,z;
    for (int i = 0; i < n; i++){
        cin >> x >> y >> z;
        v.push_back(make_pair(make_pair(y,x),z));
    }
    sort(v.begin(), v.end());

    int dp[15001] = {0,};
    for(int i = 1; i < 15001; i++){
        int m = -1;
        for(int j = 0; j < n; j++) {
            if( v[j].first.first == i ){
                m = max(m, dp[v[j].first.second] + (v[j].first.first - v[j].first.second) * M[v[j].second]);
            }
            else if (v[j].first.first > i)
                break;
        }
        dp[i] = max(dp[i - 1] , m);
    }
    cout << dp[15000];

}