#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int max_n = 100005;
int N;
vector<pair<int,int> > a;
bool parametric_search(int mid) {
    int dist = -987654321;
    for(int i = 0; i < a.size(); i++) {
        pair<int,int> curr = a[i];
        int s = a[i].first;
        int e = a[i].second;
        if((dist + mid <= s)) {
            dist = s;
        }
        else if(dist + mid > e){
            return false;
        }
        else {
            dist += mid;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
    int s,e;
        cin >> s >> e;
        a.push_back({s, s + e});
    }
    sort(a.begin(), a.end());
    int l = 0, r = 10e9 + 5;
    while(l <= r) {
        int mid = (l + r)/2;
        if(parametric_search(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l - 1;
    return 0;
}
