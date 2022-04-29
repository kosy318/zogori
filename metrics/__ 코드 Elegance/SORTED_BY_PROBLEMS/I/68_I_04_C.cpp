#include <iostream>
#include <algorithm>
using namespace std;

class Line{
public:
    long long start;
    long long end;

    bool operator < (const Line &a) const{
        if(start != a.start){
            return start < a.start;
        } else {
            return end < a.end;
        }
    }
};

Line line[100003];

long long n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >>n;

    for(int ni=0;ni<n;ni++){
        cin >> line[ni].start >> line[ni].end;
        line[ni].end += line[ni].start;
    }

    sort(line+0,line+n);

    long long rangeMin = 1;
    long long rangeMax = 2000000001;
    long long rangeMid;

    long long lastPoint;

    while(1){

        rangeMid = (rangeMin + rangeMax) / 2;

        if(rangeMin == rangeMid){
            break;
        }

        lastPoint = 0;
        for(int ni=0;ni<n;ni++){
            if(lastPoint <= line[ni].end){
                lastPoint = max(lastPoint, line[ni].start) + rangeMid;
            } else {
                lastPoint = -1;
                break;
            }
        }

        if(lastPoint == -1){
            // fail
            rangeMax = rangeMid;
        } else {
            // success
            rangeMin = rangeMid;
        }

    }

    cout << rangeMid;

}
