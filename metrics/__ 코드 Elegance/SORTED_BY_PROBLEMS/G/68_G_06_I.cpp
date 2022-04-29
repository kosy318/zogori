#include <iostream>
#include <algorithm>
using namespace std;

class Point{
public:
    int x;
    int color;
};

Point point[100001];

int m, n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>m>>n;

    if(n == 1){
        cout << "1";
        return 0;
    }

    int a, b;
    for(int ni=0;ni<n;ni++){
        cin>>a;
        point[ni].x = a;
    }
    for(int ni=0;ni<n;ni++){
        cin>>a;
        point[ni].color = a;
    }

    if(n == 2){
        if(point[0].color != point[1].color){
            cout << "2";
            return 0;
        } else {
            cout << "1";
            return 0;
        }
    }



    int result = 0;

    int lastColor = point[0].color;
    int colorDone = 1;
    if(point[0].color != point[1].color){
        result = 1;
        colorDone = 1;
    } else {
        result = 0;
        colorDone = 0;
    }

    int minLength;
    int success;

    for(int ni=1;ni<n - 1;ni++){ // except last
        if(point[ni].color != lastColor){
            if(colorDone == 0){
                result++;
            }
            colorDone = 0;
        }
        minLength = min(point[ni].x - point[ni-1].x, point[ni+1].x - point[ni].x);
        success = 0;
        if(minLength == point[ni].x - point[ni-1].x){
            if(point[ni].color == point[ni-1].color){
                success = 1;
            }
        }
        if(minLength == point[ni+1].x - point[ni].x){
            if(point[ni].color == point[ni+1].color){
                success = 1;
            }
        }
        if(success == 1){
            // nothing
        } else {
            result++;
            colorDone = 1;
        }
        lastColor = point[ni].color;
    }

    if(point[n-2].color != point[n-1].color){
        if(colorDone == 0){
            result++;
        }
        result++;
    } else {
        if(colorDone == 0){
            result++;
        }
    }

    cout << result << '\n';

}
