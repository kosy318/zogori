#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
deque<pair<int, int>> q;
int main() {
    int n, f, l;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> f >> l;
        q.push_back(make_pair(f, f+l));
    }
    sort(q.begin(), q.end());

//    int ub = q.at(q.size()-1).second;
    int ub = (q.at(q.size()-1).second - q.at(0).first)/2+1;
    int lb = 1;
//    int max_d = (ub+lb)/2;
//    int lb = (ub-q.at(0).first)/2;
    int max_d = (ub+lb)/2;

    int knots_lc, idx;
    int num_knots;
    while(ub!=lb+1){
        knots_lc = q.at(0).first;
        idx = 1;
        num_knots = 1;
        while(idx<=q.size()-1){
            if(knots_lc + max_d< q.at(idx).first){
                knots_lc = q.at(idx++).first;
                num_knots++;
            }
            else if(knots_lc + max_d> q.at(idx).second){
                idx++;
                num_knots = n-1;
                break;
            }
            else{
                knots_lc += max_d;
                idx++;
                num_knots++;
            }
        }
//        cout<< "max: " << max_d<< ", num_knots: " << num_knots<<endl;
        if(num_knots>=n){
            lb = max_d;
            max_d = (ub+lb)/2;
        }
        else if(num_knots<n){
            ub = max_d;
            max_d = (ub+lb)/2;
        }

    }
    cout << lb;

    return 0;
}