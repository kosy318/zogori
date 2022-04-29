#include <stdio.h>
int T,N,L,A;
int Count[1005][4];
int Into[256];
char DNA[50][1005];
char Undo[5]="ACGT";
int main()
{

	Into['A']=0;
	Into['C']=1;
	Into['G']=2;
	Into['T']=3;

	scanf("%d",&T);

	int t,q,w,most;
	char what;

	for (t=0;t<T;t++)
	{
		A=0;

		scanf("%d %d",&N,&L);
		for (q=0;q<N;q++) scanf("%s",DNA[q]);
		for (q=0;q<L;q++) 
		{
			Count[q][0]=Count[q][1]=Count[q][2]=Count[q][3]=0;
			for (w=0;w<N;w++)
				Count[q][ Into[DNA[w][q]] ]++;
		}

		for (q=0;q<L;q++)
		{
			most=0;
			for (w=0;w<4;w++)
			{
				if (Count[q][w]>most)
				{
					most=Count[q][w];
					what=Undo[w];
				}
			}
			printf("%c",what);
			A+= N-most;
		}
		printf("\n%d\n",A);
	}
	return 0;
}