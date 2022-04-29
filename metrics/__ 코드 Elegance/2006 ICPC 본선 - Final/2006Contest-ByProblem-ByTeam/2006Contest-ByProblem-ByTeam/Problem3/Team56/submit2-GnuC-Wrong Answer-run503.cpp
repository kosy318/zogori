#include <stdio.h>
#include <memory.h>
struct ztype
{
	int lmax,lmin;
}ch[50002],cw[50002],ah[50002],aw[50002];
int main()
{
	int i,n,x,y,lmin,lmax,lcount,wmax,hmax,w,h,ncase,cases;
	int h1,h2,w1,w2;
	scanf("%d",&ncase);
	for (cases=0;cases<ncase;cases++)
	{
		scanf("%d %d",&w,&h);
		for (i=0;i<w+2;i++)
		{
			ch[i].lmax=0;
			ch[i].lmin=h+2;
			ah[i].lmax=0;
			ah[i].lmin=h+2;
		}
		for (i=0;i<h+2;i++)
		{
			cw[i].lmax=0;
			cw[i].lmin=w+2;
			aw[i].lmax=0;
			aw[i].lmin=w+2;
		}
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			if (y<ch[x].lmin)
				ch[x].lmin=y;
			if (ch[x].lmin<1) ch[x].lmin=1;
			if (y<ch[x+1].lmin)
				ch[x+1].lmin=y;
			if (ch[x+1].lmin<1) ch[x+1].lmin=1;
			if (y+1>ch[x].lmax)
				ch[x].lmax=y+1;
			if (ch[x].lmax>h) ch[x].lmax=h;
			if (y+1>ch[x+1].lmax)
				ch[x+1].lmax=y+1;
			if (ch[x+1].lmax>h) ch[x+1].lmax=h;
			if (x<cw[y].lmin)
				cw[y].lmin=x;
			if (cw[y].lmin<1) cw[y].lmin=1;
			if (x<cw[y+1].lmin)
				cw[y+1].lmin=x;
			if (cw[y+1].lmin<1) cw[y+1].lmin=1;
			if (x+1>cw[y].lmax)
				cw[y].lmax=x+1;
			if (cw[y].lmax>w) cw[y].lmax=w;
			if (x+1>cw[y+1].lmax)
				cw[y+1].lmax=x+1;
			if (cw[y+1].lmax>w) cw[y].lmax=w;
		}
		/*
		for (i=0;i<=w+1;i++)
			printf("%d %d",ch[i].lmax,ch[i].lmin);
			*/
		i=1;
		while (ch[i].lmax==0 && i<=w)
			i++;
		if (i<=w)
			w1=i;
		ah[i]=ch[i];
		for (i++;i<=w;i++)
		{
			ah[i].lmax=ch[i].lmax;
			if (ah[i].lmax<ah[i-1].lmax)
				ah[i].lmax=ah[i-1].lmax;
			ah[i].lmin=ch[i].lmin;
			if (ah[i].lmin>ah[i-1].lmin)
				ah[i].lmin=ah[i-1].lmin;
		}
		i=w;
		while (ch[i].lmax == 0 && i>0)
			i--;
		if (i>0) w2=i;
		ah[i]=ch[i];
		for (i--;i>0;i--)
		{
			lmax=ch[i].lmax;
			if (lmax<ah[i+1].lmax)
				lmax=ah[i+1].lmax;
			lmin=ch[i].lmin;
			if (lmin>ah[i+1].lmin)
				lmin=ah[i+1].lmin;
			if (lmax<ah[i].lmax)
				ah[i].lmax=lmax;
			if (lmin>ah[i].lmin)
				ah[i].lmin=lmin;
		}
		i=1;
		while (cw[i].lmax == 0 && i<=h)
			i++;
		if (i<=h) h1=i;
		aw[i]=cw[i];
		for (i++;i<=h;i++)
		{
			aw[i].lmax=cw[i].lmax;
			if (aw[i].lmax<aw[i-1].lmax)
				aw[i].lmax=aw[i-1].lmax;
			aw[i].lmin=cw[i].lmin;
			if (aw[i].lmin>aw[i-1].lmin)
				aw[i].lmin=aw[i-1].lmin;
		}
		i=h+1;
		while (cw[i].lmax == 0 && i>0)
			i--;
		if (i>0) h2=i;
		aw[i]=cw[i];
		for (i--;i>0;i--)
		{
			lmax=cw[i].lmax;
			if (lmax<aw[i+1].lmax)
				lmax=aw[i+1].lmax;
			lmin=cw[i].lmin;
			if (lmin>aw[i+1].lmin)
				lmin=aw[i+1].lmin;
			if (lmax<aw[i].lmax)
				aw[i].lmax=lmax;
			if (lmin>aw[i].lmin)
				aw[i].lmin=lmin;
		}
		/*
		for (i=0;i<=w+1;i++)
			printf("%d %d\n",ah[i].lmax,ah[i].lmin);
			*/
		lcount=0;
		for (i=w1;i<=w2;i++)
			if (ah[i].lmax-ah[i].lmin>0)
				lcount+=ah[i].lmax-ah[i].lmin+1;
		//printf("lcountw = %d\n",lcount);
		lcount=0;
		for (i=h1;i<=h2;i++)
			if (aw[i].lmax-aw[i].lmin>0)
				lcount+=aw[i].lmax-aw[i].lmin+1;
		//printf("lcounth = %d\n",lcount);
		hmax=0;
		for (i=w1;i<=w2;i++)
			if (ah[i].lmax-ah[i].lmin>hmax)
				hmax=ah[i].lmax-ah[i].lmin;
		hmax++;
		wmax=0;
		for (i=h1;i<=h2;i++)
			if (aw[i].lmax-aw[i].lmin>wmax)
				wmax=aw[i].lmax-ah[i].lmin;
		wmax++;
		if (h-hmax>w-wmax)
			lmin=w-wmax;
		else
			lmin=h-hmax;
		if (lmin>0) lmin++;
		printf("%d\n",lmin+lcount);
		
	}
	return 0;
}
