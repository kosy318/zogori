#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;

int n;
int main(){
    cin>>n;
    if(n == 3)
    {
        cout << 0;
        return 0;
    }
    int i = 4;
    int ans = 1;
    while(n > i)
    {
        ans++;
        i *= 2;
    }
    cout << ans;
    return 0;
}
