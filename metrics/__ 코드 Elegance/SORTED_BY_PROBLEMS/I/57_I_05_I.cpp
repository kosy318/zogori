#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
deque<pair<int, int>> q;
int main() {
    int n, f, l;
    int min_before=0;
    int before=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> f >> l;
        q.push_back(make_pair(f, f+l));
    }
    sort(q.begin(), q.end());

    int ub = q.at(q.size()-1).second;
    int min = 100000;
    int max_d = (ub-lb)/2;
    int lb = max_d;
    int knots_lc, idx;
    int num_knots;
    while(ub!=lb+1){
        min = 100000;
        knots_lc = q.at(0).first;
        idx = 1;
        num_knots = 1;
        while(idx<=q.size()-1){
            if(knots_lc + max_d< q.at(idx).first){
                if(min>q.at(idx).first-knots_lc) min = q.at(idx).first-knots_lc;
//                cout<< knots_lc<<" "<<q.at(idx).first << endl;
//                cout<< "knots at: " << knots_lc<<endl;
                knots_lc = q.at(idx++).first;
                num_knots++;
            }
            else if(knots_lc + max_d> q.at(idx).second){
                idx++;
            }
            else{
                if(min>max_d) min = max_d;
                knots_lc += max_d;
//                cout<< "knots at: " << knots_lc<<endl;
                idx++;
                num_knots++;
            }
        }
        if(num_knots>=n){
//            if(before==1) {
//                cout << min_before;
//                break;
//            }
            lb = max_d;
            max_d = (ub+lb)/2;
        }
        else if(num_knots<n){
//            if(before==1){
//                cout << min_before;
//                break;
//            }
            ub = max_d;
            max_d = (ub+lb)/2;
        }
//        else{
//                before = 1;
//                min_before = min;
//                lb = max_d;
//                max_d = (ub+lb)/2;
//        }
    }
    cout << lb;

    return 0;
}