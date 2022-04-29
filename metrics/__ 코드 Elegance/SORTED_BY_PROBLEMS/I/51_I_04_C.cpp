#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    // DELETE IT PLEASE////////////////////////
    // freopen("1.in", "r", stdin);
    ///////////////////////////////////////////
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int> > vt(n);  // [first, second]
    for(int i=0; i<n; i++) {
        int xx, ll;
        cin >> xx >> ll;
        vt[i].first = xx, vt[i].second = xx + ll;
    }

    sort(vt.begin(), vt.end());

    int left = 0, right = 2e9;
    int answer = 0;
    while(left <= right) {
        int mid = ((long long)left + right) / 2;  // mid: answer
        bool finish = (left == right);

        int x = vt[0].first;
        bool good = true;
        for(int i=1; i<n; i++) {
            if(max(vt[i].first, x + mid) <= vt[i].second) {  // can
                x = max(vt[i].first, x + mid);
            }
            else {
                good = false;
                break;
            }
        }

        if(good) { // to right
            answer = max(answer, mid);
            left = mid + 1;
        }
        else { // to left
            right = mid - 1;
        }

        if(finish) break;
    }

    cout << answer;

    return 0;
}