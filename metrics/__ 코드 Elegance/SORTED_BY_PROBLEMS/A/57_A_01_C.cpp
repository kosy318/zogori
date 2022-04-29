#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<int> q;

int main() {
    int n, a, not_b, is;
    cin >> n;
    int* ns = new int[n+1];
    ns[0]=1; ns[1]=1;
    for(int i=2;i<=n;i++){
        for(int k=1;k<=i/2;k++){
            a = ns[i-k] - ns[i-2*k];
            not_b = a+ns[i-k];
            if(not_b>0){
                q.insert(not_b);
            }
        }
        is = 1;
        for(set<int>::iterator j=q.begin(); j!=q.end();j++){
            if(is==*j) is++;
            else{
                ns[i] = is;
                break;
            }
            ns[i] = is;
        }
        q.clear();
    }
    cout<<ns[n];

    return 0;
}