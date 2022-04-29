#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fire[1010]={0,};
int main() {
    int n;
    vector<int> v;
    cin >> n;
    fire[0]=1; fire[1]=1;
    for(int i=2;i<=n;i++){
        int small=1;
        v.clear();
        for(int k=1;i-2*k>=0;k++) {
            v.push_back(2 * fire[i - k] - fire[i - 2 * k]);
        }
        sort(v.begin(),v.end());

        for(int j=0;j<v.size();j++){
            if(small==v[j]) small++;
        }
        fire[i]=small;
    }
    cout<<fire[n]<<endl;
    return 0;
}