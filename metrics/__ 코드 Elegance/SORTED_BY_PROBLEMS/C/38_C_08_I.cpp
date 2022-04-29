#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v1, v2;

    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            int num;
            cin >> num;
            if(i==0)
                v1.push_back(num);
            else
                v2.push_back(num);
        }
    }

    for(int i = 0; i<n; i++){
        vector<int> tmp1, tmp2;
        vector<int> answer;
        for(int j=0; j<n; j++)
        {
            tmp1.push_back(v1[j]);
            tmp2.push_back(v2[j]);
        }

        int num = tmp1[i];

        bool f = false;
        bool isnotmatch = true;
        while(!f && isnotmatch) {
            int idx1, idx2;
            vector<int>::iterator iter1 = find(tmp1.begin(), tmp1.end(), num);
            vector<int>::iterator iter2 = find(tmp2.begin(), tmp2.end(), num);
            /*
            for(int j=0; j<tmp1.size(); j++){
                if(tmp1[j]==num)
                    idx1 = j;
                if(tmp2[j]==num)
                    idx2 = j;
            }
             */
            //int idx1 = *find(tmp1.begin(), tmp1.end(), num);
            //int idx2 = *find(tmp2.begin(), tmp2.end(), num);
            int left1, left2, right1, right2;
            if (iter1== tmp1.begin()) {
                left1 = tmp1[tmp1.size()-1];
                right1 = *(iter1+1);
            }
            else if (iter1== tmp1.end()) {
                left1 =  *(iter1-1);
                right1 = tmp1[0];
            }
            else {
                left1 = *(iter1-1);
                right1 = *(iter1+1);
            }
            if (iter2 == tmp2.begin()) {
                left2 = tmp2[tmp2.size()-1];
                right2 = *(iter2+1);
            }
            else if (iter2 == tmp2.end()) {
                left2 =  *(iter2-1);
                right2 = tmp2[0];
            }
            else {
                left2 =*(iter2-1);
                right2 = *(iter2+1);
            }
            if(left1 == left2 || left1 == right2){
                answer.push_back(num);
                tmp1.erase(iter1);
                tmp2.erase(iter2);
                num = left1;

            }
            else if(right1 == right2 || right1 == left2)
            {
                answer.push_back(num);
                tmp1.erase(iter1);
                tmp2.erase(iter2);
                num = right1;
            }

            else
            {
                isnotmatch = false;
            }

            if(tmp1.size() == 1)
            {
                answer.push_back(tmp1[0]);
                f = true;
            }
        }
        if(f)
        {
            for(int c=0; c<n; c++){
                cout << answer[c] << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;


}
