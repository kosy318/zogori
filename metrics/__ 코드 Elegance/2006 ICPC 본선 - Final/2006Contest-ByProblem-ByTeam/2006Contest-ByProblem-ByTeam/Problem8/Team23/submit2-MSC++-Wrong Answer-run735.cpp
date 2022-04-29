#include<stdio.h>
#include<string.h>

//#define min(a,b) 
//#define min3(a,b,c) 
#define abbs(a) (((a)>0)?(a):(-(a)))

int N,ny,nx;
char y[100];
char x[5002];
int a[5001][51];
int rev[5001][51];
int res1,res2,res3,res4,res5,res6;




int min(int a,int b)
{
	return (((a)>(b))?(b):(a));
}

int min3(int a,int b,int c)
{
	return (min(min((a),(b)),(c)));
}

int dy1(int l, int r)
{
	int temp;
	if(l>r) return 0;
	for(int i=l; i<r; i++)
		a[i][0]=i-l;
	for(int i=0; i<ny; i++)
		a[l][i]=i;
	/////////////////////
	for(int i=l+1; i<r; i++)
		for(int j=1; j<ny; j++)
			a[i][j]=min3(a[i-1][j-1]+((x[i]==y[j])?0:1), a[i-1][j]+1, a[i][j-1]+1);


	/////////////////////////////////////////
	for(int i=l; i<=r; i++)
		rev[i][ny]=r-i;
	for(int i=0; i<=ny; i++)
		rev[r][i]=ny-i;
	
	for(int i=r-1; i>=l; i--)
		for(int j=ny-1; j>=0; j--)
		{
			rev[i][j]=min3(rev[i+1][j+1]+((x[i]==y[j])?0:1), rev[i+1][j]+1, rev[i][j+1]+1);
		}

	temp=a[r-1][ny-1];
	int min=9999999;
	int po=99999;
	for(int i=l; i<r; i++)
		if(a[i][ny-1]+rev[i+1][0]<min)
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		} /*else if(a[i][ny-1]+rev[i+1][0]==min && abbs(po-(r-po)) > abbs(i-(r-i)))
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}*/
	//printf("%d %d %d %d\n",l,r,min,temp);
	if(min>temp)
	{
		if(temp>res1) res1=temp;
		return temp;
	}
	else return dy1(l,po+2)+dy1(po+2,r);
}

int dy2(int l, int r)
{
	int temp;
	if(l>r) return 0;
	for(int i=l; i<r; i++)
		a[i][0]=i-l;
	for(int i=0; i<ny; i++)
		a[l][i]=i;
	/////////////////////
	for(int i=l+1; i<r; i++)
		for(int j=1; j<ny; j++)
			a[i][j]=min3(a[i-1][j-1]+((x[i]==y[j])?0:1), a[i-1][j]+1, a[i][j-1]+1);


	/////////////////////////////////////////
	for(int i=l; i<=r; i++)
		rev[i][ny]=r-i;
	for(int i=0; i<=ny; i++)
		rev[r][i]=ny-i;
	
	for(int i=r-1; i>=l; i--)
		for(int j=ny-1; j>=0; j--)
		{
			rev[i][j]=min3(rev[i+1][j+1]+((x[i]==y[j])?0:1), rev[i+1][j]+1, rev[i][j+1]+1);
		}

	temp=a[r-1][ny-1];
	int min=9999999;
	int po=99999;
	for(int i=l; i<r; i++)
		if(a[i][ny-1]+rev[i+1][0]<min)
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		} /*else if(a[i][ny-1]+rev[i+1][0]==min && abbs(po-(r-po)) > abbs(i-(r-i)))
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}*/
	//printf("%d %d %d %d\n",l,r,min,temp);
	if(min>temp)
	{
		if(temp>res2) res2=temp;
		return temp;
	}
	else return dy2(l,po+1)+dy2(po+1,r);
}

int dy3(int l, int r)
{
	int temp;
	if(l>r) return 0;
	for(int i=l; i<r; i++)
		a[i][0]=i-l;
	for(int i=0; i<ny; i++)
		a[l][i]=i;
	/////////////////////
	for(int i=l+1; i<r; i++)
		for(int j=1; j<ny; j++)
			a[i][j]=min3(a[i-1][j-1]+((x[i]==y[j])?0:1), a[i-1][j]+1, a[i][j-1]+1);


	/////////////////////////////////////////
	for(int i=l; i<=r; i++)
		rev[i][ny]=r-i;
	for(int i=0; i<=ny; i++)
		rev[r][i]=ny-i;
	
	for(int i=r-1; i>=l; i--)
		for(int j=ny-1; j>=0; j--)
		{
			rev[i][j]=min3(rev[i+1][j+1]+((x[i]==y[j])?0:1), rev[i+1][j]+1, rev[i][j+1]+1);
		}

	temp=a[r-1][ny-1];
	int min=9999999;
	int po=99999;
	for(int i=l; i<r; i++)
		if(a[i][ny-1]+rev[i+1][0]<min)
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}else if(a[i][ny-1]+rev[i+1][0]==min && abbs(po-(r-po)) > abbs(i-(r-i)))
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}
	//printf("%d %d %d %d\n",l,r,min,temp);
	if(min>temp)
	{
		if(temp>res3) res3=temp;
		return temp;
	}
	else return dy3(l,po+1)+dy3(po+1,r);
}
int dy4(int l, int r)
{
	int temp;
	if(l>r) return 0;
	for(int i=l; i<r; i++)
		a[i][0]=i-l;
	for(int i=0; i<ny; i++)
		a[l][i]=i;
	/////////////////////
	for(int i=l+1; i<r; i++)
		for(int j=1; j<ny; j++)
			a[i][j]=min3(a[i-1][j-1]+((x[i]==y[j])?0:1), a[i-1][j]+1, a[i][j-1]+1);


	/////////////////////////////////////////
	for(int i=l; i<=r; i++)
		rev[i][ny]=r-i;
	for(int i=0; i<=ny; i++)
		rev[r][i]=ny-i;
	
	for(int i=r-1; i>=l; i--)
		for(int j=ny-1; j>=0; j--)
		{
			rev[i][j]=min3(rev[i+1][j+1]+((x[i]==y[j])?0:1), rev[i+1][j]+1, rev[i][j+1]+1);
		}

	temp=a[r-1][ny-1];
	int min=9999999;
	int po=99999;
	for(int i=l; i<r; i++)
		if(a[i][ny-1]+rev[i+1][0]<min)
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		} else if(a[i][ny-1]+rev[i+1][0]==min && abbs(po-(r-po)) > abbs(i-(r-i)))
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}
	//printf("%d %d %d %d\n",l,r,min,temp);
	if(min>temp)
	{
		if(temp>res4) res4=temp;
		return temp;
	}
	else return dy4(l,po+2)+dy4(po+2,r);
}int dy5(int l, int r)
{
	int temp;
	if(l>r) return 0;
	for(int i=l; i<r; i++)
		a[i][0]=i-l;
	for(int i=0; i<ny; i++)
		a[l][i]=i;
	/////////////////////
	for(int i=l+1; i<r; i++)
		for(int j=1; j<ny; j++)
			a[i][j]=min3(a[i-1][j-1]+((x[i]==y[j])?0:1), a[i-1][j]+1, a[i][j-1]+1);


	/////////////////////////////////////////
	for(int i=l; i<=r; i++)
		rev[i][ny]=r-i;
	for(int i=0; i<=ny; i++)
		rev[r][i]=ny-i;
	
	for(int i=r-1; i>=l; i--)
		for(int j=ny-1; j>=0; j--)
		{
			rev[i][j]=min3(rev[i+1][j+1]+((x[i]==y[j])?0:1), rev[i+1][j]+1, rev[i][j+1]+1);
		}

	temp=a[r-1][ny-1];
	int min=9999999;
	int po=99999;
	for(int i=l; i<r; i++)
		if(a[i][ny-1]+rev[i+1][0]<min)
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}else if(a[i][ny-1]+rev[i+1][0]==min && abbs(po-(r-po)) > abbs(i-(r-i)))
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}
	//printf("%d %d %d %d\n",l,r,min,temp);
	if(min>temp)
	{
		if(temp>res5) res5=temp;
		return temp;
	}
	else return dy5(l,po)+dy5(po,r);
}
int dy6(int l, int r)
{
	int temp;
	if(l>r) return 0;
	for(int i=l; i<r; i++)
		a[i][0]=i-l;
	for(int i=0; i<ny; i++)
		a[l][i]=i;
	/////////////////////
	for(int i=l+1; i<r; i++)
		for(int j=1; j<ny; j++)
			a[i][j]=min3(a[i-1][j-1]+((x[i]==y[j])?0:1), a[i-1][j]+1, a[i][j-1]+1);


	/////////////////////////////////////////
	for(int i=l; i<=r; i++)
		rev[i][ny]=r-i;
	for(int i=0; i<=ny; i++)
		rev[r][i]=ny-i;
	
	for(int i=r-1; i>=l; i--)
		for(int j=ny-1; j>=0; j--)
		{
			rev[i][j]=min3(rev[i+1][j+1]+((x[i]==y[j])?0:1), rev[i+1][j]+1, rev[i][j+1]+1);
		}

	temp=a[r-1][ny-1];
	int min=9999999;
	int po=99999;
	for(int i=l; i<r; i++)
		if(a[i][ny-1]+rev[i+1][0]<min)
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		} else if(a[i][ny-1]+rev[i+1][0]==min && abbs(po-(r-po)) > abbs(i-(r-i)))
		{
			min=a[i][ny-1]+rev[i+1][0];
			po=i;
		}
	//printf("%d %d %d %d\n",l,r,min,temp);
	if(min>temp)
	{
		if(temp>res6) res6=temp;
		return temp;
	}
	else return dy6(l,po)+dy6(po,r);
}
void main()
{

	scanf("%d",&N);

	while(N--)
	{
		res1=-1;
		res2=-1;
		res3=-1;
		res4=-1;
		res5=-1;
		res6=-1;
		scanf("%s",y);
		scanf("%s",x);
		nx=(int)strlen(x);
		ny=(int)strlen(y);
		dy1(0,nx);
		dy2(0,nx);
		dy3(0,nx);
		dy4(0,nx);
		dy5(0,nx);
		dy6(0,nx);
		printf("%d\n",min3(min(res1,res2),min3(res3,res5,res6),res4));
	}
}