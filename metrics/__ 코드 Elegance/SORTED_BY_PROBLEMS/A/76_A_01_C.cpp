//
// Created by team076 on 19. 11. 9..
//

#include <stdio.h>
#include <set>
using namespace std;

int main() {
    int n;

    scanf("%d",&n);
    int a[1010] = {1,1};
    for(int i=2;i<=n;i++){
        set<int> s;
        for(int j=1;i>=2*j;j++){
            if(2*a[i-j]-a[i-2*j]>0)
            s.insert(2*a[i-j]-a[i-2*j]);
        }
        int cnt=1;
        bool b=false;
        for(int x:s) {
            if(x>cnt){a[i]=cnt;b=true;break;}
            else cnt++;
        }
        if(!b) {
            a[i]=cnt;
        }
    }
    printf("%d",a[n]);
}