#include <iostream>
using namespace std;
#define MAX 50000

int xmin[MAX], xmax[MAX], ymin[MAX], ymax[MAX];
int width, height;

void init();
void check(int x, int y);
void disp();
bool isChecked(int x, int y);
int num();
int getblank();

int main() {
	int testcase;
	int holes;
	int x, y;

	cin >> testcase;

	for(int i=0; i<testcase; i++) {
		init();
		cin >> width >> height >> holes;

		for(int j=0; j< holes; j++) {
			cin >> x >> y;
			check(x, y);
		}
		cout << num()+getblank() << endl;
	}
	return 0;
}
void init() {
	for(int i=0; i<MAX; i++) {
		xmin[i] = ymin[i] = MAX;
		xmax[i] = ymax[i] = 0;
	}
}

void checkp(int x, int y) {
	if(xmin[y] > x)
		xmin[y] = x;
	if(xmax[y] < x)
		xmax[y] = x;
	if(ymin[x] > y)
		ymin[x] = y;
	if(ymax[x] < y)
		ymax[x] = y;
	if(xmin[y]<0)
		xmin[y] = 0;
	if(ymin[x]<0)
		ymin[x] = 0;
	if(xmax[y] >= width)
		xmax[y] = width -1;
	if(ymax[x] >= height)
		ymax[x] = height-1;
}

void check(int x, int y) {
	checkp(x-1, y-1);
	checkp(x-1, y);
	checkp(x, y-1);
	checkp(x, y);
}

void disp() {
	int cnt=0;
	for(int i=height; i>=0; i--) {
		for(int j=0; j<=width; j++) {
			if(isChecked(i,j)) {
				cout << "V";
				cnt++;
			}
			else
				cout << "-";
		}
		cout << endl;
	}
	cout << cnt << endl;
}

bool isChecked(int x, int y) {
	if(xmin[y] <= x && xmax[y] >= x)
		return true;
	return false;
}

int num() {
	int cnt=0;
	for(int i=0; i<width; i++)
		if(xmax[i]>xmin[i]){
			//printf("%d  %d  %d\n",xmax[i], xmin[i], xmax[i]-xmin[i]+1);
			cnt += xmax[i]-xmin[i]+1;
		}

	return cnt;
}

int getblank() {
	int min = MAX;
	for(int i=0; i<width; i++)
		if(xmax[i]>=xmin[i]) {
			if(width-(xmax[i]-xmin[i]+1) < min)
				min = width-(xmax[i]-xmin[i]+1);
		}
	for(int i=0; i<height; i++)
		if(ymax[i]>=ymin[i]) {
			if(height-(ymax[i]-ymin[i]+1) < min)
				min = height-(ymax[i]-ymin[i]+1);
		}

	return min;
}