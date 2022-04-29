#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

int n;
int a[1005]={1,1,2,1,1,2,2,4,8};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 3; i <= 1000; i++){
        vector<int> pos(1001,1);
        for(int k = 1; i-2*k >= 0; k++){
            int val1 = a[i-k];
            int val2 = a[i-2*k];
            if(val1*2-val2 >= 0)
                pos[val1*2-val2] = 0;
        }
        int j = 1;
        for(; j < 1000; j++){
            if(pos[j]){ a[i] = j; break;}
        }
//        if(i < 100) cout << i << ' ' << a[i] << '\n';
    }
    cin >> n;
    cout << a[n];


}