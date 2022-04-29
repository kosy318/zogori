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
    int k = 0;
    int l = 0, r = 3;
    cin >> n;
    while(r < n){
        l = r;
        r <<= 1;
        k += 2;
    }
    if(n == l + 1)
        cout << k - 1;
    else
        cout << k;
}