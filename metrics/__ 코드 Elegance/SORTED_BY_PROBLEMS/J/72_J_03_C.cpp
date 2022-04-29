#include <bits/stdc++.h>

using namespace std;

long long a[2222222] = {0,0,0,0,1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 5; i <= n; i++) {
        if(i & 1) {
            a[i] = max(a[(i-1)/2] + 2, a[(i+1)/2] + 2);
        }
        else {
            a[i] = a[i/2] + 2;
        }
    }
    cout << a[n];
    return 0;
}


/*
long long  arr1[10001][3], arr2[101], cache[10001];
vector<int> s,e;
int m,n;

long long solve(int i){

    int c = 0;
    long long ret = 0;
    for(int j = i+1; j< n;j++){
        c= 0;
        for(int k = 0;k < s.size();k+){
            if((s[k] < arr1[j][0] && arr1[j][0] < e[k]) ||   (s[k] < arr1[j][1] && arr1[j][1] < e[k])){
            c = 1;
            break;
            }
        }
        if(c == 1)continue;
        s.push_back(arr1[j][0]);
        e.push_back(arr1[j][1]);
        ret = max(ret,solve(i) + arr2[j]*(arr1[j][1] - arr1[j][0]));
        s.pop_back();
        e.pop_back();
    }
    return ret;
}

int main(){

    cin >> m >> n;
    for(int i = 0;i<m;i++)cin >> arr2[i];

    for(int i = 0; i<n;i++)cin >> arr1[i][0] >> arr1[i][1] >> arr1[i][2];

    long long ret= 0;
    for(int i = 0;i<n;i++){
        s.push_back(arr1[i][0]);
        e.push_back(arr1[i][1]);
        ret = max(ret,solve(i) + arr2[i]*(arr1[i][1] - arr1[i][0]));
        s.pop_back();
        e.pop_back();
    }

    cout << ret ;

}

*/
