#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    string str;
    ifstream file(argv[1]);
    int loc = 0;
    while (getline(file, str)){
        loc++;
    }

    cout << loc << endl;
}
