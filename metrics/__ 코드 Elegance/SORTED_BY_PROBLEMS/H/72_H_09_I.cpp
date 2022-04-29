#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
pair <int, int> s[1001];
pair <int, int> b[1001];
int n,m,c1,c2;
int yy1,y2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i].first >> s[i].second;
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    cin >> c1 >> c2;

    sort(s,s+n);
    sort(b, b+m);
    int it;
    int scnt = 0, bcnt = 0, ret = 0;
    for(int i = 0; i < n ; i++){
        for(int j = i + 1; j < n; j++){
        yy1 = max(s[i].second,s[j].second);
        y2 = min(s[i].second,s[j].second);
        scnt = bcnt = 0;
        it = lower_bound(s,s+n, s[i]) - s;
        for(int k = it; k < n && s[k].first <= s[j].first; k++){
            if(yy1 >= s[k].second && y2 <= s[k].second) scnt++;
        }
        it = lower_bound(b,b+m, b[i]) - b;
        for(int k = it; k < m && b[k].first <= b[j].first; k++){
            if(yy1 >= b[k].second && y2 <= b[k].second) bcnt++;
        }

        ret = max(ret,(scnt * c1) - (bcnt*c2));
        }
    }
    cout << ret;

    return 0;
}

