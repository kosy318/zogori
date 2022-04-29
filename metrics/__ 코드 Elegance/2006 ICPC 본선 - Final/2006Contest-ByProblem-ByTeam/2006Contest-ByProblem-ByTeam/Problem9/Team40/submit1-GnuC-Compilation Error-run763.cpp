#include <iostream>
#include <vector>

using namespace std;
typedef sturct Point{
		int x, y;
};
int main(){
	int ts, n, sx, sy;
	double h, min=10001;
	cin >> ts;
	while(ts--){
		cin >> n;
		Point p[n];
		for(int i=0; i<n; i++){
				cin >> p[i].x >> p[i].y;
		}
		for(int i=0; i<n; i++){
				sx = p[i].x;
				sy = p[i].y;
				for(int j=0; j<n; j++){
						h = (((p[j+1].y - p[j].y)/(p[i+1].x - p[i].x))*sx - p[i+1].x) + p[i+1].y;
						h = h - sy;
						if(h < min)
								min = h;

				}
		}
		if( min == 10001)
				cout << "IMPOSSIBLE" << endl;
		else
				cout << h << endl;
	}
}
