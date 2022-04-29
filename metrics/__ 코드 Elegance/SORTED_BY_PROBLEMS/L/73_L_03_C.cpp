#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Data
{
public:
    int s,e,t;
};
bool compare(Data &i, Data&j)
{
    if(i.e==j.e)return i.s<j.s;
    return i.e<j.e;
}
int price[110]={0,};
long long Sum[10001];
Data input[10001];
int main(void) {
    //freopen("input.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>price[i];
    for(int i=1; i<=n; i++)
        cin>>input[i].s>>input[i].e>>input[i].t;
    sort(input,input+n,compare);
    vector<int> last;
    long long ma = -1;
    for(int i=1; i<=n; i++)
    {
        auto t = upper_bound(last.begin(),last.end(),input[i].s);
        int idx = t - last.begin();
        idx = max(0,idx);
        long long cost = (input[i].e - input[i].s) * price[input[i].t];
        long long gain = Sum[idx]+cost;
        if(gain>ma)ma = gain;
        Sum[i] = ma;
        last.push_back(input[i].e);
    }
    cout<<Sum[n];
    return 0;
}