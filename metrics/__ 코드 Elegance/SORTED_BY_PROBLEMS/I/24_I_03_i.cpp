#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>>v;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a,b; cin>>a>>b;
        v.push_back({a,a+b});
    }
    sort(v.begin(),v.end());
    int left =0, right =1e9+10;
    while(left<=right)
    {
        int mid = (left+right)/2;
        int point =0;
        int cnt=0;
        for(int i=0; i<v.size(); i++)
        {
            if(i == 0){
                cnt++;
                continue;
            }
            else if(point+mid<v[i].first)
            {
                point = v[i].first;
            }
            else if(point+mid>=v[i].first && point+mid<=v[i].second)
            {
                point +=mid;
            }
            else if(point+mid>v[i].second)
            {
                right = mid-1;
                break;
            }
            cnt++;
        }
        if(cnt ==v.size())
            left = mid+1;
    }
    cout<<right;
    return 0;
}

