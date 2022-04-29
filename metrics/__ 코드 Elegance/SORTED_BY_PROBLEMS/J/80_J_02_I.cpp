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
    cin>>n;
    if(n==3) cout<<0;
    else if(n==4) cout<<1;
    else if(n%2==1) cout<<n/2;
    else cout<<n/2-1;
    return 0;
}