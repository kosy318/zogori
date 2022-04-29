#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int x;
    if (n == 3){
        x = 0;
    }
    else if (n == 4){
        x = 1;
    }
    else if (n == 5){
        x = 2;
    }
    else {
        x = 3 + (n-6)/2;
    }
    cout << x << '\n';
}