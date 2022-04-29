
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<2){
        cout<<1<<endl;
        return 0;
    }
    int* A=new int[n+1];
    bool** table=new bool*[n+1];
    A[0]=A[1]=1;
    for(int i=n;i>=0;i--){
        table[i]=new bool[n+1];
        for(int j=n;j>=0;j--){
            table[i][j]=true;
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<n+1;j++){
            if(table[i][j]){
                A[i]=j+1;
                break;
            }
        }

        for(int j=0;j<i;j++){
            if(i*2-j>n){
                continue;
            }
            if(A[i]*2-A[j]>n+1){
                continue;
            }
            if(A[i]*2-A[j]<1){
                continue;
            }
            table[i*2-j][A[i]*2-A[j]-1]=false;
        }
    }
    cout<<A[n]<<endl;
}
/**/















/*
#include <iostream>
using namespace std;

int main()
{
    int m, n, i;
    int result = 0;
    int point[100000];
    int color[100000];

    cin >> m >> n;

    for(i=0;i<n;i++)
        cin >> point[i];
    for(i=0;i<n;i++)
        cin >> color[i];

    if(color[0] != color[1])
        result++;

    for(i=1;i<n;i++)
    {
        if((point[i] - point[i-1]) > (point[i+1] - point[i]))
        {
            if (color[i] != color[i+1])
                result++;
        }
        else
        {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}/**/



























/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


pair<int,int> sub(pair<int,int> a, pair<int,int> b){
    return make_pair(b.first-a.first, b.second-a.second);
}


int OP(pair<int,int> a, pair<int,int> b){
    return a.first*b.second-a.second*b.first;
}


vector<pair<int,int>*> seq(pair<int,int>* points){
    vector<pair<int,int>*> res(3);
    res[0]=new pair<int,int>[4];
    res[0][0]=points[0];
    res[0][1]=points[1];
    res[0][2]=points[2];
    res[0][3]=points[3];
    res[1]=new pair<int,int>[4];
    res[1][0]=points[0];
    res[1][1]=points[1];
    res[1][2]=points[3];
    res[1][3]=points[2];
    res[2]=new pair<int,int>[4];
    res[2][0]=points[0];
    res[2][1]=points[1];
    res[2][2]=points[2];
    res[2][3]=points[3];
    return res;
}


vector<pair<int, bool>> calcSq(pair<int,int>* points){
    vector<pair<int, bool>> res;

    int a, b;
    for(pair<int,int>* sq : seq(points)){
        a=OP(sub(sq[0],sq[1]),sub([sq[1],sq[2]]));
        b=OP(sub(sq[2],sq[3]),sub([sq[3],sq[0]]));
        if(a*b>0){
            res.clear();
            res.push_back(make_pair(abs(a+b),true));
            return res;
        }
        res.push_back(make_pair(abs(a+b),false));
    }
    return res;
}


int main()
{
    vector<pair<int, bool>> aa=calcSq(new pair<int,int>[4]{make_pair(1,2),make_pair(1,-2),make_pair(-1,1),make_pair(-1,-1)});
    cout<<aa.length()<<endl;
    return 0;

    int n;
    cin>>n;

    pair<int, int>* points = new pair<int, int>[n];
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }
}
*/
