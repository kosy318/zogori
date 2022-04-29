#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

int n;
class Thread{
public:
    int s, e;

    Thread(int _s, int _e){
        s=_s;
        e=_e;
    };
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<Thread> threads;
    int x, l;
    for(int i = 0; i < n; i++){
        cin >> x >> l;
        threads.push_back(Thread(x, x+l));
    }

    sort(threads.begin(), threads.end(), [](Thread& l, Thread &r){return l.s < r.s;});

    ll left = 0, rigth = 2000000000+5;
    while (rigth - left > 1){
        ll mid = (left + rigth)/2;

        bool success = true;

        ll last = -4000000000;
        for(auto t : threads){
            if(last + mid < t.s)
                last = t.s;
            else if (last + mid <= t.e)
                last += mid;
            else{
                success = false;
                break;
            }
        }

        if(success)
            left = mid;
        else
            rigth = mid;
    }
    cout << left << '\n';
}