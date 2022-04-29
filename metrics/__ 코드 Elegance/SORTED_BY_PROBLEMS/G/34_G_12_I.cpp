#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct Seglazy{
    typedef int T1;
    typedef int T2;
    T1 id = INF, initval = INF;
    T2 unused = INF;
    T1 combine(T1 a, T1 b){return min(a,b);}
    T2 combineL(T2 a, T2 b){return min(a,b);}
    void unlazy(int i, int nl, int nr){arr[i] = min(arr[i], lazy[i]);}

    int n; vector<T1> arr; vector<T2> lazy;
    Seglazy(int sz): n{1}{
        while(n < sz) n<<=1;
        arr.resize(2*n, initval), lazy.resize(2*n, unused);
    }
    void propagate(int x, int nl, int nr){
        if(lazy[x] == unused) return;
        if(x < n){
            lazy[x*2] = combineL(lazy[x*2], lazy[x]);
            lazy[x*2+1] = combineL(lazy[x*2+1], lazy[x]);
        }
        unlazy(x, nl, nr);
        lazy[x] = unused;
    }

    void update(int l, int r, T2 val){
        update(l, r, val, 1, 0, n-1);
    }
    void update(int l, int r, T2 val, int x, int nl, int nr){
        propagate(x, nl, nr);
        if(r < nl || nr < l) return;
        if(l <= nl && nr <= r){
            lazy[x] = combineL(lazy[x], val);
            propagate(x, nl, nr);
            return;
        }
        int mid = (nl + nr) / 2;
        update(l, r, val, x*2, nl, mid);
        update(l, r, val, x*2+1, mid+1, nr);
        arr[x] = combine(arr[x*2], arr[x*2+1]);
    }
    T1 query(int l, int r){
        return query(l, r, 1, 0, n-1);
    }
    T1 query(int l, int r, int x, int nl, int nr){
        propagate(x, nl, nr);
        if(r < nl || nr < l) return id;
        if(l <= nl && nr <= r) return arr[x];
        int mid = (nl+nr)/2;
        return combine(query(l, r, x*2, nl, mid), query(l, r, x*2+1, mid+1, nr));
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int C, n; cin>>C>>n;
    vector<int> left(n), cur, color(n), pos(n), A(n), M(n);
    vector<vector<int>> cont;
    for(int i=0; i<n; i++) cin>>pos[i];
    for(int i=0; i<n; i++) cin>>color[i];
    for(int i=0; i<n; i++){
        if(i == 0 || color[i] == color[i-1]) cur.push_back(pos[i]);
        else{
            cont.push_back(cur);
            left[cont.size()] = left[cont.size()-1] + cur.size();
            cur.clear(), cur.push_back(pos[i]);
        }
    }
    cont.push_back(cur);
    left[cont.size()] = left[cont.size()-1] + cur.size();
    for(int i=0; i<cont.size(); i++) A[i] = cont[i].back() - cont[i][0];
    for(int i=1; i<cont.size(); i++) M[i-1] = cont[i][0] - cont[i-1].back();

    Seglazy ST(n);

    if(cont.size() == 1){cout << 1; exit(0);}
    for(int i=0; i<left[1]; i++) ST.update(i, i, 1);
    for(int i=0; i<cont.size()-1; i++){
        for(int j=0; j<cont[i].size(); j++){
            int p = cont[i][j];
            int d = p - cont[i][0];
            int L = lower_bound(cont[i+1].begin(), cont[i+1].end(), left[i+1]+A[i]-d-M[i]) - cont[i+1].begin();
            int R = upper_bound(cont[i+1].begin(), cont[i+1].end(), left[i+1]+A[i]-d+M[i]) - cont[i+1].begin();
            //cout<<i<<j<<' '<<p+A[i]-d<<M[i]<<' '<<L<<R<<endl;
            int val = ST.query(left[i]+j, left[i]+j);
            if(j != cont[i].size()-1) ST.update(left[i]+j+1, left[i]+cont[i].size()-1, val+1);
            if(L < R) ST.update(left[i+1]+L, left[i+1]+R-1, val+1);
            ST.update(left[i]+j+1, left[i]+j+1, val+1);
        }
    }
    int k = cont.size()-1;
    cout << ST.query(left[k], n-1) << endl;

/*
    for(auto V: cont){
        for(int x: V) cout<<x<<' ';
        cout<<endl;
    }
    for(int x: left) cout<<x;cout<<endl;
    for(int i=0; i<n; i++) cout<<ST.query(i,i)<<' ';
*/
}