#include <iostream>

using namespace std;

int main() {
	int test_c;

	cin >> test_c;

	while(test_c--) {
		int x, y, maxx=0, maxy=0, blank=0;
		int points;
		int *xs, *ys;
		int result=0;

		cin >> x >> y >> points;

		xs=new int[points];
		ys=new int[points];

		for(int i=0; i<points; i++)
			cin >> xs[i] >> ys[i];

		int **map;

		map=new int*[x+2];
		for(int i=0; i<x+2; i++)
				map[i]=new int [y+2];

		for(int i=0; i<x+2; i++) {
				for(int j=0; j<y+2; j++) {
					map[i][j]=0;	
				}
		}

		for(int i=0; i<points; i++) {
			map[xs[i]+1][ys[i]+1]=1;
			map[xs[i]][ys[i]]=1;
			map[xs[i]][ys[i]+1]=1;
			map[xs[i]+1][ys[i]]=1;
		}
		for(int i=1; i<x+1; i++) {
				int begin=-1, end=-1;

				for(int j=1; j<y+1; j++) {
						if(map[i][j]==1 && begin==-1)
							begin=j;
						if(map[i][j]==1)
							end=j;
				}

				if(maxy < end-begin+1)
						maxy=end-begin+1;

				while(begin<end)
					map[i][begin++]=1;
		}
		for(int j=1; j<y+1; j++) {
				int begin=-1, end=-1;

				for(int i=1; i<x+1; i++) {
						if(map[i][j]==1 && begin==-1)
							begin=i;
						if(map[i][j]==1)
							end=i;
				}

				if(maxx < end-begin+1)
						maxx=end-begin+1;

				while(begin<end)
					map[begin++][j]=1;
		}

		if(x-maxx < y-maxy)
			blank=x-maxx;
		else
			blank=y-maxy;

		//cout << maxx << " " << maxy << endl;
		//cout << x << " " << y << endl;

		/*for(int i=1; i<x+1; i++) {
				for(int j=1; j<y+1; j++) 
						cout << map[i][j] << " ";
			cout << endl;
		}*/

		for(int i=1; i<x+1; i++) {
				for(int j=1; j<y+1; j++)
						if(map[i][j] == 1)
								result++;
		}

		cout << result+blank << endl;
		for(int i=0; i<x+2; i++)
				delete[] map[i];
		delete[] map;
	}
	return 0;
}
