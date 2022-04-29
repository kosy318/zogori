#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 2000000000
using namespace std;
char Y[55];
char X[5005];
int YL,XL,T;
int D[5005][55];
int P[5005][55];
int LX[55];
int PS(int k)
{
	//k=1;

	int q,w;
	int last=0;
	int a,b,c,d,ly;
	int bb,cc;

	for (w=0;w<YL;w++) LX[w]=-1;

	D[0][0] = ( X[0] != Y[0] );
	if (D[0][0]>k) P[0][0]=0; else {P[0][0]=1;LX[0]=0;}
	if (YL==1 && P[0][0]) last=1;
	for (w=1;w<YL;w++) 
	{
		D[0][w] = w + ( X[0]!=Y[w] );
		if (D[0][w]>k) P[0][w]=0; else {P[0][w]=1;LX[w]=0;}
		if (w==YL-1 && P[0][w]) last=1;
	}
	for (q=1;q<XL;q++)
	{
		ly=-1;
		for (w=0;w<YL;w++)
		{
			if (w==0) 
			{
				D[q][0] = (q-last) + (X[q]!=Y[0]);
				if (D[q][0]>k) P[q][0]=0; else P[q][0]=1;
				if (P[q][0])
				{
					if (w==YL-1) last=q+1;
					LX[0]=q;
				}
			} 
			else 
			{
				//Change
				if (P[q-1][w-1]) a=D[q-1][w-1] + ( X[q]!=Y[w] ); else a=MAX;
				if (P[q-1][w]) b=D[q-1][w] + 1; else b=MAX;
				
				if (P[q][w-1]) c=D[q][w-1] + 1; else c=MAX;

				if (LX[w-1]<0) bb=MAX; else bb=D[ LX[w-1] ][w-1] + (q-LX[w-1]-1) + (X[q]!=Y[w]);
				if (ly<0) cc=MAX; else cc=D[q-1][ly]+(w-ly-1)+ (X[q]!=Y[w]);
				

				d=min( a, min(b,c) );
				d=min( d, min(bb,cc) );
				if (d>k) P[q][w]=0;
				else 
				{
					D[q][w]=d;
					P[q][w]=1;
					if (w==YL-1) last=q+1;
				}
			}
			if (P[q-1][w]) ly=w;
		}
		for (w=0;w<YL;w++)
			if (P[q][w]) LX[q]=w;
	}
	return (last==XL);	
}
int main()
{
	scanf("%d",&T);
	int t,k;
	int min,max,mid;
	for (t=0;t<T;t++)
	{
		scanf("%s",&Y);
		scanf("%s",&X);
		YL=strlen(Y);
		XL=strlen(X);
		min=0;
		max=YL+YL;
		while (min<=max)
		{
			mid=min+max;
			mid/=2;
			if ( PS(mid) ) { k=mid;max=mid-1; }
			else { min=mid+1; }
		}
		printf("%d\n",k);
	}
	return 0;
}