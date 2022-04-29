#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> l;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int xi,li;  scanf("%d%d",&xi,&li);
        l.push_back({xi,xi+li});
    }
    sort(l.begin(),l.end());

    int h=0,t=1e9,x,ans;
    while(h<=t){
        x = (h+t)/2;
        //printf("%d ",x);

        int p=l[0].first, flag=0;
        for(int i=1;i<n;i++){
            if(l[i].first <= p+x && p+x <= l[i].second){
                flag=1;
                p += x;
            }
            else if(p+x < l[i].first){
                flag=1;
                p = l[i].first;
            }
            else{
                flag=0;
                break;
            }
        }

        if(flag) {
            h = x + 1;
            ans = x;
        }
        else t = x-1;
    }

    printf("%d",ans);

    return 0;
}