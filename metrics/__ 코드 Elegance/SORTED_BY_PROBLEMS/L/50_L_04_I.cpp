#include <iostream>
#include <algorithm>
using namespace std;

struct info{int s,e,w;};
info _tmp[10001];
int mineral[101];
int n,m, ans,_max;
int max_end;

bool cmp(const info &a, const info &b){
    if(a.s < b.s) return true;
    else if(a.s == b.s){
        if(a.e < b.e){
            return true;
        }
        else return false;
    }
    else return false;
}

void go(int nn, int start){
    if(start > max_end){
        return;
    }
    else{
        for(int i = nn;i<=n;i++){
            if(_tmp[i].s < start) continue;
            ans += _tmp[i].w;
            if(_max < ans){
                _max = ans;
            }
            go(i+1,_tmp[i].e);
            ans -= _tmp[i].w;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        cin >> mineral[i];
    }
    for(int i=1;i<=n;i++){
        int s,e,t;
        cin >> s>>e>>t;
        max_end = max_end < e ? e : max_end;
        _tmp[i]={s,e,(e-s)*mineral[t]};
    }

    sort(_tmp,_tmp+n,cmp);

    for(int i=1;i<=n;i++){
        ans = _tmp[i].w;
        if(_max < ans){
            _max = ans;
        }
        go(i+1,_tmp[i].e);
        ans = 0;
    }

    cout << _max;

    return 0;
}
