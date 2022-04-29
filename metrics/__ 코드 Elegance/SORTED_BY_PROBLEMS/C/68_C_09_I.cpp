#include <iostream>
#include <set>
using namespace std;

int number1[300003];
int number2[300003];

int index[100003];

int result[100001];
int resultSize;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<long long> s;

    int n;
    int a;

    cin >> n;

    for(int ni=0;ni<n;ni++){
        cin >> a;
        number1[ni + 0] = a;
        number1[ni + n] = a;
        number1[ni + n + n] = a;
    }

    for(int ni=0;ni<n;ni++){
        cin >> a;
        number2[ni + 0] = a;
        number2[ni + n] = a;
        number2[ni + n + n] = a;
        index[a] = ni + n;
    }



    int success;
    int l1, r1, l2, r2;
    int f;
    for(int ni=0;ni<n;ni++){

        resultSize = 1;
        result[0] = number1[ni];

        l1 = ni - 1 + n;
        r1 = ni + 1 + n;

        l2 = index[number1[ni]] - 1;
        r2 = index[number1[ni]] + 1;

        success = 1;
        for(int nni=0;nni<n-1;nni++){

            f = 0;
            if(number1[l1] == number2[l2] || number1[l1] == number2[r2]){
                f++;
            }
            if(number1[r1] == number2[l2] || number1[r1] == number2[r2]){
                f++;
            }

            if(number1[l1] == number1[r1]){
                result[resultSize++] = number1[l1];
                break;
            }

            if(f == 1){
                if(number1[l1] == number2[l2]){
                    result[resultSize++] = number1[l1];
                    l1--;
                    l2--;
                } else if(number1[l1] == number2[r2]){
                    result[resultSize++] = number1[l1];
                    l1--;
                    r2++;
                } else if(number1[r1] == number2[l2]){
                    result[resultSize++] = number1[r1];
                    r1++;
                    l2--;
                } else {
                    result[resultSize++] = number1[r1];
                    r1++;
                    r2++;
                }
            } else if(f == 2){
                result[resultSize++] = number1[l1];
                result[resultSize++] = number1[r1];
                nni++;
                l1--;r1++;
                l2--;r2++;
            } else {
                success = 0;
                break;
            }

        }

        if(success == 1){
            for(int ii=0;ii<resultSize;ii++){
                cout << result[ii] << " ";
            }
            return 0;
        }

    }

    cout << "-1";

}
