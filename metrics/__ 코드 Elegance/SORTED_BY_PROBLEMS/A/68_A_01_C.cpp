#include <iostream>
using namespace std;

int memo[2001] = {0, };
int visit[2001] = {0, };

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int i, j, k;

    int a, b, c;

    memo[0] = 1;
    memo[1] = 1;

    for(i=2;i<=n;i++){

        for(k=1;;k++){
            if(i - k - k < 0){
                break;
            }
            a = memo[i - k - k];
            b = memo[i - k];
            c = b + b - a;

            if(c > 0){
                visit[c] = i;
            }
        }

        for(j=1;;j++){
            if(visit[j] != i){
                memo[i] = j;
                break;
            }
        }

    }

    cout << memo[n];

}
