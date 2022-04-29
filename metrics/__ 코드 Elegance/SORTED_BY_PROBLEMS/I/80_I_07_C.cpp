#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#define MAXN 100000
using namespace std;

typedef long long int lli;
struct strt{
    lli x, l;
    bool operator<(const strt& s)const{
        return x < s.x;
    }
    bool operator>(const strt& s)const{
        return x > s.x;
    }
};
lli N, ans;
strt X[MAXN];
bool isPos(lli g){
    lli prex = X[0].x;
    for(int j = 1; j < N; j++){
        if(X[j].x + X[j].l >= prex + g){
            if(prex + g <= X[j].x)
                prex = X[j].x;
            else
                prex = prex + g;
        }else{
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int j = 0; j < N; j++){
        cin >> X[j].x >> X[j].l;
    }
    sort(X, X + N);
    lli l = 0, r = 3000000000LL;
    while(l <= r){
        lli mid = (l + r) >> 1;
        if(isPos(mid)){
            l = mid + 1;
            ans = max(ans, mid);
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}