#include <iostream>
#include <vector>

using namespace std;

#define MAXV 1010
#define MAXDEGREE 1010

#define QUEUESIZE 1024

#define MAXINT 0x7FFFFFFF

int roads[1010][1010];
int roadsAfter[1010][1010];

#define NORMAL		1
#define TARGET		2
#define TOLL		3

int main()
{
	int nTest;
	int nCities;
	int nRoads, nTolls;
	int x, y;
	int i, j, k;
	int t1, t2, t3, t4;		// target !!!

	cin >> nTest;

	while(nTest > 0) {
		
		cin >> nCities;
		cin >> nRoads;

		memset(roads, 0, sizeof(roads));
		memset(roadsAfter, 0, sizeof(roadsAfter));

		for(i=1; i<=nRoads; ++i) {
			cin >> x;
			cin >> y;

			roads[x][y] = NORMAL;
			roads[y][x] = NORMAL;
		}

		cin >> t1;
		cin >> t2;

		roads[t1][t2] = TARGET;
		roads[t2][t1] = TARGET;

		cin >> t3;
		cin >> t4;

		roads[t3][t4] = TARGET;
		roads[t4][t3] = TARGET;

		cin >> nTolls;

		for(i=0; i<nTolls; ++i) {
			cin >> x;
			cin >> y;

			roads[x][y] = TOLL;
			roads[y][x] = TOLL;
		}

		vector<int> connected;

		for(i=1; i<=nCities; ++i) {
	
			for(j=1; j<=nRoads; ++j) {
			//	if(roads[i][j] == NORMAL || roads[i][j] == TARGET)
				if(roads[i][j] == NORMAL)
					connected.push_back(j);
			}

		//	cout << "connected list size : " << connected.size() << endl;
			
			memcpy(roadsAfter, roads, sizeof(roads));

			if(connected.size() == 0)
				;
			else if(connected.size() == 1)
				;
			else if(connected.size() == 2) {
				roadsAfter[connected[0]][connected[1]] = NORMAL;
				roadsAfter[connected[1]][connected[0]] = NORMAL;
			}
			else {
				for(j=0; j<=connected.size()-2; ++j) {
				
					for(k=j+1; k<=connected.size()-1; ++k) {

					//	cout << "try to : " << j << ", " << k << endl;

						roadsAfter[connected[j]][connected[k]] = NORMAL;
						roadsAfter[connected[k]][connected[j]] = NORMAL;
					}
				}
			}

			connected.clear();
		}

		
		/*
		for(i=1; i<=nCities; ++i) {
			for(j=1; j<=nCities; ++j) {
				cout << roadsAfter[i][j] << " ";
			}

			cout << endl;
		}
		*/

		if (t1 == t3) {
			if(roadsAfter[t2][t4] == NORMAL) {
				cout << "YES" << endl;
				--nTest;
				continue;
			}
			else  {
				cout << "NO" << endl;
				--nTest;
				continue;
			}
		}
		else if (t1 == t4) {
			if(roadsAfter[t2][t3] == NORMAL) {
				cout << "YES" << endl;
				--nTest;
				continue;
			}
			else {
				cout << "NO" << endl;
				--nTest;
				continue;
			}
				
		}
		else if (t2 == t3) {
			if(roadsAfter[t1][t4] == NORMAL) {
				cout << "YES" << endl;
				--nTest;
				continue;
			}
			else {
				cout << "NO" << endl;
				--nTest;
				continue;
			}
		}
		else if (t2 == t4) {
			if(roadsAfter[t1][t3] == NORMAL) {
				cout << "YES" << endl;
				--nTest;
				continue;
			}
			else {
				cout << "NO" << endl;
				--nTest;			
				continue;
			}
		}
		else if( (roadsAfter[t1][t3] == NORMAL && roadsAfter[t2][t4] == NORMAL) || (roadsAfter[t2][t3] == NORMAL && roadsAfter[t1][t4] == NORMAL) ) {
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

		--nTest;
	}

	return 0;
}


/*
3
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6
5 6
3 5
2 4
1
6 5
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6
5 6
2 3
3 5
1
4 2
5 4
1 2
2 3
3 4
4 5
1 2
4 5
2
2 3
3 4


3
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6
5 6
3 5
2 4
1
6 5
0 1 1 1 1 1
1 0 1 1 1 1
1 1 0 1 1 1
1 1 1 0 1 1
1 1 1 1 0 1
1 1 1 1 1 0
YES
6 8
2 1
1 3
4 5
2 4
5 3
2 3
3 6
5 6
2 3
3 5
1
4 2
0 1 1 1 1 1
1 0 1 1 1 1
1 1 0 1 1 1
1 1 1 0 1 1
1 1 1 1 0 1
1 1 1 1 1 0
YES
5 4
1 2
2 3
3 4
4 5
1 2
4 5
2
2 3
3 4
0 2 0 0 0
2 0 3 0 0
0 3 0 3 0
0 0 3 0 2
0 0 0 2 0
NO
Press any key to continue
*/