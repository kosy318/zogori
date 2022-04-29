#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Vertex {
    int pos;
    int id;

    bool open;
};

bool operator<(const Vertex& a, const Vertex& b) {
    return a.pos < b.pos || (a.pos == b.pos && b.open && !a.open);
}



int main()
{
    int m,n;
    cin >> m >> n;

    long long money[101] = {0,};

    for(int i=0; i<m; i++)
    {
        cin >> money[i+1];
    }

    long long earn[10000];
    Vertex vertices[20000];
    int start, end, type;
    for(int i=0; i<n; i++)
    {
        cin >> start >> end >> type;
        earn[i] = (end - start) * money[type];

        vertices[i * 2].id = i;
        vertices[i * 2].pos = start;
        vertices[i * 2].open = true;

        vertices[i * 2 + 1].id = i;
        vertices[i * 2 + 1].pos = end;
        vertices[i * 2 + 1].open = false;
    }

    sort(vertices, vertices + n * 2);


    long long maxVal = 0;
    for(int i = 0; i < n * 2; i++) {
        if(vertices[i].open)
            earn[vertices[i].id] += maxVal;
        else
            maxVal = max(maxVal, earn[vertices[i].id]);
    }

    cout << maxVal << endl;
    return 0;
}