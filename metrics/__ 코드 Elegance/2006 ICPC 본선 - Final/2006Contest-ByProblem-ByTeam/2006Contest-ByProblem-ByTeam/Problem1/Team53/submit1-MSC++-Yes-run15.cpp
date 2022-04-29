#include<stdio.h>

char a[111];
char b[111];

int x, y, z, xx, yy, zz;
int Cnt;

int Go(int x, int y, int z, int xx, int yy, int zz)
{
	int Cnt = 0;
	int l1, l2, l3;
	int t1, t2, t3;
		t1 = x*10000 + y *100 + z;
		t2 = xx*10000 + yy * 100 + zz;
		for(l1=0;l1<=23;l1++)
		{
			t3 = l1 * 10000;
			if(t3+5959 < t1 || t3 > t2) continue;
		for(l2=0;l2<=59;l2++)
		{
			t3 = l1 * 10000 + l2 * 100;
			if(t3+59 < t1 || t3 > t2) continue;
			for(l3=0;l3<=59;l3++)
			{
				t3 = l1 * 10000 + l2 * 100 + l3;
				if(t3 < t1 || t3 > t2) continue;
				if(t3 % 3 == 0)
				{
					Cnt++;
				}
			}
		}
	}
		return Cnt;
}

int main(void)
{
	int T;
	int l1, l2, l3;
	int t1, t2, t3;

	for(scanf("%d",&T);T>=1;T--)
	{
		Cnt = 0;
		scanf("%s %s",a,b);
		for(l1=0;a[l1];l1++) if(a[l1] == ':') a[l1] = ' ';
		for(l1=0;b[l1];l1++) if(b[l1] == ':') b[l1] = ' ';
		sscanf(a, "%d %d %d",&x,&y,&z);
		sscanf(b, "%d %d %d",&xx,&yy,&zz);
		t1 = x*10000 + y *100 + z;
		t2 = xx*10000 + yy * 100 + zz;
		if(t1 > t2)
		{
			printf("%d\n",Go(0,0,0,xx,yy,zz) + Go(x,y,z,23,59,59));
		}
		else
		{
			printf("%d\n",Go(x,y,z,xx,yy,zz));
		}
	}
}