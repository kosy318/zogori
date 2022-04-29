#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int k = 0, t = 0;
    int l = 0, r = 3;
    cin >> n;
    while(r < n){
        l = r;
        r <<= 1;
        k += 2;
        if(t) t <<= 1;
        else t = 1;
    }
    if(n <= l + t)
        cout << k - 1;
    else
        cout << k;
}