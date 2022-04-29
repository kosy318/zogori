#include <iostream>
using namespace std;

#define MAX 1000
#define infi 0xffffff

struct pnt {
	int x;
	int y;
};

int t, n;
pnt p[MAX];
int bong[MAX];
pnt t1, t2;
double temp;

double calc(pnt a, pnt b)
{
	double x1 = a.x;
	double x2 = b.x;
	double y1 = a.y;
	double y2 = b.y;
	
	return y1 - (y2-y1) / (x2-x1) * x1;
}


int main()
{
	int t, n;
	scanf("%d",&t);
	int py;
	double high, min;
	pnt t1, t2;

	for(int i=0; i<t; i++) {
		scanf("%d",&n);
		min = infi;

		for(int j=0; j<n; j++) {
			scanf("%d %d",&p[j].x,&p[j].y);
			if(j) {
				if(p[j].y > py) {
					bong[j] = 1;
				} else if(p[j].y == py) {
					bong[j] = 2;
				} else bong[j] = 0;
			} else bong[j] = 0;
			py = p[j].y;
		}

		
		for(int j=0; j<n; j++) {
			if(bong[j] == 0) continue;
			//cout << "Now Point " << p[j].x << "," << p[j].y << endl;
			high = 0;

			for(int k=0; k<j; k++) {	// Front
				if(bong[k] == 0 || k==0) continue;
				//***if(bong[k] > 0 ) {
					t1 = p[k-1];
					t2 = p[k];
					t1.x -= p[j].x;
					t2.x -= p[j].x;
					temp = calc(t1,t2)-p[j].y; 
					//cout << "temp : " << temp << endl;
					if(temp > 1000) {
						high = infi;
						break;
					} else if(temp > high) high = temp;
				//***} 
			}	 
	
			if(high == infi) break;

			for(int l=j+1; l<n; l++) { // Back
				if(bong[l] == 0 || l>=n-1) continue;
				//***if(bong[k] > 0) {
					t1 = p[l];
					t2 = p[l+1];
					t1.x -= p[j].x;
					t2.x -= p[j].x;
					temp = calc(t1,t2)-p[j].y;
					//cout << "temp : " << temp << endl;
					if(temp > 1000) {
						high = infi;
						break;
					}	else if(temp > high) high = temp;
				//***}
			}
			if(min > high) min = high;

		}// n-for
		
		for(int j=0; j<n; j++) {

			if(bong[j] == 2) {
				double high2 = 0;
				pnt tp1 = p[j-1];
				pnt tp2 = p[j];
				
				while(tp1.x < tp2.x) {
					high2 = 0;
					//cout << "Now : " << tp1.x << " " << tp1.y << endl;

					for(int k=1; k<=j-1; k++) {	// Front
						if(bong[k] == 0) continue;
						t1 = p[k-1];
						t2 = p[k];
						t1.x -= tp1.x;
						t2.x -= tp1.x;
						temp = calc(t1,t2)-tp1.y; 
						//cout << "temp : " << temp << endl;
						if(temp > 1000) {
							high2 = infi;
							break;
						}	
						else if(temp > high2) high2 = temp;
						 
					}		 
					
					if(high2 == infi) break;

					for(int l=j; l<n-1; l++) { // Back
						if(bong[l] == 0) continue;
						t1 = p[l];
						t2 = p[l+1];
						t1.x -= tp1.x;
						t2.x -= tp1.x;
						temp = calc(t1,t2)-tp1.y;
						//cout << "temp : " << temp << endl;
						if(temp > 1000) {
							high2 = infi;
							break;
						}	else if(temp > high2) high2 = temp;
						
					}
					
					if(min > high2) min = high2;
					//cout << "high2 : " << high2 << endl;
						
					tp1.x++;
				} // end of while
					
				//cout << high << " " << high2 << endl;
			}
		//	if(min > high) min = high;
			
		}
		if(min == infi) printf("IMPOSSIBLE\n");
		else printf("%.1f\n",min);
	}

	return 0;
}
