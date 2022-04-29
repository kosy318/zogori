#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool opp(pair<int,int> p1, pair<int,int>p2){
    return p1.first <p2.first;
}

int main(){
    int n, max;
    cin >> n;
    vector<pair<int,int>> p(n);
    vector<int> knot(n,0);
    for(int i=0;i<n;i++)
        cin >> p[i].first>>p[i].second;

    sort(p.begin(),p.end(),opp);
    knot[0]=0;
    knot[n-1] = p[n-1].first + p[n-1].second;

    int i=0, j=0;
    max = p[n-1].first+p[n-1].second;
    for(i=1;i<n-1;i++){
        max /= n - i - 1;
        if (p[i].first - knot[i-1] >= max) { knot[i ] = p[i].first; }
        else if (knot[i - 1] + max >= p[i].first && knot[i - 1] + max <= p[i].first+p[i].second) {
            knot[i] = p[i].first + max;

        }
        else if (knot[i - 1] + max <= p[i].first) { knot[i] = p[i].first+p[i].first; }
        else if (knot[i - 1] + max >= p[i].first+p[i].second) { knot[i] = p[i].first+p[i].second; }
    }


    /*for(int k=i;k<j;k++){
        max /=j-i-1;
        if(p[i-1].first+max>= p[i].first && p[i-1].first+max<=p[i].second) knot[i]=p[i-1].first+max;
        else if(p[i-1].first+max>= p[i].first) knot[i]=p[i].first;
        else if(p[i-1].first+max<=p[i].second) knot[i]=p[i].second;
    }
    cout<<"3333"<<endl;*/
    int sMin=knot[n-1];
    for(int k=0;k<n-1;k++){
        sMin=min(sMin,knot[k+1]-knot[k]);
    }
    cout<<sMin<<endl;
    return 0;
}
