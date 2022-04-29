#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int n;
        cin >> n;
    }
    int prev, cnt =0;
    cin >> prev;
    for(int i=1; i<m; ++i){
        int n;
        cin >> n;
        if(n!=prev){
            cnt++;
        }
        prev=n;
    }
    cout << cnt+1;
}
