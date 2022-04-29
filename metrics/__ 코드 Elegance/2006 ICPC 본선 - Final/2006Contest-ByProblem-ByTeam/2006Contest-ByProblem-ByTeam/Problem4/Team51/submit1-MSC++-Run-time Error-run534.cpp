#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <queue>

//#include <fstream>
//fstream fin("D.in");
//#define cin fin

struct XY {
	int x;
	int y;
	bool isdislike;
};

struct G {
	vector<int> e;
};

vector<XY>edge;
vector<XY>dislike;
XY faA, faB;
int N, M, F;

void process()
{
	int sv, ev;
	for (int i = 0; i < edge.size(); ++i) {
		for (int k = 0; k < dislike.size(); ++k) {
			if (edge[i].x == dislike[k].x && edge[i].y == dislike[k].y) {
				edge[i].isdislike = true;
			}
		}
	}
	
	vector<G> graph;
	graph.clear();
	G tempG;
	tempG.e.clear();
	int c = 0;

	for (int i = 0; i < edge.size(); ++i) {
		if (edge[i].isdislike == true)
			continue;
		graph.push_back(tempG);
		if (edge[i].x == faA.x && edge[i].y == faA.y) {
			sv = c;
		}
		if (edge[i].x == faB.x && edge[i].y == faB.y) {
			ev = c;
		}
		for (int j = 0; j < edge.size(); ++j) {
			if (i != j  && edge[j].isdislike == false) {
				if (edge[i].x == edge[j].x || edge[i].x == edge[j].y ||
					edge[i].y == edge[j].x || edge[i].y == edge[j].y )
					graph[c].e.push_back(j);
			}
		}
		c++; 
	}

	queue<int> q;
	int v;
	bool discovered[10000] = {0,};
	q.push(sv);
	discovered[sv] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		if (v == ev) {
			cout << "YES\n";
			return;
		}
		for (int k  = 0; k < graph[v].e.size(); ++k) {
			if (discovered[graph[v].e[k]] == false) {
				q.push(graph[v].e[k]);
				discovered[graph[v].e[k]] = true;
			}
		}
	}
	cout << "NO\n";
}

int main()
{
	XY tempXY;
	int nCase;
	cin >> nCase;

	for (int i = 0; i < nCase; ++i) {
		cin >> N >> M;
		edge.clear();
		dislike.clear();

		for (int j = 0; j < M; ++j) {
			cin >> tempXY.x >> tempXY.y;
			tempXY.isdislike = false;

			if (tempXY.x > tempXY.y)
				swap(tempXY.x, tempXY.y);
			edge.push_back(tempXY);
		}

		cin >> faA.x >> faA.y;
		if (faA.x > faA.y)
			swap(faA.x, faA.y);
		cin >> faB.x >> faB.y;
		if (faB.x > faB.y)
			swap(faB.x, faB.y);

		cin >> F;
		for (int k = 0 ; k < F; ++k) {
			cin >> tempXY.x >> tempXY.y;
			if (tempXY.x > tempXY.y)
				swap(tempXY.x, tempXY.y);
			dislike.push_back(tempXY);
		}
		process();		
	}
	return 0;
}
