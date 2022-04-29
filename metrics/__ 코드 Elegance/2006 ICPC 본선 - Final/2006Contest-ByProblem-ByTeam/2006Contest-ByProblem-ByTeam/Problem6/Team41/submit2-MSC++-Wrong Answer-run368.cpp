#include <iostream>
#include <math.h>

using namespace std;

double a[21];
double b[21];
int m;
int n;
double x;
double bang[30][30];


void process()
{
	int testn;
	int tz;
	int i;
	cin >> testn;
	for (tz=0;tz<testn;tz++){
		cin >> n;
		for (i=1;i<=n;i++)
			cin >>a[i]>>b[i];
		cin >> m;
		for (i=1;i<=n;i++){
			bang[i][i]=a[i];
			bang[i][n+1]=-1;
			bang[i][n+2]=-b[i];
		}
		for (i=1;i<=n;i++){
			bang[n+1][i]=1;
		}
		bang[n+1][n+1]=0;
		bang[n+1][n+2]=m;
		double carry;
		for (i=1;i<=n;i++){
			carry=-((double)bang[n+1][i]/(double)bang[i][i]);
			bang[n+1][n+1]+=carry;
			bang[n+1][n+2]+=bang[i][n+2]*carry;
	
		}
		if(bang[n+1][n+1] == 0) cout << "0" << endl;
		else if(abs((bang[n+1][n+2]/bang[n+1][n+1])-(int)((bang[n+1][n+2]/bang[n+1][n+1])))>0.01) cout << "0" << endl;
		else cout << -(bang[n+1][n+2]/bang[n+1][n+1]) << endl;
	}
}

int main()
{
	process();
	return 0;
}