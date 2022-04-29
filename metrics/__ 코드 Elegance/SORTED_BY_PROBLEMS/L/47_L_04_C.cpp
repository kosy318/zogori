#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, long long>> mine;
int n, m;
int mine_price[101];
long long d[100000];

bool comparator(const pair<pair<int, int>, int> A, const pair<pair<int, int>, int> B)
{
    if(A.first.second>B.first.second)
    {
        return false;
    }
    else if(A.first.second==B.first.second)
    {
        if(A.first.first>B.first.first)
        {
            return false;
        }
        else return true;
    }
    else return true;
}
int main()
{
    int max_n=0;
//    freopen("input.txt","r",stdin);
    cin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        cin>>mine_price[i];
    }
    for(int i=0; i<n; i++)
    {
        int temp1, temp2, type;
        cin>>temp1>>temp2>>type;
        mine.push_back(make_pair(make_pair(temp1, temp2), (temp2-temp1)*mine_price[type]));
    }
    sort(mine.begin(), mine.end(), comparator);
    int first, last;
    for(int i=0; i<n; i++)
    {
        last = mine[i].first.second;
//        cout<<"========"<<first<<" "<<last<<'\n';
        for(int j=first+1;j<last;j++) {
            d[j]=d[first];
//            cout<<j<<" "<<d[j]<<'\n';
//            cout<<"adfasdfasdf"<<'\n';
        }
//        if(mine[i].first.second>max_n) max_n = mine[i].first.second;
        long long tmp=max(d[mine[i].first.first]+mine[i].second, d[mine[i].first.second-1]);
//        cout<<d[mine[i].first.first-1]<<'\n';
        d[mine[i].first.second] = max(d[mine[i].first.second], tmp);


        first = mine[i].first.second;
//        cout<<mine[i].first.second<<" "<<d[mine[i].first.second]<<'\n';

//        cout<<mine[i].first.first<<mine[i].first.second<<mine[i].second<<endl;
    }
    cout<<d[mine[n-1].first.second]<<'\n';
//    for()
}
