#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> P1, P2;
int n1, n2;
int c1, c2;

int main()
{
//    freopen("input.txt","r",stdin);
    cin>>n1;
    for(int i=0; i<n1; i++)
    {
        long long temp1, temp2;
        cin>>temp1>>temp2;
        P1.push_back(make_pair(temp1, temp2));
    }
    cin>>n2;
    for(int i=0; i<n2; i++)
    {
        long long temp1, temp2;
        cin>>temp1>>temp2;
        P2.push_back(make_pair(temp1, temp2));
    }
    cin>>c1>>c2;
    long long x1, x2, y1, y2;
    int cnt_1=0, cnt_2=0;
    int max_t=-98765432;
    int temp;
    for(int i=0; i<n1; i++)
    {
        for(int j=i+1; j<n1; j++)
        {
            cnt_1=cnt_2=0;
            x2=max(P1[i].first, P1[j].first);
            y2=max(P1[i].second, P1[j].second);
            x1=min(P1[i].first, P1[j].first);
            y1=min(P1[i].second, P1[j].second);
            for(int k=0; k<n1; k++)
            {
                if(x1<=P1[k].first && x2>=P1[k].first && y1<=P1[k].second && y2>=P1[k].second)
                {
                    cnt_1++;
                }
            }
            for(int k=0; k<n2; k++)
            {
                if(x1<=P2[k].first && x2>=P2[k].first && y1<=P2[k].second && y2>=P2[k].second)
                {
                    cnt_2++;
                }
            }
            temp=c1*cnt_1 - c2*cnt_2;
            max_t=max(temp, max_t);
        }
    }
    cout<<max_t<<endl;
}
