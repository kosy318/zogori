#include <bits/stdc++.h>

using namespace std;


int n,a,b,c1,c2;

struct point{
    int x, y, cate;
}arr[1005];

bool cmp(point A, point B){
    return A.x < B.x;
}

int rootY[100], Y[3000],sqrtY, rootY2[100],Y2[3000];

int main(){
    map<int,int> appear;
    int appear_cnt = 0;

    cin>>a;
    vector<int> v;

    for(int i=0; i<a; i++){
        cin>>arr[i].x>>arr[i].y;
        arr[i].cate = 1;
        if(appear.find(arr[i].y) == appear.end()){
            appear[arr[i].y] = appear_cnt++;
            v.push_back(arr[i].y);
        }
    }
    cin>>b;
    for(int i=0; i<b; i++){
        cin>>arr[a+i].x>>arr[a+i].y;
        arr[a+i].cate = 2;
        if(appear.find(arr[a+i].y) == appear.end()){
            appear[arr[a+i].y] = appear_cnt++;
            v.push_back(arr[a+i].y);
        }
    }
    cin>>c1>>c2;
    n = a+b;
    sort(arr,arr+n,cmp);
    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++) appear[v[i]] = i;
    for(int i=0; i<n; i++) arr[i].y = appear[arr[i].y];

    int ans = -1000000000;


    sqrtY = sqrt(appear_cnt);
    for(int i=0; i<n; i++){
        fill(Y,Y+3000,0), fill(Y2,Y2+3000,0);
        fill(rootY,rootY+100,0), fill(rootY2,rootY2+100,0);
        if(arr[i].cate == 1) Y[arr[i].y]++, rootY[arr[i].y/sqrtY]++;
        else Y2[arr[i].y]++, rootY2[arr[i].y/sqrtY]++;

        for(int j=i+1; j<n; j++){
            if(arr[j].cate == 1) Y[arr[j].y]++, rootY[arr[j].y/sqrtY]++;
            else Y2[arr[j].y]++, rootY2[arr[j].y/sqrtY]++;
            int a_cnt = 0, b_cnt = 0, low = min(arr[i].y, arr[j].y), high = max(arr[i].y, arr[j].y);

            for(int k = low/sqrtY; k <= high/sqrtY; k++){
                if(k == low/sqrtY || k == high/sqrtY){
                    for(int p = max(low,k*sqrtY); p<=min(high,(k+1)*sqrtY-1); p++){
                        if(arr[p].cate == 1) a_cnt++;
                        else b_cnt++;
                    }
                }
                else{
                    a_cnt += rootY[k];
                    b_cnt += rootY2[k];
                }
            }
            ans = max(ans,c1*a_cnt-c2*b_cnt);
        }
    }
    cout<<ans;

}
