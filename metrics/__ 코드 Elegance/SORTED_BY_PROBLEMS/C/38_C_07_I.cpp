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
            for(int j=0; j<tmp1.size(); j++){
                if(tmp1[j]==num)
                    idx1 = j;
                if(tmp2[j]==num)
                    idx2 = j;
            }
            //int idx1 = *find(tmp1.begin(), tmp1.end(), num);
            //int idx2 = *find(tmp2.begin(), tmp2.end(), num);
            int left1, left2, right1, right2;
            if (idx1 == 0) {
                left1 = tmp1[tmp1.size()-1];
                right1 = tmp1[idx1+1];
            }
            else if (idx1 == tmp1.size()- 1) {
                left1 =  tmp1[idx1-1];
                right1 = tmp1[0];
            }
            else {
                left1 =tmp1[idx1 - 1];
                right1 = tmp1[idx1 + 1];
            }
            if (idx2 == 0) {
                left2 = tmp2[tmp2.size()-1];
                right2 = tmp2[idx2+1];
            }
            else if (idx2 == tmp2.size() - 1) {
                left2 =  tmp2[idx2-1];
                right2 = tmp2[0];
            }
            else {
                left2 =tmp2[idx2 - 1];
                right2 = tmp2[idx2 + 1];
            }
            if(left1 == left2){
                answer.push_back(num);
                tmp1.erase(tmp1.begin()+idx1, tmp1.begin()+idx1+1);
                tmp2.erase(tmp2.begin()+idx2, tmp2.begin()+idx2+1);
                num = left1;

            }
            else if(left1 == right2)
            {
                answer.push_back(num);
                tmp1.erase(tmp1.begin()+idx1, tmp1.begin()+idx1+1);
                tmp2.erase(tmp2.begin()+idx2, tmp2.begin()+idx2+1);
                num = left1;
            }
            else if(right1 == right2 )
            {
                answer.push_back(num);
                tmp1.erase(tmp1.begin()+idx1);
                tmp2.erase(tmp2.begin()+idx2);
                num = right1;
            }
            else if(right1 == left2)
            {
                answer.push_back(num);
                tmp1.erase(tmp1.begin()+idx1, tmp1.begin()+idx1+1);
                tmp2.erase(tmp2.begin()+idx2, tmp2.begin()+idx2+1);
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
    /*
    map<int , int> m1, m2;
    map<int, int> copym1, copym2;
    vector<int> answer;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<n; j++)
        {
            int num;
            cin >> num;
            if(i == 0)
                //v1.push_back(num);
                copym1[num] = j;
            else
                copym2[num] = j;
        }
    }

    for(map<int,int>::iterator iter = copym1.begin(); iter != copym1.end(); iter++)
    //for(int i=0; i<n; i++)
    {
        m1 = copym1;
        m2 = copym2;

        int num = iter->first;
        int target = m2[num];
        bool find = false;
        bool isnotmatch = false;
        while(!find || isnotmatch) {
            int left1, right1, left2, right2;
            if (m1[num] == 0) {
                left1 = m1.end()->first;
                right1 = ;
            } else if (i == n - 1) {
                left1 = m1.at(i - 1);
                right1 = m1.at(0);
            } else {
                left1 = m1.at(i - 1);
                right1 = m1.at(i + 1);

            }

            if (target == 0) {
                left2 = m2.at(n - 1);
                right2 = m2.at(target + 1);
            } else if (target == n - 1) {
                left2 = m2.at(target - 1);
                right2 = m2.at(0);
            } else {
                left2 = m2.at(target - 1);
                right2 = m2.at(target + 1);
            }
            //map erase num, num = left1
            if(left1 == left2){
                answer.push_back(m1.at(num));
                m1.erase(m1.at(num));
                m2.erase(m2.at(num));
                num = left1;

            }
            else if(left1 == right2)
            {
                answer.push_back(m1.at(num));
                m1.erase(m1.at(num));
                m2.erase(m2.at(num));
                num = left1;
            }
            else if(right1 == right2 )
            {
                answer.push_back(m1.at(num));

                m1.erase(m1.at(num));
                m2.erase(m2.at(num));
                num = right1;
            }
            else if(right1 == left2)
            {
                answer.push_back(m1.at(num));

                m1.erase(m1.at(num));
                m2.erase(m2.at(num));
                num = right1;
            }
            else
            {
                isnotmatch = true;
            }

            if(m1.empty())
            {
                find = true;
            }
        }
        if(find){
            for(int c=0; c<n; c++)
                cout << answer[c] << " ";
            cout << "\n";
            return 0;
        }
        answer.clear();

    }

    cout << -1 << "\n";
    return 0;
}
     */