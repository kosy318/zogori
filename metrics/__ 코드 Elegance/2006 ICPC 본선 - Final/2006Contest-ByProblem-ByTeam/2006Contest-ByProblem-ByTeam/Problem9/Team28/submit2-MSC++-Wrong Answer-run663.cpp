#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>

using namespace std;


void main()
{
	int t,n,i,j;
	float xy[2][1000]; //x,y
	float maxhight[1000],a,b,temp,min;

	cin >> t;

	while(t--){
		memset(xy,0,sizeof(xy));
		memset(maxhight,0,sizeof(maxhight));

		cin >> n;
		cin >> xy[0][0] >> xy[1][0];
		for(i=1 ; i<n ; i++) 
		{
			cin >> xy[0][i] >> xy[1][i];
			if(xy[1][i]==xy[1][i-1]){
				temp = (xy[0][i-1]+xy[0][i])/2.0;
				//xy[0][i-1] = ceil((double)temp);
				//xy[0][i] = floor((double)temp);
				xy[0][i-1] = temp;
				xy[0][i] = temp;
			}
			
		}

		for(i=0 ; i<n-1 ; i++){
			a = (xy[1][i] - xy[1][i+1])/(xy[0][i] - xy[0][i+1]);
			b = xy[1][i] - ( a*xy[0][i]);

			for(j=0 ; j<n ; j++){
				temp = a*xy[0][j] + b;
				if(temp > maxhight[j]) maxhight[j] = temp;
			}
		}
		min = 10000000000;
		for(i=0 ; i<n ; i++){
			
			maxhight[i] = maxhight[i]- xy[1][i]; 
			if(min > maxhight[i]) min = maxhight[i];
		}
		if(min >1000) cout << "IMPOSSIBLE" << endl;
		else printf("%.1f\n",min);
	}
}


