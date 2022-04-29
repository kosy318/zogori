#include<stdio.h>
#include<malloc.h>

int main()
{
	int T;
	int x, y;
	int hx, hy;
	int hole;
	char **grid;
	int t, i, j;
	int minX=50001, minY=50001, maxX=0, maxY=0;
	int mXind, mYind;
	int firstIndex, lastIndex,  num;
	int fflag, lflag;
	int temp[50001];
	int num1, num2;

	scanf("%d", &T);
	for(t=0; t<T; t++) {
		
		mXind=mYind=0;
		firstIndex = lastIndex=0;
		/*  in */
		scanf("%d %d", &x, &y);
		grid = (char**)calloc(x, sizeof(char));
		for(i=0; i<x; i++) {
			grid[i] = (char*)calloc(y, sizeof(char));
		}
		for(i=0; i<x; i++) {
			for(j=0; j<y; j++) {
				grid[i][j] = '0';
			}
		}

		scanf("%d", &hole);
		for(i=0; i<hole; i++) {
			scanf("%d %d", &hx, &hy);

			if(hx<x && hy<y && hx>=0 && hy>=0)
				grid[hx][hy] = '1';
			if(hx-1<x && hy<y && hx-1>=0 && hy>=0)
				grid[hx-1][hy]='1';
			if(hx<x && hy-1<y && hx>=0 && hy-1>=0)
				grid[hx][hy-1]='1';
			if(hx-1>=0 && hy-1>=0 && hx-1<x && hy-1<x)
				grid[hx-1][hy-1]  = '1';
			
		}


		/* process - fill the around hole */
		
		maxX = maxY=0;
		for(i=0; i<x; i++) {
			fflag = lflag = 0;
			firstIndex = lastIndex=0;
			for(j=0; j<y; j++) {
				if(grid[i][j]=='1' && fflag==0) {
					firstIndex = j;
					fflag = 1;
				}
			}
			for(j=y-1; j>=0; j--) {
				if(grid[i][j]=='1' && lflag==0) { 
					lastIndex = j;
					lflag = 1;
				}
			}
			for(j=firstIndex; j<lastIndex; j++) {
				grid[i][j] = '1';
			}
			if(lastIndex-firstIndex+1 > maxX) {
				maxX = lastIndex-firstIndex+1;
				mXind = i;
			}
		}
		////
		for(j=0; j<y; j++) {
			fflag = lflag = 0;
			firstIndex = lastIndex=0;
			for(i=0; i<x; i++) {
				if(grid[i][j]=='1' && fflag==0) {
					firstIndex = i;
					fflag=1;
				}	
			}
			for(i=x-1; i>=0; i--) {
				if(grid[i][j]=='1' && lflag==0) { 
					lastIndex = i;
					lflag=1;
				}
			}
			for(i=firstIndex; i<lastIndex; i++) {
				grid[i][j] = '1';
			}
			if(lastIndex-firstIndex+1 > maxY) {
				maxY = lastIndex-firstIndex+1;
				mYind = j;
			}
		}
		

		/* process - cut one line  */
				for(j=0; j<y; j++) {
				temp[j] = grid[mXind][j];
				grid[mXind][j] = '1';
			}
		
		maxX = maxY=0;
		for(i=0; i<x; i++) {
			fflag = lflag = 0;
			firstIndex = lastIndex=0;
			for(j=0; j<y; j++) {
				if(grid[i][j]=='1' && fflag==0) {
					firstIndex = j;
					fflag = 1;
				}
			}
			for(j=y-1; j>=0; j--) {
				if(grid[i][j]=='1' && lflag==0) { 
					lastIndex = j;
					lflag = 1;
				}
			}
			for(j=firstIndex; j<lastIndex; j++) {
				grid[i][j] = '1';
			}
			if(lastIndex-firstIndex+1 > maxX) {
				maxX = lastIndex-firstIndex+1;
				mXind = i;
			}
		}
		num1=0;
		for(i=0; i<x; i++) {
			for(j=0; j<y; j++) {
				if(grid[i][j]=='1') {
					num1++;
				}
			}
		}

	
		
			for(j=0; j<y; j++) {
				grid[mXind][j] = temp[j];
			}
			for(i=0; i<x; i++) {
				grid[i][mYind] = '1';
			}	
		for(j=0; j<y; j++) {
			fflag = lflag = 0;
			firstIndex = lastIndex=0;
			for(i=0; i<x; i++) {
				if(grid[i][j]=='1' && fflag==0) {
					firstIndex = i;
					fflag=1;
				}	
			}
			for(i=x-1; i>=0; i--) {
				if(grid[i][j]=='1' && lflag==0) { 
					lastIndex = i;
					lflag=1;
				}
			}
			for(i=firstIndex; i<lastIndex; i++) {
				grid[i][j] = '1';
			}
			if(lastIndex-firstIndex+1 > maxY) {
				maxY = lastIndex-firstIndex+1;
				mYind = j;
			}
		}
		num2=0;
		for(i=0; i<x; i++) {
			for(j=0; j<y; j++) {
				if(grid[i][j]=='1') {
					num2++;
				}
			}
		}

	
		
				/* process - fill the around hole */

		////

	
		if(num1<num2)
			printf("%d\n", num1);
		else
			printf("%d\n", num2);

	}

	return 0;
}
