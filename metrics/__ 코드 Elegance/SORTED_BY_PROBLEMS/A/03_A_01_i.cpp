#include <iostream>

using  namespace std;

int arr[1001] ={0,};

void solve(int i){
    int idx = 2;
    while(idx!=i){
        int ans = 1;
        int preAns = 0;

        while(1){
            preAns = ans;
            for(int k = 1; idx-2*k>=0; ++k){
                if(ans - arr[idx-k] == arr[idx-k] - arr[idx-2*k]){
                    ans++;
                }
            }
            if(preAns == ans)
                break;
        }

        arr[idx++] = ans;
    }
}


int main(int argc, char* argv[])
{
    arr[0] = 1;
    arr[1] = 1;

    int input;
    cin >> input;

    solve(input+1);
    cout<<arr[input]<<endl;

    return 0;
}
