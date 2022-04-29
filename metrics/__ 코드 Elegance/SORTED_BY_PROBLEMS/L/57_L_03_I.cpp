#include <bits/stdc++.h>
using namespace std;
int type[10001], m, n, money;
bool during[15000];
deque<pair<pair<int,int>,pair<int,int>>> mine;

bool time_check(int s, int e){
    int count=0;
    for(int i=s; i<=e; i++){
        if(during[i]==false){
            count++;
        }
        if(count>1)
            return false;
    }
    for(int i=s; i<=e; i++){
        during[i]=false;
    }
    return true;
}

int main() {
    cin>>m>>n;
    for(int i=0; i<=15000; i++){
        during[i]=true;
    }
    for(int i=1; i<=m; i++) cin>>type[i];

    for(int i=1; i<=n; i++){
        int s, e, t;
        cin>>s>>e>>t;
        mine.push_back(make_pair(make_pair((e-s)*type[t],t),make_pair(s,e)));
    }
    sort(mine.begin(), mine.end());
//    for(int i=0; i<mine.size();i++){
//        cout<<mine[i].first.first<<endl;
//    }

    while(!mine.empty()){
        if(time_check(mine[mine.size()-1].second.first, mine[mine.size()-1].second.second)==true){
            money+=mine[mine.size()-1].first.first;
            mine.pop_back();
        }else{
            mine.pop_back();
        }
    }

    cout<<money;

    return 0;
}