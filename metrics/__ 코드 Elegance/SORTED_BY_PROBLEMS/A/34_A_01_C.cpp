#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> fire(n+2);
    fire[0] = fire[1] = 1;
    for(int i=2; i<=n; i++){
        vector<bool> unused(500, true);
        unused[0] = false;
        for(int k=1; i-2*k>=0; k++){
            int val = fire[i-k]*2 - fire[i-2*k];
            if(val > 0) unused[val] = false;
        }
        auto it = find(unused.begin(), unused.end(), true);
        assert(it != unused.end());
        fire[i] = it - unused.begin();
    }
    cout << fire[n];
}