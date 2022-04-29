#include <iostream>
#include <algorithm>

#define ll long long


using namespace std;


int bisect_right(int* a, ll lo, ll hi, ll x){
    while (lo < hi){
        ll mid = (lo + hi) / 2;

        if (a[mid] > x)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

struct work{
    ll start;
    ll end;
    ll earn;
    ll type;
    bool operator < (struct work other) {
        return (start < other.start);
    }

};

ll bisect_left(struct work* a, ll lo, ll hi, ll x){
    while (lo < hi){
        ll mid = (lo + hi) / 2;

        if (a[mid].start < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

ll solv_s(struct work* ws, ll n, ll idx, ll pr){
//    cout << idx << " (" << pr << ")" << endl;
    if (n == idx) {
//        cout << "break;" << endl;
        return 0;
    }
    ll m = 0;

    for (ll i = idx; i < n; i++) {


        m = max(m, pr + ws[i].earn);


//        cout << i << endl;
        ll nidx = bisect_left(ws, i+1, n, ws[i].end);

//        cout << nidx << "!?" << endl;

        if (ws[i].end <= ws[nidx].start){
            for (ll t = nidx;  t<n ; t++) {
//                cout << t << "!!" << endl;
                m = max(m, solv_s(ws,n, t, pr + ws[i].earn));
//                cout << t << endl;
            }

        }
//        m = max(solv_s(ws, n, i+1, pr + ws[i].earn), m);
    }
//    cout << idx << " (" << pr << ")" <<  " m (" << m << ")" << endl;

    return m;

}

ll solv(struct work* ws, ll n){

    ll m = 0;
    for (ll i = 0; i < n; i++) {
//        cout << "start at " << i;

        m = max(m, ws[i].earn);

        ll nidx = bisect_left(ws, i+1, n, ws[i].end);
        if (ws[i].end <= ws[nidx].start) {
//            cout << " next " << nidx << endl;
            ll t = solv_s(ws, n, nidx, ws[i].earn);
//            cout << "result " << i << " = " << t << endl;

            m = max(t, m);
        }


    }
    return m;
}

int main() {

    //freopen("../input", "rb", stdin);

    ll m, n;


    ll price[100] = {0, };
    struct work works[10000];

    cin >> m >> n;
    for (ll i = 0; i < m; i++) {
        cin >> price[i];
    }

    for (ll i = 0; i < n; i++) {
        ll s,e,t;
        cin >> s >> e >> t;
        works[i].start = s;
        works[i].end = e;
        works[i].earn = price[t-1] * (e-s);
        works[i].type = t;
    }
    sort(works, works + n);
//    for (int j = 0; j < n; j++) {
//        cout <<j <<  ": " << works[j].start << ", " << works[j].end << ", " << works[j].earn << ", " << works[j].type << endl;
//    }

//    cout << bisect_left(works, 0, n-1, 4);

    cout << solv(works, n);





    return 0;
}