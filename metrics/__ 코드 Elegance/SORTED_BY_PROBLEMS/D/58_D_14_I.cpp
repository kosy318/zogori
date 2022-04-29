#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;
set<int> s[52];

set<pii> total;
int ind[52][1010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        for(int j = 1; ; j++){
            int x; scanf("%d", &x);
            if(x == 0) break;
            total.insert(make_pair(i, x));
            ind[i][x] = j;
            s[i].insert(x);
        }
    }

    vector<pii> ll;
    while(true){
        bool flag = false;
        for(int i = 1; i < n; i++){
            int k = s[i].size();

            if(k < 2) continue;
            for(int val1: s[i]){
                auto it = s[i].upper_bound(val1);
                if(it == s[i].end()) break;
                int val2 = *it;

                /// i - 1
                if(i - 1 >= 1){
                    auto it = s[i - 1].lower_bound(val1);
                    if(!(it == s[i - 1].end() || *it > val2)){
                        continue;
                    }
                }
                /// i + 1
                if(i + 1 < n){
                    auto it = s[i + 1].lower_bound(val1);
                    if(it != s[i + 1].end() && *it <= val2) continue;
                }

                flag = true;
                ll.push_back(make_pair(i, val1));
                ll.push_back(make_pair(i, val2));
            }
        }

        for(int i = 1, j = 2; j < n; i++, j++){
            for(int val1: s[i]){
                auto it = s[j].upper_bound(val1);
                if(it == s[j].end()) break;
                int val2 = *it;

                it = s[i].upper_bound(val1);
                if(it == s[i].end()) continue;
                int val3 = *it;
                if(val3 < val2) continue;

                it = s[j].upper_bound(val2);
                if(it == s[j].end()) continue;
                int val4 = *it;
                if(val4 < val3) continue;

                if(i - 1 >= 1){
                    auto it = s[i - 1].lower_bound(val1);
                    if(it != s[i - 1].end() && *it <= val3) continue;
                }
                if(j + 1 < n){
                    auto it = s[j + 1].lower_bound(val2);
                    if(it != s[j + 1].end() && *it <= val4) continue;
                }
                flag = true;
                ll.push_back(make_pair(i, val1));
                ll.push_back(make_pair(j, val4));
            }
        }
         /// last
        for(int i = 2, j = 1; i < n; i++, j++){
            for(int val1: s[i]){
                auto it = s[j].upper_bound(val1);
                if(it == s[j].end()) break;
                int val2 = *it;

                it = s[i].upper_bound(val1);
                if(it == s[i].end()) continue;
                int val3 = *it;
                if(val3 < val2) continue;

                it = s[j].upper_bound(val2);
                if(it == s[j].end()) continue;
                int val4 = *it;
                if(val4 < val3) continue;

                if(j - 1 >= 1){
                    auto it = s[j - 1].lower_bound(val2);
                    if(it != s[j - 1].end() && *it <= val4) continue;
                }
                if(i + 1 < n){
                    auto it = s[i + 1].lower_bound(val1);
                    if(it != s[i + 1].end() && *it <= val3) continue;
                }
                flag = true;
                ll.push_back(make_pair(j, val1));
                ll.push_back(make_pair(i, val4));
            }
        }

        if(!flag) break;
        for(pii p: ll){
            s[p.first].erase(p.second);
        }
        ll.clear();
    }


    vector<pii> vec;
    for(pii p: total){
        int i = p.first, x = p.second;
        if(s[i].find(x) != s[i].end()) vec.push_back(make_pair(i, ind[i][x]));
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++) printf("%d %d\n", vec[i].first, vec[i].second);
    return 0;
}
