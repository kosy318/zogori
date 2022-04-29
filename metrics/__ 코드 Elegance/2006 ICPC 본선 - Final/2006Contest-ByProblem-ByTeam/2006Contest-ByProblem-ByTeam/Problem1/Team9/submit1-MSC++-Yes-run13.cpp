#include<stdio.h>

int start_h,start_m,start_s;
int end_h,end_m,end_s;

bool Is_Count()
{
	int sum=start_h*1000 + start_m*100 + start_s;

	if(sum%3==0) return true;
	return false;
}
int main(void)
{
	//freopen("input.txt","r",stdin);

	int tn;
	scanf("%d",&tn);

	while(tn--)
	{
		scanf("%d:%d:%d %d:%d:%d",&start_h,&start_m,&start_s,&end_h,&end_m,&end_s);
		
		int r=0;

		
		while(1)
		{
			bool flag=Is_Count();

			if(flag)
			{
				r++;
			}

			if(start_h==end_h && start_m==end_m && start_s==end_s)
			{
				break;
			}

			start_s++;
			if(start_s==60)
			{
				start_s=0;
				start_m++;
			}
			if(start_m==60)
			{
				start_m=0;
				start_h++;
			}
			if(start_h==24)
			{
				start_h=0;
			}
		}
		printf("%d\n",r);
	
	}
	
	return 0;
}