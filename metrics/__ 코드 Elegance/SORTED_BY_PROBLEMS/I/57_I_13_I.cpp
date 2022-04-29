#include <bits/stdc++.h>
using namespace std;
int type[10001], m, n, money, Max, t_s, t_e;
bool during[15000];
deque<pair<pair<int,int>,pair<int,int>>> mine, cpy;

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
    for(int i=1; i<=m; i++) cin>>type[i];

    for(int i=1; i<=n; i++){
        int s, e, t;
        cin>>s>>e>>t;
        mine.push_back(make_pair(make_pair(s,e), make_pair((e-s)*type[t],t)));
    }
    sort(mine.begin(), mine.end());
//    for(int i=0; i<mine.size();i++){
//        cout<<mine[i].first.first<<endl;
//    }
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--) {
            cpy.push_front(mine[j]);
        }
        money=0;
        //    for(int i=0; i<mine.size();i++){
//        cout<<mine[i].first.first<<endl;
//    }
        for(int j=0; j<i; j++){
            cpy.pop_front();
        }
        //cout<<cpy.size()<<endl;
        for(int j=0; j<=15000; j++){
            during[i]=true;
        }
        t_e=0;
        while(!cpy.empty()){
            if(cpy[0].first.first>=t_e){
                t_e=cpy[0].first.second;
                money+=cpy[0].second.first;
                cpy.pop_front();
            }else{
                cpy.pop_front();
            }
//            if(time_check(mine[mine.size()-1].second.first, mine[mine.size()-1].second.second)==true){
//                money+=mine[mine.size()-1].first.first;
//                mine.pop_back();
//            }else{
//                mine.pop_back();
//            }
        }
        //cout<<money<<endl;
        if(Max<money){
            Max=money;

        }
    }

    cout<<Max;

    return 0;
}