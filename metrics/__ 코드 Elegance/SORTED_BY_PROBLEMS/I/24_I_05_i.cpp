#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<long long,long long>>v;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin>>n;
    for(long long i=0; i<n; i++)
    {
        long long a,b; cin>>a>>b;
        v.push_back({a,a+b});
    }
    sort(v.begin(),v.end());
    long long left =0, right =1e9+10;
    while(left<=right)
    {
        long long mid = (left+right)/2;
        long long point =0;
        long long cnt=0;
        for(long long i=0; i<v.size(); i++)
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

