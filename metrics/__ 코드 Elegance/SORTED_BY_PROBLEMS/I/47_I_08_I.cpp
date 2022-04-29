#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long ans1;
long long ans2;
vector<pair<long long, long long>> v;
long long lastpoint;
long long binary_s_end(long long start, long long last) {
//    cout<<start<<" "<<last<<'\n';
    long long fl = 0;
    long long key = (start+last)/2;
    if(start==last) return key;
//    cout<<key<<'\n';
    long long ko = lastpoint;
    for(long long i=v.size()-2;i>=0;i--) {
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

long long binary_s_start(long long start, long long last) {
//    cout<<start<<" "<<last<<'\n';
    long long fl = 0;
    long long key = (start+last)/2;
    if(start==last) return key;
//    cout<<key<<'\n';
    long long ko = 0;
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
    long long maxn = 0;

//    freopen("input.txt","r",stdin);
    long long num;
    cin>>num;
    long long begin_n, end_n;
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
