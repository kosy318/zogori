#include <bits/stdc++.h>

using namespace std;

struct line {
    int s, e;
};

bool cmp(line a, line b) {
    return a.s < b.s;
}

int main() {
    int n;
    cin >> n;
    line arr[n];
    vector<int> result;
    for ( int i = 0; i < n; i++ ) {
        int s, d;
        cin >> s >> d;
        arr[i].s = s;
        arr[i].e = s+d;
    }
    sort(arr, arr+n, cmp);
    int location = arr[0].s;
    int dest = arr[n-1].e;

    for ( int i = 0; i < n-1; i++ ) {
        double avg = (dest - location) / (double)(n-i-1);
        if ( arr[i+1].s - location >= avg ) {
            result.push_back(arr[i+1].s - location);
            location = arr[i+1].s;
        } else if ( arr[i+1].e >= location + avg ) {
            result.push_back((int)avg);
            location += avg;
        } else {
            result.push_back(arr[i+1].e - location);
            location = arr[i+1].e;
        }
    }

    int m = 2e9;
    for ( int i = 0; i < result.size(); i++ )
        m = min(m, result[i]);
    cout << m << endl;
}
