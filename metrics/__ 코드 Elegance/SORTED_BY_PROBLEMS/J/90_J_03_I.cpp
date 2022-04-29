#include <iostream>

int main() {
    int N;
    std::cin >> N;
    if(N<=5) N-=3;
    else if(N%2) N=3;
    else N=2;
    std::cout << N;
    return 0;
}