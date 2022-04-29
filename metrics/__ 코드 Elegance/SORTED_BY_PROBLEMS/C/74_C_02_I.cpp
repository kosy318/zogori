#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <algorithm>

#define FRONT_FRONT 0
#define FRONT_BACK 1
#define BACK_FRONT 2
#define FONT_BACK 3

using namespace std;

int a[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> dq1;
    deque<int> dq2;


    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        int input;
        cin >> input;
        dq1.push_back(input);
    }

    for(int i=0;i<n;i++) {
        int input;
        cin >> input;
        dq2.push_back(input);
    }

    vector<int> ans;
    while(!dq1.empty()||!dq2.empty()) {
        if(dq1.front() == dq2.front()) {
            ans.push_back(dq1.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        else if(dq1.front() == dq2.back()) {

            ans.push_back(dq1.front());
            dq1.pop_front();
            dq2.pop_back();
        }
        else if (dq1.back() == dq2.front()) {

            ans.push_back(dq1.back());
            dq1.pop_back();
            dq2.pop_front();
        }
        else if (dq1.back() == dq2.back()) {

            ans.push_back(dq1.back());
            dq1.pop_back();
            dq2.pop_back();
        }
        else {
            cout << -1 <<"\n";
            return 0;
        }

    }
    for(int i : ans) {
        cout << i << " ";
    }

    return 0;
}