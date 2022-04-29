#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ans1;
int ans2;
vector<pair<int, int>> v;
int lastpoint;
int binary_s_end(int start, int last) {
//    cout<<start<<" "<<last<<'\n';
    int fl = 0;
    int key = (start+last)/2;
    if(start==last) return key;
//    cout<<key<<'\n';
    int ko = lastpoint;
    for(int i=v.size()-2;i>=0;i--) {
//        cout<<ko-key<<" "<<v[i].first<<" "<<v[i].second<<'\n';
        if(ko-key >= v[i].first && ko-key <= v[i].second) {
            fl=2;
            ko = ko-key;
//            ko = v[i].second;
        } else if(ko-key>v[i].second){
            fl=1;
            break;
        } else {
            fl=0;
            break;
        }
    }
    if(fl==2) {
        ans1 = key;
//        cout<<"ans1: "<<ans1<<'\n';
    }
//    cout<<"done"<<'\n';
    if(fl==1 || fl==2) {
        binary_s_end(key+1, last);
    } else {
        binary_s_end(start, key);
    }
}

int binary_s_start(int start, int last) {
//    cout<<start<<" "<<last<<'\n';
    int fl = 0;
    int key = (start+last)/2;
    if(start==last) return key;
//    cout<<key<<'\n';
    int ko = 0;
    for(int i=1;i<v.size();i++) {
//        cout<<ko+key<<" "<<v[i].first<<" "<<v[i].second<<'\n';
        if(ko+key >= v[i].first && ko+key <= v[i].second) {
            fl=2;
            ko = ko+key;
//            ko = v[i].second;
        } else if(ko+key<v[i].first){
            fl=1;
            break;
        } else {
            fl=0;
            break;
        }
    }
    if(fl==2) {
        ans2=key;
//        cout<<"ans2: "<<ans2<<'\n';
    }
//    cout<<"done"<<'\n';
    if(fl==1 || fl==2) {
        binary_s_start(key+1, last);
    } else {
        binary_s_start(start, key);
    }
}
int main()
{
    int maxn = 0;

//    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    int begin_n, end_n;
    for(int i=0;i<num;i++) {
        cin>>begin_n>>end_n;
        if(begin_n+end_n>maxn) maxn = begin_n+end_n;
        v.push_back(make_pair(begin_n, begin_n+end_n));
    }
    sort(v.begin(), v.end());

//    for(int i=0;i<num;i++) {
//        cout<<v[i].first<<" "<<v[i].second<<'\n';
//    }
    lastpoint = maxn;

    binary_s_end(0, lastpoint);
    binary_s_start(0, lastpoint);
    cout<<max(ans1, ans2)<<'\n';

    return 0;
}
