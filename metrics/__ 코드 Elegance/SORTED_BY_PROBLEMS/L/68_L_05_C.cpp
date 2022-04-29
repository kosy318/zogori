#include <iostream>
#include <algorithm>
using namespace std;

class MineralWork{
public:
    long long startTime;
    long long endTime;
    long long price;

    bool operator < (const MineralWork &a) const{
        return endTime < a.endTime;
    }
};

long long memo[20001] = {0, };
long long price[201];

MineralWork mineralWork[20000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin>>m>>n;

    for(int mi=1;mi<=m;mi++){
        cin >> price[mi];
    }

    long long a, b, c;
    for(int ni=0;ni<n;ni++){
        cin>>a>>b>>c;
        mineralWork[ni].price = (b - a) * price[c];
        mineralWork[ni].startTime = a;
        mineralWork[ni].endTime = b;
    }

    sort(mineralWork + 0, mineralWork + n);
    int mineralWorkPtr = 0;

    for(int ti=1;ti<=15000;ti++){
        memo[ti] = memo[ti-1];
        while(mineralWorkPtr < n){
            if(mineralWork[mineralWorkPtr].endTime == ti){
                memo[ti] = max(memo[ti], memo[mineralWork[mineralWorkPtr].startTime] + mineralWork[mineralWorkPtr].price);
            } else {
                break;
            }
            mineralWorkPtr++;
        }
    }

    cout << memo[15000];

}
