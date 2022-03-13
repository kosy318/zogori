#include <iostream>

using namespace std;
int testcase;
int fenceNumber;
int fence[200000];


int divide(int start, int last){
    if(start == last){
        return fence[start];
    }
    else{
        int center = (start+last)/2;
        int leftArea = divide(start,center);
        int rightArea = divide(center+1,last);
        ///////////////////////////////////
        int centerArea;
        int centerMin;
        int centerNumber;
        centerMin = min(fence[center],fence[center+1]);
        centerNumber = 2;
        int leftcursor = center;
        int rightcursor = center+1;
        centerArea = centerNumber * centerMin;
        while(leftcursor-1 >= start || rightcursor+1 <= last){
            if(leftcursor-1 >= start && rightcursor+1 <= last){
                if(fence[leftcursor-1] >= fence[rightcursor+1]){
                    leftcursor--;
                    centerNumber++;
                    centerMin = min(centerMin, fence[leftcursor]);
                }
                else{
                    rightcursor++;
                    centerNumber++;
                    centerMin = min(centerMin,fence[rightcursor] );
                }
            }

            else if(leftcursor-1 >= start){
                leftcursor--;
                centerNumber++;
                centerMin = min(centerMin, fence[leftcursor]);
            }
            else{
                rightcursor++;
                centerNumber++;
                centerMin = min(centerMin,fence[rightcursor]);
            }
            centerArea = max(centerArea, centerNumber * centerMin);
        }
        return max(leftArea,max(rightArea,centerArea));
    }
}
int main()
{
    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        cin >> fenceNumber;
        for(int j = 0; j < fenceNumber; j++){
            cin >> fence[j];
        }
        cout << divide(0,fenceNumber-1) << endl;

    }
    return 0;
}
