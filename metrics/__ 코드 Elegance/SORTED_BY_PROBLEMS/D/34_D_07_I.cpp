#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> cnt(n);
    for(int i=0; i<n-1; i++){
        while(1){
            int x; cin>>x;
            if(x == 0) break;
            cnt[i]++;
        }
    }
    cout << accumulate(cnt.begin(), cnt.end(), 0) << '\n';
    for(int i=0; i<n; i++) for(int j=0; j<cnt[i]; j++) cout<<i+1<<' '<<j+1<<'\n';
}