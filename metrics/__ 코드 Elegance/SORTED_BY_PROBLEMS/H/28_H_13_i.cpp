#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define SIZE 2001
int n,m;

class cls{
public:
    int x,y,label;
};

vector<cls> vec;
bool compare1(cls a, cls b){
    return a.x < b.x ? true : false;
}

bool compare2(cls a, cls b){
    return a.y < b.y ? true : false;
}

int c1,c2;
void input(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cls temp;
        cin>>temp.x>>temp.y;
        temp.label = 1;
        vec.push_back(temp);
    }
    cin >> m;
    for(int i = 0; i<m; i++){
        cls temp;
        cin>>temp.x>>temp.y;
        temp.label = 2;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), compare1);
    cin>>c1>>c2;
}

void solve(){
    long long sums = -~(1<<31) - 1;
    int mins = -~(1<<31) - 1;
    int num1 = 0;
    int num2 = 0;
    int idx = 0;
    for(int i = 0; i<n+m; i++){
        cls temp = vec[i];
        if(temp.label == 1)
            num1++;
        else
            num2++;

        int t = c1 * num1 - c2 * num2;
        if(mins < t){
            mins = t;
            idx = i;
        }
    }
    vector<cls> vec2;
    num1 = 0;
    num2 = 0;
    for(int i = 0; i<=idx; i++){
        cls temp = vec[i];
        if(temp.label == 1)
            num1++;
        else
            num2++;
        vec2.push_back(temp);
    }

    sort(vec2.begin(), vec2.end(), compare2);

    for(int i = 0; i<=idx; i++){
        cls temp = vec2[i];
        if(temp.label == 1)
            num1--;
        else
            num2--;

        int t = c1 * num1 - c2 * num2;
        if(mins < t){
            mins = t;
        }
    }


    cout<<mins<<endl;
}

int main(void){
    input();
    solve();
}

