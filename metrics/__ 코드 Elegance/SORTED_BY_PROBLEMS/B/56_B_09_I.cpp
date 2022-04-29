#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< pair<int,long> > road[100005];
vector< vector<long long> > num[100005];
queue<int> que;
bool check[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        road[a].push_back({b,c});
        road[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++){
        if(road[i].size()==1){
            que.push(i);
            vector<long long> temp;
            temp.push_back(0);
            num[i].push_back(temp);
        }
    }
    while(!que.empty()){
        int now=que.front();
        que.pop();
        if(check[now]){
            continue;
        }
        check[now]=true;
        if(num[now].size()>0){
            for(int j=0;j<num[now].size();j++){
                for(int k=j+1;k<num[now].size();k++){
                    for(auto a:num[now][j]){
                        for(auto b:num[now][k]){
                            ans+=(a+b)*(a+b);
                        }
                    }
                }
            }
        }

        for(int i=0;i<road[now].size();i++){
            if(check[road[now][i].first]){
                continue;
            }
            vector<long long> temp;
            for(int j=0;j<num[now].size();j++){
                for(int k=0;k<num[now][j].size();k++){
                    temp.push_back(num[now][j][k]+road[now][i].second);
                }
            }
            que.push(road[now][i].first);
            num[road[now][i].first].push_back(temp);

        }
    }
    cout<<ans<<"\n";
    return 0;
}
// 4 1 4 1 4 3    1 2 4 1
//6 1 5 1 5 2 1 5 6 1 6 4 3 6 3 2
// 10 1 2 10 10 2 7 3 2 8 3 9 3 9 8 2 7 9 1 6 4 3 4 5 2 3 4 4
