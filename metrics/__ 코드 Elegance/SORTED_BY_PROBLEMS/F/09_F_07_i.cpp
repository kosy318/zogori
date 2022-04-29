
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


pair<int,int> sub(pair<int,int> a, pair<int,int> b){
    return make_pair(b.first-a.first, b.second-a.second);
}


long long int OP(pair<int,int> a, pair<int,int> b){
    return ((long long int)a.first)*b.second-((long long int)a.second)*b.first;
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
    res[2][1]=points[2];
    res[2][2]=points[1];
    res[2][3]=points[3];
    return res;
}


vector<long long int> calcSq(pair<int,int>* points){
    vector<long long int> res;

    long long int a, b, c, d;
    for(pair<int,int>* sq : seq(points)){
        a=OP(sub(sq[0],sq[1]),sub(sq[1],sq[2]));
        b=OP(sub(sq[2],sq[3]),sub(sq[3],sq[0]));
        c=OP(sub(sq[1],sq[2]),sub(sq[2],sq[3]));
        d=OP(sub(sq[3],sq[0]),sub(sq[0],sq[1]));
        if(a*b>0&&c*d>0){
            res.clear();
            res.push_back((long long int)abs(a)+(long long int)abs(b));
            return res;
        }
        res.push_back(abs(a+b));
    }
    return res;
}


int main()
{
    int n;
    cin>>n;

    pair<int, int>* points = new pair<int, int>[n];
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }

    vector<long long int> aa;
    int res = 0;
    int mins = 0;
    long long int minarr = 8000000000000000009;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    aa=calcSq(new pair<int,int>[4]{ points[i],points[j],points[k],points[l]});
                    if(aa.size()==1){
                        res+=2;
                    }
                    else{
                        res+=3;
                    }
                    for(long long int& area : aa){
                        if(area==minarr){
                            mins++;
                        }
                        else if(area<minarr){
                            mins=1;
                            minarr=area;
                        }
                    }
                }
            }
        }
    }

    cout<<res+mins*2<<endl;

    return 0;
}
/**/
